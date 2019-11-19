#pragma once

#include <fstream>
#include "lexer.h"

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
bool parser_operator(char* str, int length, JSLexer& t);


}