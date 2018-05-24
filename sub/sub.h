#pragma once
#ifdef __SUB_DLL
#define _SUB_API __declspec(dllexport)
#else
#define _SUB_API __declspec(dllimport)
#endif

_SUB_API int sub(const int a, const int b);

#undef  _SUB_API