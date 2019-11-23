#pragma once

#include <iostream>
#include <string>
#include "parser.h"

namespace PolydeucesEngine {

#define DEBUG


class DebugGrammar : public IGrammarListener {
private:
  template<class T> void pl(T msg) {
    std::cout << msg << std::endl;
  }

public:
  void enterBlock(Word& w) { pl("enter block "+ w.toString()); }

  void exitBlock(Word& w) { pl("exit block "+ w.toString()); }

  void declaration_var(Word& w, JSLexer modifier) {
    switch (modifier) {
      case JSLexer::Var:
        pl("var "+ w.toString());
        break;

      case JSLexer::Let:
        pl("let "+ w.toString());
        break;

      case JSLexer::Const:
        pl("const "+ w.toString());
        break;
    }
  }

  void enterExp(Word& w) {
    pl("Enter express");
  }

  void exitExp(Word& w) {
    pl("Exit express");
  }
};

}