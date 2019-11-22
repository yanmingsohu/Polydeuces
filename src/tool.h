#pragma once
#include "types.h"

namespace PolydeucesEngine {


enum UnicodeType {
  UnicodeUnknow = 0, Letter = 1, CombiningMark = 2, Digit = 3, ConnectorPunctuation = 4
};


int utf8_to_unicode(Unicode& out, CharSequence str, int len);
UnicodeType unicode_type(Unicode c);


template<class T> bool isDigital(T c) {
  return c >= '0' && c <= '9';
}


template<class T> bool isHexDigital(T c) {
  return (c >= '0' && c <= '9') || (c >= 'a' && c <='z') || (c >= 'A' && c <= 'Z');
}


template<class T> bool isLetter(T c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}


template<class T> T get_max(T a, T b) {
  return a > b ? a : b;
}


template<class T> T get_min(T a, T b) {
  return a < b ? a : b;
}


}