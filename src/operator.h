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
    auto r = calcRef(a, b);
    ctx->pushCalc(r);
  }

  inline RefVar calcRef(RefVar a, RefVar b) {
    if (a->isNumber() && b->isNumber()) {
      auto c = calc(a->toNumber(), b->toNumber());
      RefVar r(new JSNumber(c));
      return r;
    } else if (a->isString() || b->isString()) {
      auto r = str_calc(a, b);
      return r;
    }
    return RefVar(new JSNaN());
  }
  //
  // 计算类的实现
  //
  virtual double calc(double a, double b) = 0;
  //
  // 非数字运算, 默认总是返回 NaN
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
    RefVar right = ctx->popCalc();
    RefVar left  = ctx->popCalcOriginal();
    assignment(ctx, left, right);
  }

  // 在赋值之前做一些运算, 默认啥也不做
  virtual void calc(RefContext& ctx, std::string& leftname, RefVar& left, RefVar& right) {}

  inline void assignment(RefContext& ctx, RefVar& left, RefVar& right) {
    if (!left->isIdentifier()) {
      ctx->setError("Invalid left-hand value " + left->toString());
      return;
    }

    auto name = left->toString();
    calc(ctx, name, left, right);
    if (!ctx->hasError()) {
      ctx->setContextProperty(name, right);
      if (!ctx->hasError()) {
        ctx->pushCalc(left);
      }
    }
  }
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


template<class MathOperator>
class AssignmentOperatorExp : public AssignmentOperatorBase {
private:
  MathOperator op;
public:
  void calc(RefContext& ctx, std::string& leftname, RefVar& left, RefVar& right) override {
    RefVar left_v = ctx->getContextProperty(leftname);
    if (!ctx->hasError()) {
      right = op.calcRef(left_v, right);
    }
  }
};



class VariableDeclarationAssignmentOperator : public AssignmentOperatorBase {
public:
  void operator()(RefContext& ctx, InstructionSet* ins) override {
    RefVar left  = ctx->popCalcOriginal();
    RefVar right = ctx->popCalc();
    assignment(ctx, left, right);
  }
};


template<class Calc, class Save>
class UnaryExpression : public Runnable {
private:
  Calc calc;
  Save save;
public:
  UnaryExpression(Calc c, Save s) : calc(c), save(s) {
  }

  void operator()(RefContext& ctx, InstructionSet* ins) override {
    RefVar left = ctx->popCalcOriginal();
    if (!left->isIdentifier()) {
      ctx->setError("Invalid left-hand value " + left->toString());
      return;
    }

    std::string name = left->toString();
    RefVar before = ctx->getContextProperty(name);
    if (ctx->hasError())
      return;

    // 变量为 name, 值是 before 进行计算返回计算结果
    RefVar after = calc(name, before);
    // before 是变量原始值, after 是计算后的值, 保存到上下文
    save(ctx, name, before, after);
  }
};


template<class Calc, class Save>
UnaryExpression<Calc, Save>* UnaryExpressionCreator(Calc c, Save s) {
  return new UnaryExpression<Calc, Save>(c, s);
}


RefVar IncrementOp(std::string& name, RefVar& value) {
  if (value->isNumber()) {
    return RefVar(new JSNumber(value->toNumber() + 1));
  } else {
    return RefVar(new JSNaN());
  }
}


RefVar DecreaseOp(std::string& name, RefVar& value) {
  if (value->isNumber()) {
    return RefVar(new JSNumber(value->toNumber() - 1));
  } else {
    return RefVar(new JSNaN());
  }
}


void PostSave(RefContext& ctx, std::string&name, RefVar& before, RefVar& after) {
  ctx->pushCalc(before);
  ctx->setContextProperty(name, after);
}


void PreSave(RefContext& ctx, std::string& name, RefVar& before, RefVar& after) {
  ctx->pushCalc(after);
  ctx->setContextProperty(name, after);
}

}