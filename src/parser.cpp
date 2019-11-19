#include "parser.h"
#include <string>
#include <iostream>
#include <vector>
#include <memory>

namespace PolydeucesEngine {


class ParseData {
private:
  std::vector<Word> words;
  WordState state;
  // 不负责 code 的内存管理
  char* code;
  int begin;
  int error_count;

public:
  const int length;

public:
  ParseData(char* _code, int bufferLength) 
  : code(_code), length(bufferLength), begin(0)
  , state(WordState::Blank), error_count(0) {
  }

  char operator[](int i) {
    return code[i];
  }

  void setState(WordState s) {
    state = s;
  }

  bool isState(WordState s) {
    return state == s;
  }

  void pushWord(int endpos, WordType t, JSLexer l = JSLexer::Unknow) {
    if (endpos <= begin) return;
    if (t == WordType::Non) {
      if (parser_key_word(code + begin, endpos - begin, l)) {
        t = WordType::KeyWord;
      }
    }
    //std::cout << begin << ',' << endpos << std::endl;
    words.push_back({code + begin, endpos - begin, t, l});
  }

  void pushError(int i) {
    pushWord(i, WordType::SyntaxError);
    update(i + 1);
    ++error_count;
  }

  int errorCount() {
    return error_count;
  }

  void update(int last_pos) {
    begin = last_pos;
    state = WordState::Blank;
  }

  void print() {
    for (auto i = words.begin(); i != words.end(); ++i) {
      std::cout << std::string(i->begin, i->length) 
                << '\t' << i->length << '\t';
      switch (i->type) {
        case KeyWord: std::cout << "Key"; break;
        case Num: std::cout << "Num"; break;
        case String: std::cout << "String"; break;
        case Operator: std::cout << "Operator"; break;
        case Comment: std::cout << "Comment"; break;
        case Symbol: std::cout << "symbol"; break;
        default:
          std::cout << "Non"; break;
      }
      std::cout << ' ';
      print_lexer(i->lexer, std::cout);
      std::cout << std::endl;
    }
  }

  char* code_ref() {
    return code;
  }
}; 


void parse_javascript(std::ifstream& code_stm) {
  code_stm.seekg(0, std::ios_base::end);
  std::ifstream::streampos filesize = code_stm.tellg();
  code_stm.seekg(0, std::ios_base::beg);

  // 输入流处理了不同平台的换行问题
  std::unique_ptr<char[]> code_buf(new char[filesize]);
  std::streambuf* raw_buffer = code_stm.rdbuf();
  auto realsize = raw_buffer->sgetn(code_buf.get(), filesize);

  ParseData pd(code_buf.get(), realsize);
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
  pd.pushWord(i, WordType::Comment);
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
  pd.pushWord(i, WordType::Comment);
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
  pd.pushWord(i, WordType::String);
  pd.update(i+1);
}


void parse_javascript(char* code, const int length) {
  ParseData pd(code, length);
  parse_lexer(pd);
}


void parse_lexer(ParseData& pd) {
  for (int i = 0; i < pd.length; ++i) {
    switch (pd[i]) {
      case '\n':
      case ' ':
      case '\t':
        if (pd.isState(WordState::Char)) {
          pd.pushWord(i, WordType::Non);
        } // no break;
      case '\r':
        pd.update(i+1);
        pd.setState(WordState::Blank);
        break;

      case '/':
        pd.pushWord(i, WordType::Non);
        pd.update(i);
        if (pd.isState(WordState::Char) || pd.isState(WordState::Blank)) {
          if (pd[i + 1] == '/') {
            SingleLineComment(pd, i+=2);
          }
          else if (pd[i + 1] == '*') {
            MultiLineComment(pd, i+=2);
          }
        } else {
          pd.pushWord(i + 1, WordType::Operator);
          pd.update(i + 1);
        }
        break;

      case '\'':
        pd.pushWord(i, WordType::Non);
        ++i;
        pd.update(i);
        NormString(pd, i, '\'');
        break;

      case '"':
        pd.pushWord(i, WordType::Non);
        ++i;
        pd.update(i);
        NormString(pd, i, '"');
        break;

      case '`': //TODO: 完整支持多行字符串
        pd.pushWord(i, WordType::Non);
        ++i;
        pd.update(i);
        NormString(pd, i, '`');
        break;

      default:
        JSLexer lexer;
        int offset = parser_operator(pd.code_ref() + i, pd.length - i, lexer);
        if (offset) {
          pd.pushWord(i, WordType::Non);
          pd.update(i);
          pd.pushWord(i + offset, WordType::Operator, lexer);
          pd.update(i + offset);
          continue;
        }
        
        if (pd[i] >= 33 && pd[i] < 127) {
          pd.setState(WordState::Char);
        } 
        else {
          pd.setState(WordState::Ctrl);
        }
        break;
    }
  }
  pd.pushWord(pd.length, WordType::Non);
}


}