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

    // ����Ϊ name, ֵ�� before ���м��㷵�ؼ�����
    RefVar after = calc(name, before);
    // before �Ǳ���ԭʼֵ, after �Ǽ�����ֵ, ���浽������
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


//
// bool CompareOp(double d) ��� d>0 ��������������Ҳ�����, ���ز���ֵ
// bool TypeCompareOp(JavaScriptTypeId a, JavaScriptTypeId b, bool& returnVar) -
//    �Ƚ� a b ������, ������� true ��ʹ�� returnVar 
//    ��ֵ��Ϊ�������ʽ�Ľ��, ����ִ�к�������
//
template<class CompareOp, class TypeCompareOp>
class RelationalExpressionOp : public Runnable {
private:
  CompareOp* compare;
  TypeCompareOp* type;

public:
  RelationalExpressionOp(CompareOp* _c, TypeCompareOp* _t) 
  : compare(_c), type(_t) {}

  void operator()(RefContext& ctx, InstructionSet* ins) override {
    auto b = ctx->popCalc();
    auto a = ctx->popCalc();
    auto r = calcRef(a, b);
    RefVar ref(new JSBoolean(r));
    ctx->pushCalc(ref);
  }

  inline bool calcRef(RefVar a, RefVar b) {
    double va = 0, vb = 0;
    bool r = false;

    if ( type(a->typeID(), b->typeID(), r) ) {
      return r;
    }

    // �Ƚ�����
    if (canbeNum(a, va) || canbeNum(b, vb)) {
      r = compare(va - vb);
    }
    // �Ƚ��ַ���
    else if (a->isString() && b->isString()) {
      r = compare( a->toString().compare(b->toString()) );
    }
    // �Ƚϵ�ַ
    else if (a->isObject() || b->isObject()) {
      va = double(long(a.get()));
      vb = double(long(b.get()));
      r = compare(va - vb);
    }
    // ���ɱȽ϶���ıȽ�
    else if (a->isNaN()) {
      r = compare(b->isNaN() ? 0 : 1);
    }
    else if (a->isNull() || a->isUndefined()) {
      r = compare((b->isNull() || b->isUndefined()) ? 0 : 1);
    }
    return r;
  }

  // ���԰Ѷ���ת��Ϊ����, ��������޷�ת������ false
  inline bool canbeNum(RefVar& rv, double& v) {
    if (rv->isNumber() || rv->isBool()) {
      v = rv->toNumber();
      return true;
    }
    if (rv->isString() || rv->isArray()) {
      try {
        v = std::stod(rv->toString());
        return true;
      } catch (std::invalid_argument&) {
      } catch (std::out_of_range&) {}
    }
    return false;
  }
};


template<class Com, class Type>
RelationalExpressionOp<Com, Type>* RelationalExpressionCreator(Com* f1, Type* f2) {
  return new RelationalExpressionOp<Com, Type>(f1, f2);
}


bool LessThanExp(const double r) {
  return r < 0;
}


bool LessThanEqualsExp(const double r) {
  return r <= 0;
}


bool MoreThanExp(const double r) {
  return r > 0; 
}


bool GreaterThanEqualsExp(const double r) {
  return r >= 0;
}


bool EqualsExp(const double r) {
  return r == 0;
}


bool NotEqualsExp(const double r) {
  return r != 0;
}


bool IdentityEqualsExp(JavaScriptTypeId a, JavaScriptTypeId b, bool& r) {
  if (a == b) return false;
  r = false;
  return true;
}


bool IdentityNotEqualsExp(JavaScriptTypeId a, JavaScriptTypeId b, bool& r) {
  if (a == b) return false;
  r = true;
  return true;
}


bool SkipType(JavaScriptTypeId a, JavaScriptTypeId b, bool& r) {
  return false;
}


class LogicalAndExp : public Runnable {
public:
  void operator()(RefContext& ctx, InstructionSet* ins) override {
    auto b = ctx->popCalc();
    auto a = ctx->popCalc();
    if (a->toBoolean() && b->toBoolean()) {
      ctx->pushCalc(b);
    }
    ctx->pushCalc(a);
  }
};


class LogicalOrExp : public Runnable {
public:
  void operator()(RefContext& ctx, InstructionSet* ins) override {
    auto b = ctx->popCalc();
    auto a = ctx->popCalc();
    if (a->toBoolean()) {
      ctx->pushCalc(a);
    }
    ctx->pushCalc(b);
  }
};


class NotExp : public Runnable {
public:
  void operator()(RefContext& ctx, InstructionSet* ins) override {
    auto a = ctx->popCalc();
    auto b = a->toBoolean();
    RefVar v(new JSBoolean(!b));
    ctx->pushCalc(v);
  }
};


class BitNotEx : public Runnable {
public:
  void operator()(RefContext& ctx, InstructionSet* ins) override {
    auto a = ctx->popCalc();
    int b = int(a->toNumber());
    RefVar v(new JSNumber(~b));
    ctx->pushCalc(v);
  }
};

}