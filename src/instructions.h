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
    RefVar rv(new JSNumber(num));
    ctx->pushCalc(rv);
  }
};


class DebugCalc : public Runnable {
public:
  void operator()(RefContext& ctx, InstructionSet* ins) {
    ctx->printCalcStack();
  }
};


class PushLiteral : public Runnable {
private:
  RefVar var;
public:
  PushLiteral(RefVar rv) : var(rv) {}
  PushLiteral(Var* v) : var(v) {}

  void operator()(RefContext& ctx, InstructionSet* ins) {
    ctx->pushCalc(var);
  }
};


class IdentifierExp : public Runnable {
private:
  std::string name;
public:
  IdentifierExp(std::string n) : name(n) {}

  void operator()(RefContext& ctx, InstructionSet* ins) {
    RefVar rv(new JSIdentifier(name));
    ctx->pushCalc(rv);
  }
};


}