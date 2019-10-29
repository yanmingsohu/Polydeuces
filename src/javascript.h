#pragma once

#include <algorithm>
#include <vector>
#include <memory>
#include <list>

namespace PolydeucesEngine {

class Manager;
class Runnable;
class instruction;
class Process;
class Noncopy;
class JSObject;
class JSContext;


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


typedef std::shared_ptr<JSObject> ObjRef;


//
// 当前代码段上下文
// TODO: 每次进入/函数/块 都要创建上下文的实例, 在多线程中有独立的实例
//
class JSContext : public JSObject {
private:
  std::shared_ptr<JSContext> parent;
  std::list<std::shared_ptr<JSContext>> childs;

public:
  JSContext(std::shared_ptr<JSContext>& _parent);
  JSContext();
  //
  // 增加对子节点上下文的引用
  //
  void add(std::shared_ptr<JSContext>& child);
  std::shared_ptr<JSContext>& getParent();
};


//
// 函数/任务/进程的抽象接口
//
class Runnable : public JSObject {
protected:
  long lineNum = -1;

public:
  //
  // 执行当前指令
  //
  virtual void operator()() = 0;
  //
  // 执行之后调用, 有错误返回 true
  //
  virtual bool hasErr() = 0;
  //
  // 当前指令在源代码中的行号
  //
  virtual long line() = 0;
};


//
// 指令集合
//
class Instruction : private Noncopy {
private:
  std::vector<std::shared_ptr<Runnable>> arr;
  size_t p;
  size_t _size;

public:
  enum FailCode {
    // 成功执行
    success = 0,
    // 没有更多指令
    noMore,
    // 有错误
    hasErr,
  };
  Instruction();
  //
  // 返回指令数量
  //
  size_t size();
  //
  // 执行下一条指令, 返回指令执行状态, 
  // 不应该在出错后调用, 将出现不可预料的后果
  //
  FailCode next();
  //
  // 插入一条指令到指令的最后
  //
  void push(std::shared_ptr<Runnable> &);
};


//
// 一个初始脚本将被编译为一个进程对象
//
class Process {
private:
  Instruction instruct;
  std::shared_ptr<JSContext> rootContext;
  bool pauseFlag;
  size_t id;

public:
  Process();
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
  // 在指定上下文中创建一个子上下文并返回.
  //
  std::shared_ptr<JSContext> newContext(std::shared_ptr<JSContext>& parent);
  //
  // 返回根节点上下文
  //
  std::shared_ptr<JSContext> getRootContext();

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
};

}

