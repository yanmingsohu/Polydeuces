#include "gcomm.h"

#include "stdio.h"
#include "antlr4-runtime.h"
#include "JavaScriptParser.h"
#include "JavaScriptLexer.h"
#include "parser_listener.h"
#include "parser.h"

using namespace antlr4;
using namespace PolydeucesEngine;


void with_antlr4(std::ifstream& code) {
  ANTLRInputStream input(code);
  std::cout << input.toString() << "\n\n" << std::endl;
  JavaScriptLexer lexer(&input);
  lexer.setUseStrictDefault(true);
  CommonTokenStream tokens(&lexer);

  std::cout << (lexer.IsStrictMode() ? "Strict\n" : "Not Strict\n");

  IManagerListener defaultML;
  Manager manager(defaultML);
  CoreListener cl(manager);
  JavaScriptParser parser(&tokens);
  parser.addParseListener(&cl);
  tree::ParseTree* tree = parser.program();

  //std::wstring s =  + L"\n";
  // Unicode output in the console is very limited.
  /*std::wcout << "\n Parse Tree: \n"
             << antlrcpp::s2ws(tree->toStringTree(&parser))
             <<"\n" << std::endl; */

  manager.start();
  printf("ok");
}


int main(char** argv, int argc) {
  std::ifstream code;
  code.open("../../test/first.js");
  parse_javascript(code);
  return 0;
}