#pragma once

#include "javascript.h"

namespace PolydeucesEngine {


class EnterBlock : public Microinstruction {
public:
  void operator()(RefContext& ctx, Microinstruction::Param cpu) {
    auto nCtx = cpu->newContext();
    cpu->setCurrContext(nCtx);
    std::cout << "[Enter block>>>]\n";
  }
};


class ExitBlock : public Microinstruction {
public:
  void operator()(RefContext& ctx, Microinstruction::Param cpu) {
    auto pCtx = ctx->getParent();
    cpu->setCurrContext(pCtx);
    std::cout << "[Exit block<<<]\n";
  }
};


class PushNumeric : public Microinstruction {
private:
  double num;

public:
  PushNumeric(double n) {
    num = n;
  }

  void operator()(RefContext& ctx, Microinstruction::Param cpu) {
    RefVar rv(new JSNumber(num));
    ctx->pushCalc(rv);
  }
};


class DebugCalc : public Microinstruction {
public:
  void operator()(RefContext& ctx, Microinstruction::Param cpu) {
    ctx->printCalcStack();
  }
};


class PushLiteral : public Microinstruction {
private:
  RefVar var;
public:
  PushLiteral(RefVar rv) : var(rv) {}
  PushLiteral(Var* v) : var(v) {}

  void operator()(RefContext& ctx, Microinstruction::Param cpu) {
    ctx->pushCalc(var);
  }
};


class IdentifierExp : public Microinstruction {
private:
  std::string name;
public:
  IdentifierExp(std::string n) : name(n) {}

  void operator()(RefContext& ctx, Microinstruction::Param cpu) {
    RefVar rv(new JSIdentifier(name));
    ctx->pushCalc(rv);
  }
};


class DefineVar : public Microinstruction {
private:
  std::string name;
public:
  DefineVar(std::string _name) : name(_name) {}

  void operator()(RefContext& ctx, Microinstruction::Param cpu) {
    JSContext fc = ctx->getFunctionContext();
    fc.setProperty(name, RefVar(new JSUndefined()));
  }
};


class DefineLet : public Microinstruction {
private:
  std::string name;
public:
  DefineLet(std::string _name) : name(_name) {}

  void operator()(RefContext& ctx, Microinstruction::Param cpu) {
    ctx->setProperty(name, RefVar(new JSUndefined()));
  }
};


class DefineLock : public Microinstruction {
private:
  std::string name;
public:
  DefineLock(std::string _name) : name(_name) {}

  void operator()(RefContext& ctx, Microinstruction::Param cpu) {
    ctx->setConst(name);
  }
};


class ClearCalcStack : public Microinstruction {
public:
  void operator()(RefContext& ctx, Microinstruction::Param cpu) {
    ctx->clearCalcStack();
  }
};


class PushUndefined : public Microinstruction {
  void operator()(RefContext& ctx, Microinstruction::Param cpu) {
    RefVar rf(new JSUndefined());
    ctx->pushCalc(rf);
  }
};


}