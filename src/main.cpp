#include "gcomm.h"

#include "stdio.h"
#include "antlr4-runtime.h"
#include "JavaScriptParser.h"
#include "JavaScriptLexer.h"
#include "parser_listener.h"

using namespace antlr4;
using namespace PolydeucesEngine;

int main(char** argv, int argc) {
  std::ifstream code;
  code.open("../../test/first.js");

  ANTLRInputStream input(code);
  std::cout << input.toString() << "\n\n" << std::endl;
  JavaScriptLexer lexer(&input);
  lexer.setUseStrictDefault(true); //!! ÓÐÎÊÌâ
  CommonTokenStream tokens(&lexer);

  Manager manager;
  CoreListener cl(&manager);
  JavaScriptParser parser(&tokens);
  parser.addParseListener(&cl);
  tree::ParseTree* tree = parser.program();

  //std::wstring s =  + L"\n";
  // Unicode output in the console is very limited.
  std::wcout << "\n Parse Tree: \n" 
             << antlrcpp::s2ws(tree->toStringTree(&parser)) 
             <<"\n" << std::endl; 

  printf("ok");
  return 0;
}