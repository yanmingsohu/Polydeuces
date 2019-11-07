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


ProcessID Manager::genNextID() {
  return ++id;
}


void Manager::sendError(Process* p, Ref<JSError> err) {
  ml.stop(p, err);
}


///// Instruction /////////////////////////////////////////////66

InstructionSet::InstructionSet() : _size(0) {}


InstructPos InstructionSet::size() {
  return _size;
}


void InstructionSet::push(Microinstruction* r) {
  RefInstruction ref(r);
  arr.push_back(std::move(ref));
  ++_size;
}


void InstructionSet::push_top(Microinstruction* r) {
  RefInstruction ref(r);
  arr.insert(arr.begin(), std::move(ref));
  ++_size;
}


InstructionSet::RefInstruction& InstructionSet::operator[](InstructPos pos) {
  return arr[pos];
}


///// VirtualCPU //////////////////////////////////////////////66

VirtualCPU::VirtualCPU(InstructionSet& _i) : ins(_i) {}


void VirtualCPU::Goto(InstructPos i) {
  if (i >= ins.size()) throw JSRuntimeException("outof code address");
  p = i - 1;
}


InstructPos VirtualCPU::pc() {
  return p + 1;
}


void VirtualCPU::setCurrContext(RefContext& c) {
  currContext = c;
}


RefContext VirtualCPU::getCurrContext() {
  return currContext;
}


std::shared_ptr<JSContext> VirtualCPU::newContext(RefContext& parentCtx) {
  std::shared_ptr<JSContext> ctx(new JSContext(parentCtx));
  parentCtx->add(ctx);
  return ctx;
}


std::shared_ptr<JSContext> VirtualCPU::newContext() {
  return newContext(currContext);
}


VirtualCPU::FailCode VirtualCPU::next() {
  if (p + 1 >= ins.size())
    return FailCode::noMore;

  auto currIns = ins[p + 1].get();
  (*currIns)(currContext, this);
  if (currContext->hasError()) {
    return FailCode::hasErr;
  }
  ++p;
  return FailCode::success;
}


InstructPos VirtualCPU::currentLength() {
  return ins.size();
}


///// Process /////////////////////////////////////////////////66

Process::Process(ProcessID _id)
: runFlag(RunFlag::paused), id(_id), cpu(instruct) 
{
  rootContext.reset(new JSContext(true));
}


Process::Process(RefContext& _rootContext, ProcessID _id)
: runFlag(RunFlag::paused), rootContext(_rootContext), id(_id), cpu(instruct) {
}


void Process::pause() {
  if (runFlag == RunFlag::running) {
    runFlag = RunFlag::paused;
  }
}


ProcessID Process::getId() {
  return id;
}


void Process::parseEnd() {
  cpu.setCurrContext(rootContext);
}


std::shared_ptr<JSContext> Process::getRootContext() {
  return rootContext;
}



RefContext Process::getCurrContext() {
  return cpu.getCurrContext();
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
    auto state = cpu.next();
    switch (state) {
      case VirtualCPU::noMore:
        runFlag = RunFlag::end;
        break;
      case VirtualCPU::hasErr:
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


///// ControlBlock ////////////////////////////////////////////66

ControlBlock::ControlBlock(VirtualCPU& _cpu) : cpu(_cpu), begin_point(-1), end_point(-1) {
}


ControlBlock::~ControlBlock() {}


void ControlBlock::gotoEnd() {
  cpu.Goto(end_point);
}


void ControlBlock::gotoBegin() {
  cpu.Goto(begin_point);
}


void ControlBlock::setCurrentPosEnd() {
  if (end_point >= 0) throw JSRuntimeException("can't set end pos second");
  end_point = cpu.currentLength();
}