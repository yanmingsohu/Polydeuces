#pragma once

#include <fstream>
#include "parser_gen.h"

namespace PolydeucesEngine {


enum WordType {
  Non, KeyWord, String, Operator, Comment, Symbol, SyntaxError,
  Decimal, HexInt, OctalInt1, OctalInt2, BinaryInt,
  BigDecimal, BigHexInt, BigOctalInt, BigBinaryInt,
};


enum WordState {
  Ctrl, Blank, Char,
};


struct Word {
  char* begin;
  int length;
  WordType type;
  JSLexer lexer;
};


template<class T> bool isDigital(T c) {
  return c >= '0' && c <='9';
}


template<class T> bool isLetter(T c) {
  return (c>= 'a' && c <= 'z') || (c >= 'A' && c <='Z');
}


class ParseData;
void parse_javascript(std::ifstream& code);
void parse_javascript(char* code, const int length);
void parse_lexer(ParseData& pd);
int parser_operator(char* str, int length, JSLexer& t);
int parser_key_word(char* str, int length, JSLexer& t);
int parse_number(char* str, int length, WordType& t);
int parse_symbol(char* str, int length, WordType& t);


}