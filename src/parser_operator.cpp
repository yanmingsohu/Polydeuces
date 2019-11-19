#include "parser.h"
#include "lexer.h"

namespace PolydeucesEngine {


bool parser_operator(char* str, int len, JSLexer& t) {
  switch (str[0]) {
    case '*':
      if (len > 1 && str[1] == '*') {
        t = JSLexer::Power;
      } else {
        t = JSLexer::Multiply;
      }
      return true;
  }
  return false;
}


}