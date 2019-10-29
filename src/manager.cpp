#include "javascript.h"

using namespace PolydeucesEngine;


///// Manager /////////////////////////////////////////////////66

Manager::Manager() {}


void Manager::add(Process* pro) {
  pro->id = parr.size();
  parr.push_back(std::shared_ptr<Process>(pro));
}


///// Instruction /////////////////////////////////////////////66

Instruction::Instruction() : p(-1), _size(0) {}


size_t Instruction::size() {
  return _size;
}


Instruction::FailCode Instruction::next() {
  if (p+1 >= _size) return FailCode::noMore;
  auto currIns = arr[p+1];
  (*currIns)();
  if (currIns->hasErr()) {
    return FailCode::hasErr;
  }
  return FailCode::success;
}


void Instruction::push(std::shared_ptr<Runnable> &ins) {
  arr.push_back(ins);
  ++_size;
}


///// Process /////////////////////////////////////////////////66

Process::Process() : pauseFlag(false) {
  rootContext.reset(new JSContext());
}


void Process::pause() {
  pauseFlag = true;
}


void Process::parseEnd() {
}


std::shared_ptr<JSContext> Process::getRootContext() {
  return rootContext;
}


std::shared_ptr<JSContext> Process::newContext(std::shared_ptr<JSContext>& parentCtx) {
  std::shared_ptr<JSContext> ctx(new JSContext(parentCtx));
  parentCtx->add(ctx);
  return ctx;
}


void Process::run() {
}