#include "javascript.h"

using namespace PolydeucesEngine;


///// JSObject ////////////////////////////////////////////////66

JSObject::JSObject() {}


///// JSContext ///////////////////////////////////////////////66

JSContext::JSContext(std::shared_ptr<JSContext>& _parent) : parent(_parent) {}
JSContext::JSContext() : parent(0) {}


void JSContext::add(std::shared_ptr<JSContext>& child) {
  childs.push_back(child);
}


std::shared_ptr<JSContext>& JSContext::getParent() {
  return parent;
}