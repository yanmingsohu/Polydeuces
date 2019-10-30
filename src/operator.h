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
      ctx->pushCalc(new JSNumber(c));
    }
    else {
      ctx->pushCalc(new JSNaN());
    }
  }

  //
  // 计算类的实现
  //
  virtual double calc(double a, double b) = 0;
};


class PlusExp : public Runnable {
public:
  void operator()(RefContext& ctx, InstructionSet* ins) override {
    auto b = ctx->popCalc();
    auto a = ctx->popCalc();

    if (a->isNumber() && b->isNumber()) {
      auto c = a->toNumber() + b->toNumber();
      ctx->pushCalc(new JSNumber(c));
    } 
    else if (a->isString() || b->isString()) {
      // TODO
    } 
    else {
      ctx->pushCalc(new JSNaN());
    }
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
      ctx->pushCalc(new JSNumber(- m->toNumber()));
    }
    else {
      ctx->pushCalc(new JSNaN());
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


}