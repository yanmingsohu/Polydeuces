#pragma once

#include <fstream>
#include "parser_gen.h"

namespace PolydeucesEngine {


enum WordType {
  Non, KeyWord, Num, String, Operator, Comment, Symbol, SyntaxError
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


class ParseData;
void parse_javascript(std::ifstream& code);
void parse_javascript(char* code, const int length);
void parse_lexer(ParseData& pd);
int parser_operator(char* str, int length, JSLexer& t);
int parser_key_word(char* str, int length, JSLexer& t);


}