#pragma once

#include <fstream>
#include <vector>
#include "types.h"
#include "parser_gen.h"

namespace PolydeucesEngine {


enum WordType {
  Non, KeyWord, String, Operator, Comment, Symbol, SyntaxError,
  Decimal, HexInt, OctalInt1, OctalInt2, BinaryInt,
  BigDecimal, BigHexInt, BigOctalInt, BigBinaryInt,
};


struct Word {
  CharSequence begin;
  int length;
  WordType type;
  JSLexer lexer;
};


class ParseData {
private:
  std::vector<Word> words;
  CharSequence code;
  // 内部起始字符指针
  int begin;
  int error_count;

public:
  const int length;

public:
  /* _code 内存由外部管理 */
  ParseData(CharSequence _code, int bufferLength);
  /* 用索引 i 检索缓冲区字符 */
  CharCode operator[](int i);
  /* 使用内部起始指针与 endpos 指针构造一个 Word */
  void pushWord(int endpos, WordType t, JSLexer l);
  /* 除了 pushWord 还要检查 Word 的类型 */
  void pushCheckWord(int endpos);
  /* 压入的 Word 是不符合词法的时候调用 */
  void pushError(int i);
  /* 错误数量 */
  int errorCount();
  /* 更新内部起始字符指针 */
  void update(int last_pos);
  /* 打印所有 Word 序列 */
  void print();
  /* 返回字符缓冲区指针 */
  CharSequence code_ref();
};


void parse_javascript(std::ifstream& code);
void parse_javascript(CharSequence code, const int length);
void parse_lexer(ParseData& pd);
int parser_operator(CharSequence str, int length, JSLexer& t);
int parser_key_word(CharSequence str, int length, JSLexer& t);
int parse_number(CharSequence str, int length, WordType& t);
int parse_symbol(CharSequence str, int length, WordType& t);
void begin_parse_grammar(std::vector<Word>& words);


}