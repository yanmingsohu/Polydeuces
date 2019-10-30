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
// 所有 js 对象的基础, 不可复制不可赋值.
//
class JSObject : private Noncopy {
public:
  JSObject();
};

typedef std::shared_ptr<JSObject> RefObj;


//
// 原始类型基础, 可以复制
//
class Var {
public:
  Var() {}
  virtual ~Var() {}

  // 输出字符串到 output, 默认调用 toString(), 应该尽可能重写该方法
  virtual void appendString(std::stringstream& output) {
    output << toString();
  }

  // 转换为字符串, 默认什么都不做
  virtual std::string toString() = 0;
  // 转换为数字, 默认返回 0
  virtual double toNumber() { return 0; }
  // 转换为 bool, 默认返回 false
  virtual bool toBoolean() { return false; }

  // 如果是 X 返回 true, 默认返回 false
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
  // null 与数字做数学运算时当零使用
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
// 指令插入接口, 内存策略由子类设定
//
class IInsertInstruction {
public:
  virtual void push(Runnable* pr) {
    auto sp = std::shared_ptr<Runnable>(pr);
    push(sp);
  }
  //
  // 插入一条指令到指令的最后
  //
  virtual void push(std::shared_ptr<Runnable>&) = 0;
  virtual ~IInsertInstruction() {};
};


//
// 指令集合
//
class InstructionSet : private Noncopy, public IInsertInstruction {
private:
  std::vector<std::shared_ptr<Runnable>> arr;
  size_t p;
  size_t _size;
  RefContext currContext;

public:
  enum FailCode {
    // 成功执行
    success = 0,
    // 没有更多指令
    noMore,
    // 有错误
    hasErr,
  };
  InstructionSet();
  //
  // 返回指令数量
  //
  size_t size();
  //
  // 指令指针指向将要执行的指令的位置
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
  void push(std::shared_ptr<Runnable> &) override;
  //
  // 在指定上下文中创建一个子上下文并返回.
  //
  RefContext newContext(RefContext& parentCtx);
  //
  // 用当前上下文创建一个子上下文并返回.
  //
  RefContext newContext();
  //
  // 设置当前上下文
  //
  void setCurrContext(RefContext& c);
};


//
// 当前代码段上下文
// TODO: 每次进入/函数/块 都要创建上下文的实例, 在多线程中有独立的实例
//
class JSContext : public JSObject {
private:
  std::shared_ptr<JSContext> parent;
  std::list<std::shared_ptr<JSContext>> childs;
  // 用于算数/逻辑计算的变量堆栈
  std::vector<RefVar> calcStack;
  bool isFunctionCtx;

public:
  JSContext(std::shared_ptr<JSContext>& _parent, bool isFunc = false);
  JSContext(bool isFunc = false);
  //
  // 增加对子节点上下文的引用
  //
  void add(std::shared_ptr<JSContext>& child);
  std::shared_ptr<JSContext>& getParent();

  //
  // 返回函数上下文, 可以是自身或父级, 找不到返回自身.
  // 不要对返回的对象做内存管理
  //
  JSContext* getFunctionContext();
  //
  // 从计算堆栈中弹出变量
  //
  RefVar popCalc();
  //
  // 把变量压入计算堆栈
  //
  void pushCalc(RefVar& v);
  //
  // 返回对 v 的引用对象
  //
  RefVar pushCalc(Var* v);

  void printCalcStack();
};



//
// 函数/任务/进程的抽象接口
//
class Runnable : private Noncopy {
protected:
  long lineNum = -1;

public:
  //
  // 执行当前指令
  //
  virtual void operator()(RefContext& ctx, InstructionSet* ins) = 0;
  //
  // 执行之后调用, 有错误返回 true
  //
  virtual bool hasErr() { return false; }
  //
  // 当前指令在源代码中的行号
  //
  long line() { return lineNum; }
};


//
// 一个初始脚本将被编译为一个进程对象
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
  // 开始执行代码, 或恢复挂起的操作
  //
  void run();
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

  void push(std::shared_ptr<Runnable>&);

private:
  friend Manager;
};


//
// 一个进程通常只需要一个管理器, 管理器负责启动一个程序, 
// 并为程序分配线程和内存资源;
//
class Manager {
private:
  std::vector<std::shared_ptr<Process>> parr;

public:
  Manager(Manager const&) = delete;
  Manager();
  //
  // 把进程加入管理器, 稍后将被启动, 不要在外部对 pro 做内存管理
  //
  void add(Process *pro);
  //
  // 启动任务, 直到所有进程都退出, 该方法才返回
  //
  void start();
};

}

