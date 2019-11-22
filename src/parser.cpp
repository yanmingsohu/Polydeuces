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


void ParseData::pushWord(int endpos, WordType t, JSLexer l) {
  if (endpos <= begin) return;
  //std::cout << begin << ',' << endpos << std::endl;
  words.push_back({code + begin, endpos - begin, t, l});
}


void ParseData::pushCheckWord(int endpos) {
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
  pushWord(i, WordType::SyntaxError, JSLexer::Unknow);
  update(i + 1);
  ++error_count;
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


}