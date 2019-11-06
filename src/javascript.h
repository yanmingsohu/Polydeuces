#pragma once

#include <algorithm>
#include <vector>
#include <memory>
#include <list>
#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <exception>

namespace PolydeucesEngine {

#define Ref std::shared_ptr
// ���������������� javascript �쳣, 
// ���÷�����, Ӧ�ü���Ƿ��� js �쳣, ����������.
#define THROW_JAVASCRIPT_ERROR

class Manager;
class IManagerListener;
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
class JSRuntimeException;
class LogicBlock;
class VirtualCPU;
template<class D> class Runnable;

typedef Ref<JSContext>        RefContext;
typedef Ref<JSObject>         RefObj;
typedef Ref<Var>              RefVar;
typedef Ref<Process>          RefProcess;
typedef Runnable<VirtualCPU*> Microinstruction;


enum JavaScriptTypeId {
  t_unknow=0, t_null, t_nan, t_undefined, t_number, t_boolean,
  t_array, t_object, t_string,
};


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
  // ת��Ϊ����, Ĭ�Ϸ��� 0, ����/�߼��������ø÷���, ��ʹ isNumber ���� 0
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
  // ���������� object ������ŷ��� true
  virtual bool isObject()    { return false; }
  virtual bool isSymbol()    { return false; }
  //
  // �ǶԱ���������
  //
  virtual bool isIdentifier(){ return false; }
  virtual JavaScriptTypeId typeID() = 0;
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
  bool isObject();
  JavaScriptTypeId typeID() override;
  bool toBoolean() override;

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
  JavaScriptTypeId typeID() override;
};


class JSUndefined : public Var {
public:
  bool isUndefined() override;
  void appendString(std::stringstream&) override;
  std::string toString() override;
  JavaScriptTypeId typeID() override;
};


class JSNaN : public Var {
public:
  bool isNaN() override;
  void appendString(std::stringstream&) override;
  std::string toString() override;
  JavaScriptTypeId typeID() override;
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
  JavaScriptTypeId typeID() override;
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
  JavaScriptTypeId typeID() override;
  bool toBoolean() override;
};


class JSBoolean : public Var {
private:
  bool b;
public:
  JSBoolean(bool);
  std::string toString() override;
  void appendString(std::stringstream&) override;
  double toNumber() override;
  JavaScriptTypeId typeID() override;
  bool toBoolean() override;
};


class JSIdentifier : public JSString {
public:
  JSIdentifier(std::string s);
  bool isIdentifier() override;
  bool isString() override { return false; }
};


class JSArray : public JSObject {
private:
  std::vector<RefVar> elem;
public:
  bool isArray() override;
  std::string toString() override;
  void appendString(std::stringstream&) override;
  JavaScriptTypeId typeID() override;
  bool toBoolean() override;
};


//
// �������ʱ�Ѿ������쳣״̬, �������л��׳��� c++ �쳣.
// Ӧ�ñ�֤���׳�����쳣, Ҳ��Ӧ��ʹ������������������̿���.
//
class JSRuntimeException : public std::runtime_error {
public:
  JSRuntimeException(const std::string& what) : std::runtime_error(what) {}
  JSRuntimeException(const char* what) : std::runtime_error(what) {}
  JSRuntimeException(Ref<JSError> err) : std::runtime_error(err->message()) {}
};


//
// ָ�����ӿ�, �ڴ�����������趨
//
class IInsertInstruction {
public:
  virtual ~IInsertInstruction() {};
  //
  // ����һ��ָ�ָ��ϵ����, ֮�������������ʵ�ֵ��������
  //
  virtual void push(Microinstruction* pr) = 0;
  //
  // ����һ��ָ����Ϊָ��ĵ�һ��ָ��
  //
  virtual void push_top(Microinstruction* pr) = 0;
};


