// node generate-lexer.js
const fs = require('fs');

const header = `
#include "parser.h"
#include "lexer.h"

namespace PolydeucesEngine {


bool parser_operator(char* str, int len, JSLexer& t) {
  switch (str[0]) {
`;
  
const booter = `
  }
  return false;
}


}
`;



