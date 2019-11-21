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


enum WordState {
  Ctrl, Blank, Char,
};


struct Word {
  CharSequence begin;
  int length;
  WordType type;
  JSLexer lexer;
};


class ParseData;

void parse_javascript(std::ifstream& code);
void parse_javascript(CharSequence code, const int length);
void parse_lexer(ParseData& pd);
int parser_operator(CharSequence str, int length, JSLexer& t);
int parser_key_word(CharSequence str, int length, JSLexer& t);
int parse_number(CharSequence str, int length, WordType& t);
int parse_symbol(CharSequence str, int length, WordType& t);
void begin_parse_grammar(std::vector<Word>& words);


}