//
// �����������cpu, ���Ǹ�����cpu
//
class VirtualCPU : private Noncopy {
public:
  enum FailCode {
    // �ɹ�ִ��
    success = 0,
    // û�и���ָ��
    noMore,
    // �д���
    hasErr,
  };

private:
  std::vector<LogicBlock*> blockStack;
  RefContext currContext;
  InstructionSet& ins;
  size_t p;

public:
  VirtualCPU(InstructionSet&);
  //
  // ָ��ָ��ָ��Ҫִ�е�ָ���λ��(����ʱ��Ч)
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
  // ��ָ���������д���һ���������Ĳ�����; ������ø��������Ĺ�ϵ.
  //
  RefContext newContext(RefContext& parentCtx);
  //
  // �õ�ǰ�����Ĵ���һ���������Ĳ�����; ������ø��������Ĺ�ϵ.
  //
  RefContext newContext();
  //
  // ���õ�ǰ������
  //
  void setCurrContext(RefContext& c);
  RefContext getCurrContext();
};


//
// ָ���
//
class InstructionSet : private Noncopy, public IInsertInstruction {
private:
  typedef std::unique_ptr<Microinstruction> RefInstruction;

  std::vector<RefInstruction> arr;
  size_t _size;

public:
  InstructionSet(); 
  void push_top(Microinstruction* pr) override;
  void push(Microinstruction* pr) override;
  //
  // ����ָ������
  //
  size_t size();
  RefInstruction& operator[](size_t pos);
};


//
// �߼������
// TODO: �߼������Ӧ�ñ������ָ��
//
class LogicBlock {
private:
  VirtualCPU& cpu;
  size_t begin_point;
  size_t end_point;

public:
  LogicBlock(VirtualCPU&);
  virtual ~LogicBlock();
  //
  // ָ��ָ���ƶ��������Ŀ�ʼ��(׼����ʼִ�д����)
  //
  void gotoBegin();
  //
  // ָ��ָ���ƶ�������������(�˳������)
  //
  void gotoEnd();
  //
  // �����ִ�������һ��ָ��, �÷���������, Ĭ��ʲô������
  //
  virtual void onEnd() = 0;
  //
  // �����ĵ�һ��ָ��ִ��֮ǰ������
  //
  virtual void onEnter() = 0;
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
  // �д�����, ��ñ����ǿ�
  Ref<JSError> error;
  // const �����ı����б�
  std::unordered_set<std::string> constVar;
  bool hasErrFlag;
  bool isFunctionCtx;

  // ���Ÿ�����·��һֱѰ���������ڵ�������, ���ص�һ������������, �Ҳ������ؿ�
  JSContext* findContext(std::string& propertyName, bool returnFunctionCtx = false);

  // �������ʱ����д������׳��쳣
  inline void checkStateThrowException();

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
  // ���׳� JSRuntimeException �쳣
  //
  RefVar popCalc();
  //
  // ���� isIdentifier �Ķ��������ν�����
  // ���׳� JSRuntimeException �쳣
  //
  RefVar popCalcOriginal();
  //
  // �ѱ���ѹ������ջ
  // ���׳� JSRuntimeException �쳣
  //
  void pushCalc(RefVar& v);
  //
  // ѹ�����ָ��, ���ض� v �����ö���, ��Ҫ�� Var �����ڴ����
  // ���׳� JSRuntimeException �쳣
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
  // ����ֹ���� const ����; ���׳� JSRuntimeException �쳣
  //
  THROW_JAVASCRIPT_ERROR void setContextProperty(std::string name, RefVar val) ;
  //
  // ����������͸�����������Ѱ��, �Ҳ����� js �쳣ѹ���ջ
  // ���׳� JSRuntimeException �쳣
  //
  THROW_JAVASCRIPT_ERROR RefVar getContextProperty(std::string name);
  //
  // �ڱ��ʽ�������ռ����ջ, 
  // TODO; ʼ�ձ��ֶ�ջû�ж���Ԫ��?
  // ���׳� JSRuntimeException �쳣
  //
  void clearCalcStack();
};


//
// ����/����/���̵ĳ���ӿ�
//
template<class Data>
class Runnable : private Noncopy {
protected:
  long lineNum = -1;

public:
  typedef Data Param;
  //
  // ִ�е�ǰָ��
  //
  virtual void operator()(RefContext& ctx, Data ins) = 0;
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
  VirtualCPU cpu;
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

