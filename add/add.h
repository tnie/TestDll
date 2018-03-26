#pragma once
#include <string>

#ifdef __ADD_DLL
#define _ADD_API __declspec(dllexport)
#else
#define _ADD_API __declspec(dllimport)
#endif

_ADD_API int add(const int, const int);
_ADD_API std::string add(const std::string&, const std::string&);

#undef  _ADD_API