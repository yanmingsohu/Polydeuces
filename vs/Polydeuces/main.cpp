#include "stdio.h"
#include "antlr4-runtime.h"
#include "JavaScriptParser.h"
#include "JavaScriptLexer.h"

#ifdef WIN32
#pragma comment(lib, "antlr4-runtime.lib")
#endif

int main(char** argv, int argc) {
  printf("hello");
  return 0;
}