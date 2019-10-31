#pragma once

#include "javascript.h"
#include <cmath>

namespace PolydeucesEngine {

//
// 二元数学运算基础类
//
class BinaryMathematicalOperator : public Runnable {
public:
  void operator()(RefContext& ctx, InstructionSet* ins) override {
    auto b = ctx->popCalc();
    auto a = ctx->popCalc();

    if (a->isNumber() && b->isNumber()) {
      auto c = calc(a->toNumber(), b->toNumber());
      RefVar r(new JSNumber(c));
      ctx->pushCalc(r);
    }
    else if (a->isString() || b->isString()) {
      auto r = str_calc(a, b);
      ctx->pushCalc(r);
    }
    else {
      RefVar r(new JSNaN());
      ctx->pushCalc(r);
    }
  }

  //
  // 计算类的实现
  //
  virtual double calc(double a, double b) = 0;
  //
  // 非数字运算, 总是返回 NaN
  //
  virtual RefVar str_calc(RefVar& a, RefVar& b) {
    RefVar str(new JSNaN());
    return str;
  }
};


//
// 赋值运算符基础实现
//
class AssignmentOperatorBase : public Runnable {
public:
  void operator()(RefContext& ctx, InstructionSet* ins) override {
    ctx->printCalcStack();
    RefVar right = ctx->popCalc();
    RefVar left  = ctx->popCalcOriginal();

    if (!left->isIdentifier()) {
      ctx->setError("Invalid left value "+ left->toString());
      return;
    }

    calc(ctx, left, right);

    auto name = left->toString();
    ctx->setProperty(name, right);
  }

  // 在赋值之前做一些运算, 默认啥也不做
  void calc(RefContext& ctx, RefVar& left, RefVar& right) {}
};


class PlusExp : public BinaryMathematicalOperator {
public:
  double calc(double a, double b) override {
    return a + b;
  }

  RefVar str_calc(RefVar& a, RefVar& b) override {
    std::string r = a->toString() + b->toString();
    return RefVar(new JSString(r));
  }
};


class MinusExp : public BinaryMathematicalOperator {
public:
  double calc(double a, double b) override {
    return a - b;
  }
};


class MultiplyExp : public BinaryMathematicalOperator {
public:
  double calc(double a, double b) override {
    return a * b;
  }
};


class DivideExp : public BinaryMathematicalOperator {
public:
  double calc(double a, double b) override {
    return a / b;
  }
};


class ModulusExp : public BinaryMathematicalOperator {
public:
  double calc(double a, double b) override {
    return std::fmod(a, b);
  }
};


class UnaryMinusExp : public Runnable {
public:
  void operator()(RefContext& ctx, InstructionSet* ins) override {
    auto m = ctx->popCalc();
    if (m->isNumber()) {
      RefVar r(new JSNumber(-m->toNumber()));
      ctx->pushCalc(r);
    }
    else {
      RefVar r(new JSNaN());
      ctx->pushCalc(r);
    }
  }
};


class LeftShiftExp : public BinaryMathematicalOperator {
public:
  double calc(double a, double b) override {
    return int(int(a) << int(b));
  }
};


class RightShiftExp : public BinaryMathematicalOperator {
public:
  double calc(double a, double b) override {
    return int(int(a) >> int(b));
  }
};


class RightShiftLogExp : public BinaryMathematicalOperator {
public:
  double calc(double a, double b) override {
    return int(unsigned int(a) >> int(b));
  }
};


class BitAndExp : public BinaryMathematicalOperator {
public:
  double calc(double a, double b) override {
    return long(unsigned int(a) & unsigned int(b));
  }
};


class BitOrExp : public BinaryMathematicalOperator {
public:
  double calc(double a, double b) override {
    return long(unsigned int(a) | unsigned int(b));
  }
};


class BitXOrExp : public BinaryMathematicalOperator {
public:
  double calc(double a, double b) override {
    return long(unsigned int(a) ^ unsigned int(b));
  }
};


class AssignmentExp : public AssignmentOperatorBase {
};


}