#pragma once

#include <fstream>
#include <vector>
#include "options.h"
#include "types.h"
#include "parser_gen.h"

namespace PolydeucesEngine {


enum WordType {
  Non, KeyWord, String, Operator, Comment, Symbol, SyntaxError, NewLine,
  Decimal, HexInt, OctalInt1, OctalInt2, BinaryInt,
  BigDecimal, BigHexInt, BigOctalInt, BigBinaryInt,
};


struct Word {
  CharSequence begin;
  int length;
  WordType type;
  JSLexer lexer;

  std::string toString() {
    return std::string(reinterpret_cast<char*>(begin), length);
  }
};


typedef std::vector<Word> WordList;


class ParseData {
private:
  WordList words;
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
  /* ʹ���ڲ���ʼָ���� endpos ָ�빹��һ�� Word, 
     ���ڲ���ʼָ�볬�� endpos ���� false, û�� Word ������ */
  bool pushWord(int endpos, WordType t, JSLexer l);
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
  /* ���� Word ���� */
  WordList& getWords();
};


class IncrementCounter {
private:
  CharSequence current;
  int line;
  int col;
public:
  const CharSequence buffer;
  const int total;

  IncrementCounter(ParseData& pd) : IncrementCounter(pd.code_ref(), pd.length) {}
  IncrementCounter(CharSequence p, const int len) 
  : buffer(p), current(p), line(1), col(1), total(len) {}
  void findNextLine(int& outLine, int& outColumn, CharSequence endPos);
};


class IGrammarListener {
public:
  virtual ~IGrammarListener() {}
  virtual void enterBlock(Word&) = 0;
  virtual void exitBlock(Word&) = 0;
  virtual void declaration_var(Word&, JSLexer modifier) = 0;
};


void parse_javascript(std::ifstream& code);
void parse_javascript(CharSequence code, const int length);
void parse_lexer(ParseData& pd);
int parser_operator(CharSequence str, int length, JSLexer& t);
int parser_key_word(CharSequence str, int length, JSLexer& t);
int parse_number(CharSequence str, int length, WordType& t);
int parse_symbol(CharSequence str, int length, WordType& t);
int begin_parse_grammar(ParseData&);
void print_error_line(IncrementCounter&, Word&);


}