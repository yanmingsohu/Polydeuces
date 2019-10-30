#pragma once

#include "javascript.h"

namespace PolydeucesEngine {


class EnterBlock : public Runnable {
public:
  void operator()(RefContext& ctx, InstructionSet* ins) {
    auto nCtx = ins->newContext();
    ins->setCurrContext(nCtx);
    std::cout << "[Enter block>>>]";
  }
};


class ExitBlock : public Runnable {
public:
  void operator()(RefContext& ctx, InstructionSet* ins) {
    auto pCtx = ctx->getParent();
    ins->setCurrContext(pCtx);
    std::cout << "[Exit block<<<]\n";
  }
};


class PushNumeric : public Runnable {
private:
  double num;

public:
  PushNumeric(double n) {
    num = n;
  }

  void operator()(RefContext& ctx, InstructionSet* ins) {
    ctx->pushCalc(new JSNumber(num));
  }
};


class DebugCalc : public Runnable {
public:
  void operator()(RefContext& ctx, InstructionSet* ins) {
    ctx->printCalcStack();
  }
};


}