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
// 声明这个方法会产生 javascript 异常, 
// 调用方法后, 应该检测是否有 js 异常, 并作出处理.
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
// 原始类型基础, 可以复制, 不支持属性
//
class Var {
public:
  Var() {}
  virtual ~Var() {}

  //
  // 输出字符串到 output, 默认调用 toString(), 应该尽可能重写该方法
  //
  virtual void appendString(std::stringstream& output);
  //
  // 设置属性, 默认什么都不做
  //
  virtual void setProperty(std::string name, RefVar val) {}
  //
  // 属性通过 setProperty 设置过返回 true, 即使设置 null/undefined 也会返回 true
  //
  virtual bool hasProperty(std::string name) { return false; }
  //
  // 读取属性如果属性不存在返回 undefined, 默认返回 undefined
  // 该方法不能判断属性是否通过 setProperty 设置过, 
  //
  virtual RefVar getProperty(std::string name);
  //
  // 转换为字符串, 默认什么都不做
  //
  virtual std::string toString() = 0;
  //
  // 转换为数字, 默认返回 0, 算数/逻辑运算会调用该方法, 即使 isNumber 返回 0
  //
  virtual double toNumber() { return 0; }
  //
  // 转换为 bool, 默认返回 false
  //
  virtual bool toBoolean() { return false; }
  //
  // 如果是 X 返回 true, 默认返回 false
  //
  virtual bool isNumber()    { return false; }
  virtual bool isBool()      { return false; }
  virtual bool isString()    { return false; }
  virtual bool isNull()      { return false; }
  virtual bool isUndefined() { return false; }
  virtual bool isNaN()       { return false; }
  virtual bool isFunction()  { return false; }
  virtual bool isArray()     { return false; }
  // 仅当对象是 object 或子类才返回 true
  virtual bool isObject()    { return false; }
  virtual bool isSymbol()    { return false; }
  //
  // 是对变量的引用
  //
  virtual bool isIdentifier(){ return false; }
  virtual JavaScriptTypeId typeID() = 0;
};


//
// 不可复制不可赋值.
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
// 如果运行时已经处于异常状态, 继续运行会抛出该 c++ 异常.
// 应该保证不抛出这个异常, 也不应该使用这个机制做程序流程控制.
//
class JSRuntimeException : public std::runtime_error {
public:
  JSRuntimeException(const std::string& what) : std::runtime_error(what) {}
  JSRuntimeException(const char* what) : std::runtime_error(what) {}
  JSRuntimeException(Ref<JSError> err) : std::runtime_error(err->message()) {}
};


//
// 指令插入接口, 内存策略由子类设定
//
class IInsertInstruction {
public:
  virtual ~IInsertInstruction() {};
  //
  // 插入一条指令到指令集合的最后, 之后对象生存期由实现的子类控制
  //
  virtual void push(Microinstruction* pr) = 0;
  //
  // 插入一条指令作为指令集的第一条指令
  //
  virtual void push_top(Microinstruction* pr) = 0;
};


//
// 虚拟机的虚拟cpu, 这是个单核cpu
//
class VirtualCPU : private Noncopy {
public:
  enum FailCode {
    // 成功执行
    success = 0,
    // 没有更多指令
    noMore,
    // 有错误
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
  // 指令指针指向将要执行的指令的位置(运行时有效)
  //
  size_t pc();
  // 
  // 设置指令i为下一次要执行的指令, 但不执行
  //
  void Goto(size_t i);
  //
  // 执行下一条指令, 返回指令执行状态, 
  // 不应该在出错后调用, 将出现不可预料的后果
  //
  FailCode next();
  //
  // 在指定上下文中创建一个子上下文并返回; 这会设置父子上下文关系.
  //
  RefContext newContext(RefContext& parentCtx);
  //
  // 用当前上下文创建一个子上下文并返回; 这会设置父子上下文关系.
  //
  RefContext newContext();
  //
  // 设置当前上下文
  //
  void setCurrContext(RefContext& c);
  RefContext getCurrContext();
};


//
// 指令集合
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
  // 返回指令数量
  //
  size_t size();
  RefInstruction& operator[](size_t pos);
};


//
// 逻辑代码块
// TODO: 逻辑代码块应该保存程序指针
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
  // 指令指针移动到代码块的开始处(准备开始执行代码块)
  //
  void gotoBegin();
  //
  // 指令指针移动到代码块结束处(退出代码块)
  //
  void gotoEnd();
  //
  // 代码块执行完最后一条指令, 该方法被调用, 默认什么都不做
  //
  virtual void onEnd() = 0;
  //
  // 代码块的第一条指令执行之前被调用
  //
  virtual void onEnter() = 0;
};


//
// 当前代码段上下文
// TODO: 每次进入/函数/块 都要创建上下文的实例, 在多线程中有独立的实例
//
class JSContext : public JSObject {
private:
  Ref<JSContext> parent;
  std::list<Ref<JSContext>> childs;
  // 用于算数/逻辑计算的变量堆栈
  std::vector<RefVar> calcStack;
  // 有错误发生, 则该变量非空
  Ref<JSError> error;
  // const 声明的变量列表
  std::unordered_set<std::string> constVar;
  bool hasErrFlag;
  bool isFunctionCtx;

