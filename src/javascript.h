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
// ���� js ����Ļ���, ���ɸ��Ʋ��ɸ�ֵ.
//
class JSObject : private Noncopy {
public:
  JSObject();
};


typedef std::shared_ptr<JSObject> ObjRef;


//
// ��ǰ�����������
// TODO: ÿ�ν���/����/�� ��Ҫ���������ĵ�ʵ��, �ڶ��߳����ж�����ʵ��
//
class JSContext : public JSObject {
private:
  std::shared_ptr<JSContext> parent;
  std::list<std::shared_ptr<JSContext>> childs;

public:
  JSContext(std::shared_ptr<JSContext>& _parent);
  JSContext();
  //
  // ���Ӷ��ӽڵ������ĵ�����
  //
  void add(std::shared_ptr<JSContext>& child);
  std::shared_ptr<JSContext>& getParent();
};


//
// ����/����/���̵ĳ���ӿ�
//
class Runnable : public JSObject {
protected:
  long lineNum = -1;

public:
  //
  // ִ�е�ǰָ��
  //
  virtual void operator()() = 0;
  //
  // ִ��֮�����, �д��󷵻� true
  //
  virtual bool hasErr() = 0;
  //
  // ��ǰָ����Դ�����е��к�
  //
  virtual long line() = 0;
};


//
// ָ���
//
class Instruction : private Noncopy {
private:
  std::vector<std::shared_ptr<Runnable>> arr;
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
  Instruction();
  //
  // ����ָ������
  //
  size_t size();
  //
  // ִ����һ��ָ��, ����ָ��ִ��״̬, 
  // ��Ӧ���ڳ�������, �����ֲ���Ԥ�ϵĺ��
  //
  FailCode next();
  //
  // ����һ��ָ�ָ������
  //
  void push(std::shared_ptr<Runnable> &);
};


//
// һ����ʼ�ű���������Ϊһ�����̶���
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
  // ��ָ���������д���һ���������Ĳ�����.
  //
  std::shared_ptr<JSContext> newContext(std::shared_ptr<JSContext>& parent);
  //
  // ���ظ��ڵ�������
  //
  std::shared_ptr<JSContext> getRootContext();

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
};

}

