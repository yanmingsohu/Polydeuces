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


///// JSObject ////////////////////////////////////////////////66

JSObject::JSObject() {}


std::string JSObject::toString() {
  return std::string("[object Object]");
}


void JSObject::setProperty(std::string name, RefVar val) {
  properties[name] = val;
}


bool JSObject::hasProperty(std::string name) {
  return properties.count(name) > 0;
}


RefVar JSObject::getProperty(std::string name) {
  auto search = properties.find(name);
  if (search != properties.end()) {
    return search->second;
  }
  return RefVar(new JSUndefined);
}


JSObject::Properties& JSObject::propertiesRef() {
  return properties;
}


void JSObject::printAllProps() {
  std::cout << "Properties:\n\t";
  for (auto i = properties.begin(); i != properties.end(); ++i) {
    std::cout << i->first << " = " << i->second->toString() << ", ";
  }
  std::cout << std::endl;
}


bool JSObject::isObject() {
  return true;
}


JavaScriptTypeId JSObject::typeID() {
  return JavaScriptTypeId::t_object;
}


bool JSObject::toBoolean() {
  return true;
}


///// JSNull //////////////////////////////////////////////////66

bool JSNull::isNull() { 
  return true; 
}


void JSNull::appendString(std::stringstream& out) {
  out << "null";
}


std::string JSNull::toString() {
  return std::string("null");
}


JavaScriptTypeId JSNull::typeID() {
  return JavaScriptTypeId::t_null;
}


///// JSUndefined /////////////////////////////////////////////66

bool JSUndefined::isUndefined() {
  return true;
}


void JSUndefined::appendString(std::stringstream& out) {
  out << "undefined";
}


std::string JSUndefined::toString() {
  return std::string("undefined");
}


JavaScriptTypeId JSUndefined::typeID() {
  return JavaScriptTypeId::t_undefined;
}


///// JSNaN ///////////////////////////////////////////////////66

bool JSNaN::isNaN() {
  return true;
}


void JSNaN::appendString(std::stringstream& out) {
  out << "NaN";
}


std::string JSNaN::toString() {
  return std::string("NaN");
}


JavaScriptTypeId JSNaN::typeID() {
  return JavaScriptTypeId::t_nan;
}


///// JSBoolean ///////////////////////////////////////////////66

JSBoolean::JSBoolean(bool _b) : b(_b) {}


std::string JSBoolean::toString() {
  return b ? "true" : "false";
}


void JSBoolean::appendString(std::stringstream& out) {
  out << (b ? "true" : "false");
}


double JSBoolean::toNumber() {
  return b ? 1 : 0;
}


JavaScriptTypeId JSBoolean::typeID() {
  return JavaScriptTypeId::t_boolean;
}


bool JSBoolean::toBoolean() {
  return b;
}


///// JSIdentifier ////////////////////////////////////////////66

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
  return "Error: " + msg;
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


JavaScriptTypeId JSString::typeID() {
  return JavaScriptTypeId::t_string;
}


bool JSString::toBoolean() {
  return str.length() > 0;
}


///// JSArray /////////////////////////////////////////////////66

bool JSArray::isArray() {
  return true;
}


std::string JSArray::toString() {
  std::stringstream buf;
  appendString(buf);
  return buf.str();
}


void JSArray::appendString(std::stringstream& buf) {
  bool first = true;
  for (auto i = elem.begin(), end = elem.end(); i != end; ++i) {
    auto e = (*i);
    if (!first) {
      buf << ',';
    } else {
      first = false;
    }
    if (e->isString()) {
      buf << '"' << e->toString() << '"';
    } else {
      buf << e->toString();
    }
    
  }
}


JavaScriptTypeId JSArray::typeID() {
  return JavaScriptTypeId::t_array;
}


bool JSArray::toBoolean() {
  return true;
}


///// JSNumber ////////////////////////////////////////////////66

JSNumber::JSNumber(double n) : num(n) {}


bool JSNumber::isNumber() {
  return true;
}


void JSNumber::appendString(std::stringstream& out) {
  long i = long(num);
  if (double(i) == num) {
    out << i;
    return;
  }
  out << num;
}


std::string JSNumber::toString() {
  long i =  long(num);
  if (double(i) == num) {
    return std::to_string(i);
  }
  return std::to_string(num);
}


double JSNumber::toNumber() {
  return num;
}


bool JSNumber::toBoolean() {
  return num != 0;
}


JavaScriptTypeId JSNumber::typeID() {
  return JavaScriptTypeId::t_number;
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
  JSContext* ctx = this;
  do {
    if (ctx->isFunctionCtx) {
      return ctx;
    }
    ctx = ctx->parent.get();
  } while (ctx);
  return 0;
}


RefVar JSContext::popCalc() {
  RefVar v = popCalcOriginal();
  if (v->isIdentifier()) {
    v = getProperty(v->toString());
  }
  return v;
}


RefVar JSContext::popCalcOriginal() {
  checkStateThrowException();
  if (calcStack.size() <= 0) {
    return Ref<Var>(new JSUndefined());
  }
  RefVar v = calcStack.back();
  calcStack.pop_back();
  return v;
}


void JSContext::pushCalc(RefVar& v) {
  checkStateThrowException();
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
    auto x = (*i)->toString();

    if ((*i)->isIdentifier()) {
      std::cout << x << '=' 
                << getContextProperty(x)->toString() << ", ";
    } else {
      std::cout << x << ", ";
    }
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


JSContext* JSContext::findContext(std::string& propertyName, bool returnFunctionCtx) {
  JSContext* ctx = this;
  JSContext* func = 0;
  do {
    if (ctx->hasProperty(propertyName)) {
      return ctx;
    }
    if (func == 0 && ctx->isFunctionCtx) {
      func = ctx;
    }
    ctx = ctx->parent.get();
  } while(ctx);
  if (returnFunctionCtx) {
    return func;
  }
  return 0;
}


void JSContext::setContextProperty(std::string name, RefVar val) {
  checkStateThrowException();
  JSContext *f = findContext(name, true);
  if (f->constVar.count(name)) {
    setError(name + " is constant variable");
    return;
  }
  f->setProperty(name, val);
}


RefVar JSContext::getContextProperty(std::string name) {
  checkStateThrowException();
  JSContext* f = findContext(name);
  if (!f) {
    setError(name +" is not defined");
    return RefVar(new JSUndefined());
  }
  auto r = f->getProperty(name);
  return r;
}


void JSContext::setConst(std::string var_name) {
  constVar.insert(var_name);
}


void JSContext::clearCalcStack() {
  checkStateThrowException();
  calcStack.clear();
}


void JSContext::checkStateThrowException() {
  if (hasErrFlag) {
    throw JSRuntimeException(error);
  }
}