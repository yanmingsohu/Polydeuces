#include "javascript.h"
#include <iostream>

using namespace PolydeucesEngine;


///// Manager /////////////////////////////////////////////////66

Manager::Manager(IManagerListener& _ml) : id(0), ml(_ml) {}


void Manager::add(Process* pro) {
  parr.push_back(std::shared_ptr<Process>(pro));
}


//
// TODO: 进程管理
//
void Manager::start() {
  for (auto i = parr.begin(); i != parr.end(); ++i) {
    auto process = (*i);

    switch (process->run()) {
      case Process::RunFlag::error:
        ml.stop(&*process, process->getCurrContext()->getError());
        break;

      case Process::RunFlag::end:
        ml.stop(&*process, process->getCurrContext()->popCalc());
        break;
    }
  }
}


size_t Manager::genNextID() {
  return ++id;
}


void Manager::sendError(Process* p, Ref<JSError> err) {
  ml.stop(p, err);
}


///// Instruction /////////////////////////////////////////////66

InstructionSet::InstructionSet() : p(-1), _size(0) {}


size_t InstructionSet::size() {
  return _size;
}


InstructionSet::FailCode InstructionSet::next() {
  if (p+1 >= _size) 
    return FailCode::noMore;

  auto currIns = arr[p+1].get();
  (*currIns)(currContext, this);
  if (currContext->hasError()) {
    return FailCode::hasErr;
  }
  ++p;
  return FailCode::success;
}


void InstructionSet::push(Runnable* r) {
  RefInstruction ref(r);
  arr.push_back(std::move(ref));
  ++_size;
}


void InstructionSet::push_top(Runnable* r) {
  RefInstruction ref(r);
  arr.insert(arr.begin(), std::move(ref));
  ++_size;
}


void InstructionSet::Goto(size_t i) {
  if (i >= _size) throw JSRuntimeException("outof code address");
  p = i-1;
}


size_t InstructionSet::pc() {
  return p+1;
}


void InstructionSet::setCurrContext(RefContext& c) {
  currContext = c;
}


RefContext InstructionSet::getCurrContext() {
  return currContext;
}


std::shared_ptr<JSContext> InstructionSet::newContext(RefContext& parentCtx) {
  std::shared_ptr<JSContext> ctx(new JSContext(parentCtx));
  parentCtx->add(ctx);
  return ctx;
}


std::shared_ptr<JSContext> InstructionSet::newContext() {
  return newContext(currContext);
}


///// Process /////////////////////////////////////////////////66

Process::Process(size_t _id) : runFlag(RunFlag::paused), id(_id) {
  rootContext.reset(new JSContext(true));
}


Process::Process(std::shared_ptr<JSContext>& _rootContext, size_t _id)
: runFlag(RunFlag::paused), rootContext(_rootContext), id(_id) {
}


void Process::pause() {
  if (runFlag == RunFlag::running) {
    runFlag = RunFlag::paused;
  }
}


size_t Process::getId() {
  return id;
}


void Process::parseEnd() {
  instruct.setCurrContext(rootContext);
}


std::shared_ptr<JSContext> Process::getRootContext() {
  return rootContext;
}



RefContext Process::getCurrContext() {
  return instruct.getCurrContext();
}


IInsertInstruction* Process::getInstructionSet() {
  return &instruct;
}


Process::RunFlag Process::run() {
  switch (runFlag) {
    case RunFlag::paused:
      runFlag = RunFlag::running;
      break;

    case RunFlag::running:
    case RunFlag::end:
    case RunFlag::error:
    default:
      return runFlag;
  }

  do {
    auto state = instruct.next();
    switch (state) {
      case InstructionSet::noMore:
        runFlag = RunFlag::end;
        break;
      case InstructionSet::hasErr:
        runFlag = RunFlag::error;
        break;
    }
  } while (runFlag == RunFlag::running);

  return runFlag;
}


///// IManagerListener ////////////////////////////////////////66

void IManagerListener::stop(Process* process, Ref<JSError> err) {
  std::cout << "Process Abort ID:" << process->getId() << "\n"
            << err->message() << std::endl;
}


void IManagerListener::stop(Process* process, RefVar returnVal) {
  std::cout << "Process Exit ID:" << process->getId() << "\n\tReturn: "
            << returnVal->toString() << std::endl;
  process->getRootContext()->printAllProps();
}


///// LogicBlock //////////////////////////////////////////////66

LogicBlock::LogicBlock(InstructionSet& _is) : is(_is), begin_point(_is.size()){
}


LogicBlock::~LogicBlock() {}


void LogicBlock::gotoEnd() {
  is.Goto(end_point);
}


void LogicBlock::gotoBegin() {
  is.Goto(begin_point);
}


void LogicBlock::onEnd() {
}