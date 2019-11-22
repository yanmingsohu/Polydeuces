#include "parser.h"
#include "tool.h"
#include <string>
#include <iostream>
#include <vector>
#include <memory>

namespace PolydeucesEngine {


ParseData::ParseData(CharSequence _code, int bufferLength)
: code(_code), length(bufferLength), begin(0)
, error_count(0) {
}


CharCode ParseData::operator[](int i) {
  return code[i];
}


bool ParseData::pushWord(int endpos, WordType t, JSLexer l) {
  if (endpos <= begin) return false;
  //std::cout << begin << ',' << endpos << std::endl;
  words.push_back({code + begin, endpos - begin, t, l});
  return true;
}


void ParseData::pushCheckWord(int endpos) {
  if (endpos <= begin) return;
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


void ParseData::pushError(int i) {
  if (pushWord(i, WordType::SyntaxError, JSLexer::Unknow)) {
    update(i + 1);
    ++error_count;
  }
}


int ParseData::errorCount() {
  return error_count;
}


void ParseData::update(int last_pos) {
  begin = last_pos;
}


void ParseData::print() {
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


CharSequence ParseData::code_ref() {
  return code;
}


std::vector<Word>& ParseData::getWords() {
  return words;
}


void IncrementCounter::findNextLine(int& l, int& c, CharSequence end) {
  for (auto i = current; i < end; ++i) {
    if (*i == '\n') {
      ++line;
      col = 1;
    } else {
      ++col;
    }
  }
  current = end;
  l = line;
  c = col;
}


void print_error_line(IncrementCounter& ic, CharSequence code, int length, Word& w) {
  CharCode* begin = w.begin;
  for (int i = 0; i < 30; ++i) {
    if (begin <= code) break;
    if (*begin == '\n') {
      ++begin;
      break;
    }
    --begin;
  }

  int begin_len = w.begin - begin;
  const int end_offset = get_min(60, length - begin_len);
  while (begin_len < end_offset) {
    if (begin[begin_len] == '\n') break;
    ++begin_len;
  }

  int line, col;
  ic.findNextLine(line, col, w.begin);

  std::cout << '\n';
  std::cout.write(reinterpret_cast<char*>(begin), begin_len) << '\n';
  for (int i = w.begin - begin; i > 0; --i) {
    std::cout << ' ';
  }
  std::cout <<"^ SyntaxError: `";
  std::cout.write(reinterpret_cast<char*>(w.begin), w.length);
  std::cout <<"` at ["<< line <<':'<< col <<']'<< std::endl;
}


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


// ! 主要解析器函数
void parse_javascript(CharSequence code, const int length) {
  ParseData pd(code, length);
  parse_lexer(pd);
  pd.print();

  if (pd.errorCount() > 0) {
    IncrementCounter ic(code);
    auto words = pd.getWords();

    for (auto i = words.begin(); i != words.end(); ++i) {
      if (WordType::SyntaxError == i->type) {
        print_error_line(ic, code, length, *i);
      }
    }
    std::cout << "Error count: " << pd.errorCount() << std::endl;
  }
}


}