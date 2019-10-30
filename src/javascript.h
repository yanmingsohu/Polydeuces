#pragma once

#include <algorithm>
#include <vector>
#include <memory>
#include <list>
#include <string>
#include <sstream>

namespace PolydeucesEngine {

class Manager;
class Runnable;
class instruction;
class Process;
class Noncopy;
class Var;
class JSObject;
class JSContext;
class JSNull;
class JSUndefined;
class JSNaN;
class JSNumber;
typedef std::shared_ptr<JSContext> RefContext;


class Noncopy {
public:
  Noncopy() {};
  virtual ~Noncopy() {};

private:
  Noncopy(Noncopy const&) = delete;
  Noncopy operator=(const Noncopy&) = delete;
};


//
// ���� js ����Ļ���, ���ɸ��Ʋ��ɸ�ֵ.
//
class JSObject : private Noncopy {
public:
  JSObject();
};

typedef std::shared_ptr<JSObject> RefObj;


//
// ԭʼ���ͻ���, ���Ը���
//
class Var {
public:
  Var() {}
  virtual ~Var() {}

  // ����ַ����� output, Ĭ�ϵ��� toString(), Ӧ�þ�������д�÷���
  virtual void appendString(std::stringstream& output) {
    output << toString();
  }

  // ת��Ϊ�ַ���, Ĭ��ʲô������
  virtual std::string toString() = 0;
  // ת��Ϊ����, Ĭ�Ϸ��� 0
  virtual double toNumber() { return 0; }
  // ת��Ϊ bool, Ĭ�Ϸ��� false
  virtual bool toBoolean() { return false; }

  // ����� X ���� true, Ĭ�Ϸ��� false
  virtual bool isNumber()    { return false; }
  virtual bool isBool()      { return false; }
  virtual bool isString()    { return false; }
  virtual bool isNull()      { return false; }
  virtual bool isUndefined() { return false; }
  virtual bool isNaN()       { return false; }
  virtual bool isFunction()  { return false; }
  virtual bool isArray()     { return false; }
  virtual bool isObject()    { return false; }
  virtual bool isSymbol()    { return false; }
};

typedef std::shared_ptr<Var> RefVar;


class JSNull : public Var {
public:
  bool isNull() override;
  void appendString(std::stringstream&) override;
  std::string toString() override;
  // null ����������ѧ����ʱ����ʹ��
  bool isNumber() override;
};


class JSUndefined : public Var {
public:
  bool isUndefined() override;
  void appendString(std::stringstream&) override;
  std::string toString() override;
};


class JSNaN : public Var {
public:
  bool isNaN() override;
  void appendString(std::stringstream&) override;
  std::string toString() override;
};


class JSNumber : public Var {
private:
  double num;
public:
  JSNumber(double n = 0);
  bool isNumber() override;
  void appendString(std::stringstream&) override;
  std::string toString() override;
  double toNumber() override;
  bool toBoolean() override;
};


//
// ָ�����ӿ�, �ڴ�����������趨
//
class IInsertInstruction {
public:
  virtual void push(Runnable* pr) {
    auto sp = std::shared_ptr<Runnable>(pr);
    push(sp);
  }
  //
  // ����һ��ָ�ָ������
  //
  virtual void push(std::shared_ptr<Runnable>&) = 0;
  virtual ~IInsertInstruction() {};
};


//
// ָ���
//
class InstructionSet : private Noncopy, public IInsertInstruction {
private:
  std::vector<std::shared_ptr<Runnable>> arr;
  size_t p;
  size_t _size;
  RefContext currContext;

public:
  enum FailCode {
    // �ɹ�ִ��
    success = 0,
    // û�и���ָ��
    noMore,
    // �д���
    hasErr,
  };
  InstructionSet();
  //
  // ����ָ������
  //
  size_t size();
  //
  // ָ��ָ��ָ��Ҫִ�е�ָ���λ��
  //
  size_t pc();
  // 
  // ����ָ��iΪ��һ��Ҫִ�е�ָ��, ����ִ��
  //
  void Goto(size_t i);
  //
  // ִ����һ��ָ��, ����ָ��ִ��״̬, 
  // ��Ӧ���ڳ�������, �����ֲ���Ԥ�ϵĺ��
  //
  FailCode next();
  void push(std::shared_ptr<Runnable> &) override;
  //
  // ��ָ���������д���һ���������Ĳ�����.
  //
  RefContext newContext(RefContext& parentCtx);
  //
  // �õ�ǰ�����Ĵ���һ���������Ĳ�����.
  //
  RefContext newContext();
  //
  // ���õ�ǰ������
  //
  void setCurrContext(RefContext& c);
};


//
// ��ǰ�����������
// TODO: ÿ�ν���/����/�� ��Ҫ���������ĵ�ʵ��, �ڶ��߳����ж�����ʵ��
//
class JSContext : public JSObject {
private:
  std::shared_ptr<JSContext> parent;
  std::list<std::shared_ptr<JSContext>> childs;
  // ��������/�߼�����ı�����ջ
  std::vector<RefVar> calcStack;
  bool isFunctionCtx;

public:
  JSContext(std::shared_ptr<JSContext>& _parent, bool isFunc = false);
  JSContext(bool isFunc = false);
  //
  // ���Ӷ��ӽڵ������ĵ�����
  //
  void add(std::shared_ptr<JSContext>& child);
  std::shared_ptr<JSContext>& getParent();

