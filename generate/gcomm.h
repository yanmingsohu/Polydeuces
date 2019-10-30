#pragma once

//
// 如果用静态库导出, 必须首先定义这个宏, 否则警告 C4251
//
#define ANTLR4CPP_STATIC

#if defined(_WIN64) || defined(_WIN32)
  #pragma comment(lib, "antlr4-runtime.lib")
#endif