  // 沿着父引用路径一直寻找属性所在的上下文, 返回第一个上下文引用, 找不到返回空
  JSContext* findContext(std::string& propertyName, bool returnFunctionCtx = false);

  // 检测运行时如果有错误则抛出异常
  inline void checkStateThrowException();

public:
  JSContext(std::shared_ptr<JSContext>& _parent, bool isFunc = false);
  JSContext(bool isFunc = false);
  //
  // 增加对子节点上下文的引用
  //
  void add(std::shared_ptr<JSContext>& child);
  std::shared_ptr<JSContext>& getParent();

  //
  // 返回函数上下文, 可以是自身或父级, 找不到返回 NULL.
  // 不要对返回的对象做内存管理
  //
  JSContext* getFunctionContext();
  //
  // 从计算堆栈中弹出变量, 如果堆栈为空, 返回 JSUndefined
  // 如果变量是 isIdentifier 的, 则返回 id 引用的变量
  // 会抛出 JSRuntimeException 异常
  //
  RefVar popCalc();
  //
  // 不对 isIdentifier 的对象做二次解引用
  // 会抛出 JSRuntimeException 异常
  //
  RefVar popCalcOriginal();
  //
  // 把变量压入计算堆栈
  // 会抛出 JSRuntimeException 异常
  //
  void pushCalc(RefVar& v);
  //
  // 压入变量指针, 返回对 v 的引用对象, 不要对 Var 进行内存管理
  // 会抛出 JSRuntimeException 异常
  //
  RefVar pushCalc(Var* v);
  //
  // 打印计算堆栈, debug 用
  //
  void printCalcStack();
  //
  // 设置错误
  //
  void setError(Ref<JSError> err);
  void setError(std::string msg);
  //
  // 获取错误
  //
  Ref<JSError> getError();
  //
  // 有错误返回 true
  //
  inline bool hasError() {
    return hasErrFlag;
  }
  //
  // 设置变量为 const
  //
  void setConst(std::string var_name);
  //
  // 寻找正确的上下文保存变量, 若变量从未存在则保存到当前最近的函数上下文.
  // 会阻止设置 const 变量; 会抛出 JSRuntimeException 异常
  //
  THROW_JAVASCRIPT_ERROR void setContextProperty(std::string name, RefVar val) ;
  //
  // 属性在自身和父级上下文中寻找, 找不到则 js 异常压入堆栈
  // 会抛出 JSRuntimeException 异常
  //
  THROW_JAVASCRIPT_ERROR RefVar getContextProperty(std::string name);
  //
  // 在表达式计算后清空计算堆栈, 
  // TODO; 始终保持堆栈没有多余元素?
  // 会抛出 JSRuntimeException 异常
  //
  void clearCalcStack();
};


//
// 函数/任务/进程的抽象接口
//
template<class Data>
class Runnable : private Noncopy {
protected:
  long lineNum = -1;

public:
  typedef Data Param;
  //
  // 执行当前指令
  //
  virtual void operator()(RefContext& ctx, Data ins) = 0;
  //
  // 当前指令在源代码中的行号
  //
  long line() { return lineNum; }
};


//
// 一个初始脚本将被编译为一个进程对象
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
  // 开始执行代码, 或恢复挂起的操作
  //
  RunFlag run();
  //
  // 暂停执行进程, 该方法在另一个线程中调用
  // run 应该挂起, 并返回, 以释放系统线程.
  //
  void pause();
  //
  // 解析器解析完成, 这将清除一部分内存
  //
  void parseEnd();
  //
  // 返回根节点上下文
  //
  RefContext getRootContext();

  size_t getId();
  RefContext getCurrContext();
  IInsertInstruction* getInstructionSet();
};


//
// 监听管理器发出的消息
//
class IManagerListener {
public:
  //
  // 当进程因为错误退出, 调用该方法
  // process 进程指针, 在函数返回后无效
  // err 错误对象
  //
  virtual void stop(Process* process, Ref<JSError> err);
  //
  // 进程正常结束后调用
  // process 进程指针, 在函数返回后无效
  // returnVal 进程的返回值
  //
  virtual void stop(Process* process, RefVar returnVal);
};


//
// 一个进程通常只需要一个管理器, 管理器负责启动一个程序, 
// 并为程序分配线程和内存资源;
//
class Manager : private Noncopy {
private:
  IManagerListener& ml;
  std::vector<std::shared_ptr<Process>> parr;
  size_t id;

public:
  //
  // IManagerListener 的有效期应该超过 Manager
  //
  Manager(IManagerListener&);
  //
  // 把进程加入管理器, 稍后将被启动, 不要在外部对 pro 做内存管理
  //
  void add(Process *pro);
  //
  // 启动任务, 直到所有进程都退出, 该方法才返回
  //
  void start();
  //
  // 生成不重复的 id
  //
  size_t genNextID();
  //
  // 发送错误消息
  //
  void sendError(Process* p, Ref<JSError> err);
};

}

