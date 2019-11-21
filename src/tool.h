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


template<class T> bool isLetter(T c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

}