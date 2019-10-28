#include "gcomm.h"

#include "stdio.h"
#include "antlr4-runtime.h"
#include "JavaScriptParser.h"
#include "JavaScriptLexer.h"

using namespace antlr4;
using namespace PolydeucesEngine;

int main(char** argv, int argc) {
  std::ifstream code;
  code.open("../../test/first.js");

  ANTLRInputStream input(code);
  std::cout << input.toString() << "\n\n" << std::endl;
  JavaScriptLexer lexer(&input);
  CommonTokenStream tokens(&lexer);

  JavaScriptParser parser(&tokens);
  tree::ParseTree* tree = parser.program();
  //parser.addParseListener()

  std::wstring s = antlrcpp::s2ws(tree->toStringTree(&parser)) + L"\n";
  std::wcout << "Parse Tree: " << s << std::endl; // Unicode output in the console is very limited.

  printf("ok");
  return 0;
}