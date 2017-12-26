#include <iostream>
#include <Windows.h>
#include <cassert>
#include <winuser.h>
#include <string>
// 1. 先考虑不使用 def 文件。这种方式貌似是后出现的
// 2. 暂时也不考虑重载，c 和 C++ 在编译期间命名的区别
// 3. 函数的调用方式相关__cdecl / __stdcall / _fastcall 几个方式的修饰符号也不相同

//typedef  int(_cdecl *ADD)(const int, const int);
typedef  int(*ADD)(const int, const int);
typedef std::string( *STRADD)(const std::string&, const std::string&);

CONST std::string _str_add_name = "?add@@YA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@ABV12@0@Z";
int main(int argc, char* argv[])
{
	HINSTANCE hInstance = LoadLibrary("add.dll");
	assert(hInstance);

	STRADD stradd = (STRADD)GetProcAddress(hInstance, _str_add_name.c_str());  // ok
    //STRADD stradd = (STRADD)GetProcAddress(hInstance, MAKEINTRESOURCE(1));  // ok
	assert(stradd);
	ADD add = (ADD)GetProcAddress(hInstance, "?add@@YAHHH@Z");  // ok
	//ADD add = (ADD)GetProcAddress(hInstance, MAKEINTRESOURCE(2)); //it's ok
	if (add)
		std::cout << stradd("the result of", "（add(1, 2)）:") << add(1, 2) << std::endl;

	ADD sub = (ADD)GetProcAddress(hInstance, "sub");  // ok
	//ADD sub = (ADD)GetProcAddress(hInstance, MAKEINTRESOURCE(3)); //it's ok
	if (sub)
		std::cout << "the result of（sub(1, 2)）:" << sub(1, 2) << std::endl;

	FreeLibrary(hInstance);
	return 0;
}

// 似乎用不到头文件
// 经过试验，在 GetProcAddress() 中不推荐使用函数名，而是使用 MAKEINTRESOURCE(n)