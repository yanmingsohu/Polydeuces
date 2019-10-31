#include "javascript.h"
#include <iostream>

using namespace PolydeucesEngine;


///// JSObject* ///////////////////////////////////////////////66

JSObject::JSObject() {}


std::string JSObject::toString() {
  return std::string("[object Object]");
}


bool JSNull::isNull() { 
  return true; 
}

void JSNull::appendString(std::stringstream& out) {
  out << "null";
}

std::string JSNull::toString() {
  return std::string("null");
}

bool JSNull::isNumber() {
  return true;
}


bool JSUndefined::isUndefined() {
  return true;
}

void JSUndefined::appendString(std::stringstream& out) {
  out << "undefined";
}

std::string JSUndefined::toString() {
  return std::string("undefined");
}


bool JSNaN::isNaN() {
  return true;
}

void JSNaN::appendString(std::stringstream& out) {
  out << "NaN";
}

std::string JSNaN::toString() {
  return std::string("NaN");
}


///// JSError /////////////////////////////////////////////////66

JSError::JSError(std::string _msg, int _code) : msg(_msg), code(_code) {
}


std::string JSError::toString() {
  std::stringstream buf;
  appendString(buf);
  return buf.str();
}


void JSError::appendString(std::stringstream& out) {
  out << "Error:";
}


///// JSNumber ////////////////////////////////////////////////66

JSNumber::JSNumber(double n) : num(n) {}


bool JSNumber::isNumber() {
  return true;
}


void JSNumber::appendString(std::stringstream& out) {
  out << num;
}


std::string JSNumber::toString() {
  return std::to_string(num);
}


double JSNumber::toNumber() {
  return num;
}


bool JSNumber::toBoolean() {
  return num != 0;
}


///// JSContext ///////////////////////////////////////////////66

JSContext::JSContext(std::shared_ptr<JSContext>& _parent, bool isFunc) 
: parent(_parent), isFunctionCtx(isFunc), hasErrFlag(false) {
}


JSContext::JSContext(bool isFunc) 
: parent(0), isFunctionCtx(isFunc), hasErrFlag(false) {}


void JSContext::add(std::shared_ptr<JSContext>& child) {
  childs.push_back(child);
}


std::shared_ptr<JSContext>& JSContext::getParent() {
  return parent;
}


JSContext* JSContext::getFunctionContext() {
  if (isFunctionCtx) {
    return this;
  }

  RefContext ctx = parent;
  while (ctx.get()) {
    if (ctx->isFunctionCtx) {
      return ctx.get();
    }
    ctx = ctx->parent;
  }
  return this;
}


RefVar JSContext::popCalc() {
  if (calcStack.size() > 0) {
    auto v = calcStack.back();
    calcStack.pop_back();
    return v;
  } else {
    return Ref<Var>(new JSUndefined());
  }
}


void JSContext::pushCalc(RefVar& v) {
  calcStack.push_back(v);
}


RefVar JSContext::pushCalc(Var* v) {
  RefVar rv(v);
  pushCalc(rv);
  return rv;
}


void JSContext::printCalcStack() {
  std::cout << "CALC:: ";
  for (auto i = calcStack.begin(); i < calcStack.end(); ++i) {
    std::cout << (*i)->toString() << ", ";
  }
  std::cout << "\n";
}


void JSContext::setError(Ref<JSError> err) {
  error = err;
  hasErrFlag = true;
}


Ref<JSError> JSContext::getError() {
  return error;
}