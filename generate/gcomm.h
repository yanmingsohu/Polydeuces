#pragma once

//
// ����þ�̬�⵼��, �������ȶ��������, ���򾯸� C4251
//
#define ANTLR4CPP_STATIC

#if defined(_WIN64) || defined(_WIN32)
  #pragma comment(lib, "antlr4-runtime.lib")
#endif