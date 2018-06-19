#pragma once
#include <string>

#ifdef __ADD_DLL
#define _ADD_API __declspec(dllexport)
#else
#define _ADD_API __declspec(dllimport)
#endif

// 作为输入
_ADD_API void helloValue(std::string name);
_ADD_API void helloRef  (const std::string& name);
// 作为输出
_ADD_API std::string  returnValue(void);
_ADD_API std::string& returnRef(void);
_ADD_API bool returnBy(std::string* out);

#undef  _ADD_API