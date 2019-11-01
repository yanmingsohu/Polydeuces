#pragma once

#include "javascript.h"
#include <cmath>

namespace PolydeucesEngine {

//
// ��Ԫ��ѧ���������
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
  // �������ʵ��
  //
  virtual double calc(double a, double b) = 0;
  //
  // ����������, Ĭ�����Ƿ��� NaN
  //
  virtual RefVar str_calc(RefVar& a, RefVar& b) {
    RefVar str(new JSNaN());
    return str;
  }
};


//
// ��ֵ���������ʵ��
//
class AssignmentOperatorBase : public Runnable {
public:
  void operator()(RefContext& ctx, InstructionSet* ins) override {
    RefVar right = ctx->popCalc();
    RefVar left  = ctx->popCalcOriginal();
    assignment(ctx, left, right);
  }

  // �ڸ�ֵ֮ǰ��һЩ����, Ĭ��ɶҲ����
  virtual void calc(RefContext& ctx, std::string& leftname, RefVar& left, RefVar& right) {}

  inline void assignment(RefContext& ctx, RefVar& left, RefVar& right) {
    if (!left->isIdentifier()) {
      ctx->setError("Invalid left-hand value " + left->toString());
      return;
    }

    auto name = left->toString();
    calc(ctx, name, left, right);

    ctx->setContextProperty(name, right);
    ctx->pushCalc(left);
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
    right = op.calcRef(left_v, right);
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


}