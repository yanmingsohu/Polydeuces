#pragma once

#include <algorithm>
#include <vector>
#include <memory>
#include <list>
#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

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

  //
  // ����ַ����� output, Ĭ�ϵ��� toString(), Ӧ�þ�������д�÷���
  //
  virtual void appendString(std::stringstream& output);
  //
  // ��������, Ĭ��ʲô������
  //
  virtual void setProperty(std::string name, RefVar val) {}
  //
  // ����ͨ�� setProperty ���ù����� true, ��ʹ���� null/undefined Ҳ�᷵�� true
  //
  virtual bool hasProperty(std::string name) { return false; }
  //
  // ��ȡ����������Բ����ڷ��� undefined, Ĭ�Ϸ��� undefined
  // �÷��������ж������Ƿ�ͨ�� setProperty ���ù�, 
  //
  virtual RefVar getProperty(std::string name);
  //
  // ת��Ϊ�ַ���, Ĭ��ʲô������
  //
  virtual std::string toString() = 0;
  //
  // ת��Ϊ����, Ĭ�Ϸ��� 0
  //
  virtual double toNumber() { return 0; }
  //
  // ת��Ϊ bool, Ĭ�Ϸ��� false
  //
  virtual bool toBoolean() { return false; }
  //
  // ����� X ���� true, Ĭ�Ϸ��� false
  //
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
  //
  // �ǶԱ���������
  //
  virtual bool isIdentifier(){ return false; }
};


//
// ���ɸ��Ʋ��ɸ�ֵ.
//
class JSObject : private Noncopy, public Var {
public:
  typedef std::unordered_map<std::string, RefVar> Properties;

  JSObject();
  std::string toString() override;
  void setProperty(std::string name, RefVar val) override;
  bool hasProperty(std::string name) override;
  RefVar getProperty(std::string name) override;
  void printAllProps();

private:
  Properties properties;

protected:
  Properties& propertiesRef();
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
  //std::string stack;
  std::string msg;
  int code;

public:
  JSError(std::string msg, int code = 0);
  std::string toString() override;
  void appendString(std::stringstream&) override;
  bool isString() override;
  std::string message();
};


class JSString : public JSObject {
protected:
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


class JSIdentifier : public JSString {
public:
  JSIdentifier(std::string s);
  bool isIdentifier() override;
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
  //
  // ����һ��ָ����Ϊָ��ĵ�һ��ָ��
  //
  virtual void push_top(Runnable* pr) = 0;
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
  void push_top(Runnable* pr) override;
  void push(Runnable* pr) override;
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
  RefContext getCurrContext();
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
  std::unordered_set<std::string> constVar;

  // ���Ÿ�����·��һֱѰ���������ڵ�������, ���ص�һ������������, �Ҳ������ؿ�
  JSContext* findContext(std::string& propertyName, bool returnFunctionCtx = false);

public:
  JSContext(std::shared_ptr<JSContext>& _parent, bool isFunc = false);
  JSContext(bool isFunc = false);
  //
  // ���Ӷ��ӽڵ������ĵ�����
  //
  void add(std::shared_ptr<JSContext>& child);
  std::shared_ptr<JSContext>& getParent();

  //
  // ���غ���������, ����������򸸼�, �Ҳ������� NULL.
  // ��Ҫ�Է��صĶ������ڴ����
  //
  JSContext* getFunctionContext();
  //
  // �Ӽ����ջ�е�������, �����ջΪ��, ���� JSUndefined
  // ��������� isIdentifier ��, �򷵻� id ���õı���
  //
  RefVar popCalc();
  //
  // ���� isIdentifier �Ķ��������ν�����
  //
  RefVar popCalcOriginal();
  //
  // �ѱ���ѹ������ջ
  //
  void pushCalc(RefVar& v);
  //
  // ѹ�����ָ��, ���ض� v �����ö���, ��Ҫ�� Var �����ڴ����
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
  void setError(std::string msg);
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
  //
  // ���ñ���Ϊ const
  //
  void setConst(std::string var_name);
  //
  // Ѱ����ȷ�������ı������, ��������δ�����򱣴浽��ǰ����ĺ���������.
  // ����ֹ���� const ����
  //
  void setContextProperty(std::string name, RefVar val);
  //
  // ����������͸�����������Ѱ��, �Ҳ����� js �쳣ѹ���ջ
  //
  RefVar getContextProperty(std::string name);
  //
  // �ڱ��ʽ�������ռ����ջ, 
  // TODO; ʼ�ձ��ֶ�ջû�ж���Ԫ��?
  //
  void clearCalcStack();
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
class Process : private Noncopy {
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

  size_t getId();
  RefContext getCurrContext();
  IInsertInstruction* getInstructionSet();
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

