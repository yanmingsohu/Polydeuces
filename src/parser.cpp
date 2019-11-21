#include "parser.h"
#include "tool.h"
#include <string>
#include <iostream>
#include <vector>
#include <memory>

namespace PolydeucesEngine {


class ParseData {
private:
  std::vector<Word> words;
  // 不负责 code 的内存管理
  CharSequence code;
  int begin;
  int error_count;

public:
  const int length;

public:
  ParseData(CharSequence _code, int bufferLength)
  : code(_code), length(bufferLength), begin(0)
  , error_count(0) {
  }

  char operator[](int i) {
    return code[i];
  }

  void pushWord(int endpos, WordType t, JSLexer l) {
    if (endpos <= begin) return;
    //std::cout << begin << ',' << endpos << std::endl;
    words.push_back({code + begin, endpos - begin, t, l});
  }

  void pushCheckWord(int endpos) {
    WordType t = WordType::Non;
    JSLexer l = JSLexer::Unknow;
    CharSequence buf = code + begin;
    int len = endpos - begin;

    //TODO: 符号/数字
    if (parser_key_word(buf, len, l)) {
      pushWord(endpos, WordType::KeyWord, l);
    }
    else if (parse_number(buf, len, t)) {
      pushWord(endpos, t, JSLexer::Unknow);
    }
    else if (parse_symbol(buf, len, t)) {
      pushWord(endpos, t, JSLexer::Unknow);
    } 
    else {
      pushError(endpos);
    }
  }

  void pushError(int i) {
    pushWord(i, WordType::SyntaxError, JSLexer::Unknow);
    update(i + 1);
    ++error_count;
  }

  int errorCount() {
    return error_count;
  }

  void update(int last_pos) {
    begin = last_pos;
  }

  void print() {
    for (auto i = words.begin(); i != words.end(); ++i) {
      std::cout << std::string(reinterpret_cast<char*>(i->begin), i->length)
                << '\t' << i->length << '\t';
#define WTType(x) case x : std::cout << #x; break
      switch (i->type) {
        WTType(KeyWord);
        WTType(String);
        WTType(Operator);
        WTType(Comment);
        WTType(Symbol);
        WTType(Decimal);
        WTType(HexInt);
        WTType(OctalInt1);
        WTType(OctalInt2);
        WTType(BinaryInt);
        WTType(BigDecimal);
        WTType(BigHexInt);
        WTType(BigOctalInt);
        WTType(BigBinaryInt);
        WTType(SyntaxError);
        default: std::cout << "N(" << i->type << ")"; break;
      }
#undef WTType
      std::cout << ' ';
      print_lexer(i->lexer, std::cout);
      std::cout << std::endl;
    }
  }

