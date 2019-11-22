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
  // �ڲ���ʼ�ַ�ָ��
  int begin;
  int error_count;

public:
  const int length;

public:
  /* _code �ڴ����ⲿ���� */
  ParseData(CharSequence _code, int bufferLength);
  /* ������ i �����������ַ� */
  CharCode operator[](int i);
  /* ʹ���ڲ���ʼָ���� endpos ָ�빹��һ�� Word */
  void pushWord(int endpos, WordType t, JSLexer l);
  /* ���� pushWord ��Ҫ��� Word ������ */
  void pushCheckWord(int endpos);
  /* ѹ��� Word �ǲ����ϴʷ���ʱ����� */
  void pushError(int i);
  /* �������� */
  int errorCount();
  /* �����ڲ���ʼ�ַ�ָ�� */
  void update(int last_pos);
  /* ��ӡ���� Word ���� */
  void print();
  /* �����ַ�������ָ�� */
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