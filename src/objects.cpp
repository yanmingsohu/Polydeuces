#include "javascript.h"
#include <iostream>

using namespace PolydeucesEngine;


///// Var /////////////////////////////////////////////////////66

void Var::appendString(std::stringstream& output) {
  output << toString();
}


RefVar Var::getProperty(std::string name) { 
  return RefVar(new JSUndefined); 
}


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


JSBoolean::JSBoolean(bool _b) : b(_b) {}

std::string JSBoolean::toString() {
  return b ? "true" : "false";
}

void JSBoolean::appendString(std::stringstream& out) {
  out << (b ? "true" : "false");
}


JSIdentifier::JSIdentifier(std::string s) : JSString(s) {}

bool JSIdentifier::isIdentifier() {
  return true;
}


///// JSError /////////////////////////////////////////////////66

JSError::JSError(std::string _msg, int _code) : msg(_msg), code(_code) {
}


std::string JSError::toString() {
  return "Error";
}


void JSError::appendString(std::stringstream& out) {
  out << "Error";
}


bool JSError::isString() {
  return true;
}


std::string JSError::message() {
  return "Error " + msg;
}


///// JSString ////////////////////////////////////////////////66

JSString::JSString(std::string _str) : str(_str) {
}


std::string JSString::toString() {
  return str;
}


void JSString::appendString(std::stringstream& out) {
  out << str;
}


bool JSString::isString() {
  return true;
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
  RefVar v = popCalcOriginal();
  if (v->isIdentifier()) {
    v = getProperty(v->toString());
  }
  return v;
}


RefVar JSContext::popCalcOriginal() {
  if (calcStack.size() <= 0) {
    return Ref<Var>(new JSUndefined());
  }
  RefVar v = calcStack.back();
  calcStack.pop_back();
  return v;
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


void JSContext::setError(std::string msg) {
  Ref<JSError> ref(new JSError(msg));
  setError(ref);
}


Ref<JSError> JSContext::getError() {
  return error;
}