  CharSequence code_ref() {
    return code;
  }
}; 


void parse_javascript(std::ifstream& code_stm) {
  code_stm.seekg(0, std::ios_base::end);
  std::ifstream::streampos filesize = code_stm.tellg();
  code_stm.seekg(0, std::ios_base::beg);

  // 输入流处理了不同平台的换行问题
  std::unique_ptr<unsigned char[]> code_buf(new unsigned char[filesize]);
  std::streambuf* raw_buffer = code_stm.rdbuf();
  auto realsize = raw_buffer->sgetn(reinterpret_cast<char*>(code_buf.get()), filesize);

  parse_javascript(code_buf.get(), realsize);
}


void parse_javascript(CharSequence code, const int length) {
  ParseData pd(code, length);
  parse_lexer(pd);
  pd.print();
}


static void SingleLineComment(ParseData& pd, int& i) {
  while (i < pd.length) {
    if (pd[i] == '\r' || pd[i] == '\n') {
      break;
    }
    ++i;
  }
  pd.pushWord(i, WordType::Comment, JSLexer::Unknow);
  pd.update(i+1);
}


static void MultiLineComment(ParseData& pd, int& i) {
  while (i < pd.length) {
    if (pd[i] == '*' && pd[i + 1] == '/') {
      i += 2;
      break;
    }
    ++i;
  }
  pd.pushWord(i, WordType::Comment, JSLexer::Unknow);
  pd.update(i);
}


static void NormString(ParseData& pd, int& i, char endCh) {
  while (i < pd.length) {
    if (pd[i] == '\\' && pd[i - 1] == endCh) {
      i += 2;
      continue;
    }
    if (pd[i] == '\r' || pd[i] == '\n') {
      pd.pushError(i);
      return;
    }
    if (pd[i] == endCh) {
      break;
    }
    ++i;
  }
  pd.pushWord(i, WordType::String, JSLexer::Unknow);
  pd.update(i+1);
}


void parse_lexer(ParseData& pd) {
  int skip_brace = 0;
  enum {
    ChCtrl, ChBlank, ChChar,
  } state = ChBlank;

  for (int i = 0; i < pd.length; ++i) {
    switch (pd[i]) {
      case '\n':
      case ' ':
      case '\t':
        if (state == ChChar) {
          pd.pushCheckWord(i);
        } 
        // no break;
      case '\r':
        pd.update(i+1);
        state = ChBlank;
        break;

      case '/':
        pd.pushCheckWord(i);
        pd.update(i);
        state = ChBlank;
        if (pd[i + 1] == '/') {
          SingleLineComment(pd, i+=2);
        }
        else if (pd[i + 1] == '*') {
          MultiLineComment(pd, i+=2);
        }
        else {
          pd.pushWord(i + 1, WordType::Operator, JSLexer::Divide);
          pd.update(i + 1);
        }
        break;

      case '\'':
        pd.pushCheckWord(i);
        ++i;
        pd.update(i);
        state = ChBlank;
        NormString(pd, i, '\'');
        break;

      case '"':
        pd.pushCheckWord(i);
        ++i;
        pd.update(i);
        state = ChBlank;
        NormString(pd, i, '"');
        break;

      case '`': //TODO: 完整支持多行字符串
        pd.pushCheckWord(i);
        ++i;
        pd.update(i);
        state = ChBlank;
        NormString(pd, i, '`');
        break;

      case '.':
        if (i+1 < pd.length && isDigital(pd[i + 1])) {
          break;
        }
        goto default_check;

      case '-':
      case '+':
        if (i + 1 < pd.length && pd[i-1] == 'e' && isDigital(pd[i + 1])) {
          break;
        }
        goto default_check;

      case '{':
        if (pd[i - 2] == '\\' && pd[i - 1] == 'u') {
          ++skip_brace;
          break;
        }
        goto default_check;

      case '}':
        if (skip_brace--) break;
        goto default_check;

default_check: // 具有两种功能的符号, 在处理完特殊功能后跳转到这里.
      default:
        JSLexer lexer;
        int offset = parser_operator(pd.code_ref() + i, pd.length - i, lexer);
        if (offset) {
          pd.pushCheckWord(i);
          pd.update(i);
          pd.pushWord(i + offset, WordType::Operator, lexer);
          pd.update(i + offset);
          state = ChBlank;
          continue;
        }
        
        if (pd[i] >= 33 && pd[i] < 127) {
          state = ChChar;
        } 
        else {
          state = ChCtrl;
        }
        break;
    }
  }
  pd.pushCheckWord(pd.length);
}


int parse_number(CharSequence str, int length, WordType& t) {
  bool big = false;
  bool dot = false;
  bool e = false;

  enum {
    ParseNumInit, DecOrPrifix, DecE,
    MustDec, MustHex, MustOctal2, MustOctal1, MustBinary,
  } state = ParseNumInit;

  for (int i = 0; i < length; ++i) {
    switch (str[i]) {
      case '0':
        if (state == ParseNumInit) {
          state = DecOrPrifix;
          break;
        }
      case '1':
        if (state == MustBinary) break;
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
        if (state == MustOctal1 || state == MustOctal2) break;
        if (state == DecOrPrifix) {
          state = MustOctal1;
          break;
        }

      case '8':
      case '9':
        if (state == ParseNumInit || state == DecOrPrifix) {
          state = MustDec;
          break;
        }
        if (state == MustOctal1) {
          state = MustDec;
          break;
        }
        if (state == MustDec) break;
        if (state == DecE) {
          state = MustDec;
          break;
        }

      case 'b':
      case 'B':
        if (state == DecOrPrifix) {
          if (length < 3) return 0;
          state = MustBinary;
          break;
        }
      case 'a':
      case 'A':
      case 'c':
      case 'D':
      case 'f':
      case 'F':
        if (state != MustHex) {
          return 0;
        }
        break;

      case 'e':
      case 'E':
        if (state == MustDec) {
          if (e) return 0;
          e = true;
          if (i + 2 < length && (str[i + 1] == '+' || str[i + 1] == '-')) {
            i += 1;
          }
          state = DecE;
          break;
        }
        if (state != MustHex) {
          return 0;
        }
        break;

      case '_':
        if (state == ParseNumInit || state == DecOrPrifix) {
          return 0;
        }
        if (str[i-1] == '.') return 0;
        if (i+1 < length && str[i+1] == '.') return 0;
        continue;

      case 'n':
        if (state == MustOctal1) {
          return 0;
        }
        if (i == length - 1) {
          big = true;
          break;
        }
        return 0;

      case '.':
        if (dot) return 0;
        dot = true;
        if (state == ParseNumInit || state == DecOrPrifix) {
          state = MustDec;
          break;
        }
        if (state != MustDec) {
          return 0;
        }
        break;

      case 'x':
      case 'X':
        if (state == DecOrPrifix) {
          if (length < 3) return 0;
          state = MustHex;
          break;
        }
        return 0;

      case 'o':
      case 'O':
        if (state == DecOrPrifix) {
          if (length < 3) return 0;
          state = MustOctal2;
          break;
        }
        return 0;

      default:
        return 0;
    }
  }

  switch (state) {
    case DecOrPrifix:
    case MustDec:
      t = big ? WordType::BigDecimal : WordType::Decimal;
      return 1;

    case MustHex:
      t = big ? WordType::BigHexInt : WordType::HexInt;
      return 1;

    case MustOctal1:
      t = WordType::OctalInt1;
      return 1;

    case MustOctal2:
      t = big ? WordType::BigOctalInt : WordType::OctalInt2;
      return 1;

    case MustBinary:
      t = big ? WordType::BigBinaryInt : WordType::BinaryInt;
      return 1;
  }
  return 0;
}


int unicode_escape(CharSequence str, int length) {
  bool open_brace = false;
  int max_num_length = 4;
  enum {
    es_begin, es_u_flag, es_num_or_open_brace, es_hex,
  } state = es_begin;

  for (int i = 0; i < length; ++i) {
    switch (str[i]) {
      case '\\':
        if (state != es_begin) {
          return FailCode;
        }
        state = es_u_flag;
        break;

      case 'u':
        if (state != es_u_flag) {
          return FailCode;
        }
        state = es_num_or_open_brace;
        break;

      case '{':
        if (state != es_num_or_open_brace) {
          return FailCode;
        }
        open_brace = true;
        break;

      case '}':
        if (!open_brace) {
          return FailCode;
        }
        return i;

      case '0': case '1': case '2': case '3': case '4':
      case '5': case '6': case '7': case '8': case '9':
      case 'a': case 'b': case 'c': case 'd': case 'e': case 'f':
      case 'A': case 'B': case 'C': case 'D': case 'E': case 'F':
        if (state == es_num_or_open_brace) {
          state = es_hex;
        }
        if (state != es_hex) {
          return FailCode;
        }
        if (open_brace) break;
        if (--max_num_length <= 0) {
          return i;
        }
        break;

      default:
        return FailCode;
    }
  }
  return FailCode;
}


int parse_symbol(CharSequence str, int length, WordType& t) {
  Unicode c;
  int i = 0;
  if (str[0] != '$' && str[0] != '_') {
    i += utf8_to_unicode(c, str, length);
    if (UnicodeType::Letter != unicode_type(c)) {
      return 0;
    }
  } else {
    i = 1;
  }
  
  while (i < length) {
    if (str[i] == '\\') {
      int c = unicode_escape(str+i, length-i);
      if (c == FailCode) return 0;
      i += c + 1;
      continue;
    }

    int len = utf8_to_unicode(c, str + i, length - i);
    if (len == 0) return 0;
    i += len;

    if (c == '$' || c == '_') continue;
    if (c == 0x200C || c == 0x200D) continue;
    switch (unicode_type(c)) {
      case UnicodeType::Letter:
      case UnicodeType::CombiningMark:
      case UnicodeType::Digit:
      case UnicodeType::ConnectorPunctuation:
        continue;
    }
    return 0;
  }
  t = WordType::Symbol;
  return 1;
}


}