#pragma once

#include <algorithm>
#include <vector>
#include <memory>
#include <list>
#include <string>
#include <sstream>

namespace PolydeucesEngine {

#define Ref std::shared_ptr

class Manager;
class IManagerListener;
class Runnable;
class InstructionSet;
class IInsertInstruction;
class Process;
class Noncopy;
class Var;
class JSObject;
class JSContext;
class JSNull;
class JSUndefined;
class JSNaN;
class JSNumber;
class JSError;
class JSBoolean;
typedef Ref<JSContext>  RefContext;
typedef Ref<JSObject>   RefObj;
typedef Ref<Var>        RefVar;
typedef Ref<Process>    RefProcess;


class Noncopy {
public:
  Noncopy() {};
  virtual ~Noncopy() {};

private:
  Noncopy(Noncopy const&) = delete;
  Noncopy operator=(const Noncopy&) = delete;
};


//
// ԭʼ���ͻ���, ���Ը���, ��֧������
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


//
// ���ɸ��Ʋ��ɸ�ֵ.
//
class JSObject : private Noncopy, public Var {
public:
  JSObject();
  std::string toString() override;
};


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


class JSError : public JSObject {
private:
  std::string stack;
  std::string msg;
  int code;

public:
  JSError(std::string msg, int code = 0);
  std::string toString() override;
  void appendString(std::stringstream&) override;
  bool isString() override;
};


class JSString : public JSObject {
private:
  std::string str;
public:
  JSString(std::string str);
  std::string toString() override;
  void appendString(std::stringstream&) override;
  bool isString() override;
};


class JSBoolean : public Var {
private:
  bool b;
public:
  JSBoolean(bool);
  std::string toString() override;
  void appendString(std::stringstream&) override;
};


//
// ָ�����ӿ�, �ڴ�����������趨
//
class IInsertInstruction {
public:
  //
  // ����һ��ָ�ָ��ϵ����, ֮�������������ʵ�ֵ��������
  //
  virtual void push(Runnable* pr) = 0;
  virtual ~IInsertInstruction() {};
};


//
// ָ���
//
class InstructionSet : private Noncopy, public IInsertInstruction {
private:
  typedef std::unique_ptr<Runnable> RefInstruction;

  std::vector<RefInstruction> arr;
  RefContext currContext;
  size_t p;
  size_t _size;

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

  virtual void push(Runnable* pr) override;
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
  Ref<JSContext> parent;
  std::list<Ref<JSContext>> childs;
  // ��������/�߼�����ı�����ջ
  std::vector<RefVar> calcStack;
  bool isFunctionCtx;
  // �д�����, ��ñ����ǿ�
  Ref<JSError> error;
  bool hasErrFlag;

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
  // �Ӽ����ջ�е�������, �����ջΪ��, ���� JSUndefined
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
  //
  // ��ӡ�����ջ, debug ��
  //
  void printCalcStack();
  //
  // ���ô���
  //
  void setError(Ref<JSError> err);
  //
  // ��ȡ����
  //
  Ref<JSError> getError();
  //
  // �д��󷵻� true
  //
  inline bool hasError() {
    return hasErrFlag;
  }
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
  // ��ǰָ����Դ�����е��к�
  //
  long line() { return lineNum; }
};


//
// һ����ʼ�ű���������Ϊһ�����̶���
//
class Process : public IInsertInstruction, private Noncopy {
public:
  enum RunFlag {
    paused, running, error, end,
  };

private:
  RunFlag runFlag;
  InstructionSet instruct;
  RefContext rootContext;
  size_t id;

public:
  Process(size_t id);
  Process(RefContext& rootContext, size_t id);
  //
  // ��ʼִ�д���, ��ָ�����Ĳ���
  //
  RunFlag run();
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

  void push(Runnable*);

  size_t getId();
};


//
// ������������������Ϣ
//
class IManagerListener {
public:
  //
  // ��������Ϊ�����˳�, ���ø÷���
  // process ����ָ��, �ں������غ���Ч
  // err �������
  //
  virtual void stop(Process* process, Ref<JSError> err);
  //
  // �����������������
  // process ����ָ��, �ں������غ���Ч
  // returnVal ���̵ķ���ֵ
  //
  virtual void stop(Process* process, RefVar returnVal);
};


//
// һ������ͨ��ֻ��Ҫһ��������, ��������������һ������, 
// ��Ϊ��������̺߳��ڴ���Դ;
//
class Manager : private Noncopy {
private:
  IManagerListener& ml;
  std::vector<std::shared_ptr<Process>> parr;
  size_t id;

public:
  //
  // IManagerListener ����Ч��Ӧ�ó��� Manager
  //
  Manager(IManagerListener&);
  //
  // �ѽ��̼��������, �Ժ󽫱�����, ��Ҫ���ⲿ�� pro ���ڴ����
  //
  void add(Process *pro);
  //
  // ��������, ֱ�����н��̶��˳�, �÷����ŷ���
  //
  void start();
  //
  // ���ɲ��ظ��� id
  //
  size_t genNextID();
  //
  // ���ʹ�����Ϣ
  //
  void sendError(Process* p, Ref<JSError> err);
};

}

