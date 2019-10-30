#include "javascript.h"

using namespace PolydeucesEngine;


///// Manager /////////////////////////////////////////////////66

Manager::Manager() {}


void Manager::add(Process* pro) {
  pro->id = parr.size();
  parr.push_back(std::shared_ptr<Process>(pro));
}


void Manager::start() {
  for (auto i = parr.begin(); i != parr.end(); ++i) {
    (*i)->run();
  }
}


///// Instruction /////////////////////////////////////////////66

InstructionSet::InstructionSet() : p(-1), _size(0) {}


size_t InstructionSet::size() {
  return _size;
}


InstructionSet::FailCode InstructionSet::next() {
  if (p+1 >= _size) return FailCode::noMore;
  auto currIns = arr[p+1];
  (*currIns)(currContext, this);
  if (currIns->hasErr()) {
    return FailCode::hasErr;
  }
  ++p;
  return FailCode::success;
}


void InstructionSet::push(std::shared_ptr<Runnable> &ins) {
  arr.push_back(ins);
  ++_size;
}


void InstructionSet::Goto(size_t i) {
  p = i-1;
}


size_t InstructionSet::pc() {
  return p+1;
}


void InstructionSet::setCurrContext(RefContext& c) {
  currContext = c;
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

Process::Process() : pauseFlag(false) {
  rootContext.reset(new JSContext());
}


Process::Process(std::shared_ptr<JSContext>& _rootContext) 
: pauseFlag(false), rootContext(_rootContext) {
}


void Process::pause() {
  pauseFlag = true;
}


void Process::parseEnd() {
  instruct.setCurrContext(rootContext);
}


std::shared_ptr<JSContext> Process::getRootContext() {
  return rootContext;
}


void Process::push(std::shared_ptr<Runnable>& r) {
  instruct.push(r);
}


void Process::run() {
  while (!pauseFlag) {
    auto state = instruct.next();
    switch (state) {
      case InstructionSet::noMore:
        return;
      case InstructionSet::hasErr:
        return;
    }
  }
}