  //
  // ���غ���������, ����������򸸼�, �Ҳ�����������.
  // ��Ҫ�Է��صĶ������ڴ����
  //
  JSContext* getFunctionContext();
  //
  // �Ӽ����ջ�е�������
  //
  RefVar popCalc();
  //
  // �ѱ���ѹ������ջ
  //
  void pushCalc(RefVar& v);
  //
  // ���ض� v �����ö���
  //
  RefVar pushCalc(Var* v);

  void printCalcStack();
};



//
// ����/����/���̵ĳ���ӿ�
//
class Runnable : private Noncopy {
protected:
  long lineNum = -1;

public:
  //
  // ִ�е�ǰָ��
  //
  virtual void operator()(RefContext& ctx, InstructionSet* ins) = 0;
  //
  // ִ��֮�����, �д��󷵻� true
  //
  virtual bool hasErr() { return false; }
  //
  // ��ǰָ����Դ�����е��к�
  //
  long line() { return lineNum; }
};


//
// һ����ʼ�ű���������Ϊһ�����̶���
//
class Process : public IInsertInstruction {
private:
  InstructionSet instruct;
  RefContext rootContext;
  bool pauseFlag;
  size_t id;

public:
  Process();
  Process(RefContext& rootContext);
  //
  // ��ʼִ�д���, ��ָ�����Ĳ���
  //
  void run();
  //
  // ��ִͣ�н���, �÷�������һ���߳��е���
  // run Ӧ�ù���, ������, ���ͷ�ϵͳ�߳�.
  //
  void pause();
  //
  // �������������, �⽫���һ�����ڴ�
  //
  void parseEnd();
  //
  // ���ظ��ڵ�������
  //
  RefContext getRootContext();

  void push(std::shared_ptr<Runnable>&);

private:
  friend Manager;
};


//
// һ������ͨ��ֻ��Ҫһ��������, ��������������һ������, 
// ��Ϊ��������̺߳��ڴ���Դ;
//
class Manager {
private:
  std::vector<std::shared_ptr<Process>> parr;

public:
  Manager(Manager const&) = delete;
  Manager();
  //
  // �ѽ��̼��������, �Ժ󽫱�����, ��Ҫ���ⲿ�� pro ���ڴ����
  //
  void add(Process *pro);
  //
  // ��������, ֱ�����н��̶��˳�, �÷����ŷ���
  //
  void start();
};

}

