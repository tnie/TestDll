#include <iostream>
#include <Windows.h>
#include <cassert>
#include <winuser.h>
// 1. 先考虑不使用 def 文件。这种方式貌似是后出现的
// 2. 暂时也不考虑重载，c 和 C++ 在编译期间命名的区别
// 3. 函数的调用方式相关__cdecl / __stdcall / _fastcall 几个方式的修饰符号也不相同

//typedef  int(_cdecl *ADD)(const int, const int);
typedef  int( *ADD)(const int, const int);

int main(int argc, char* argv[])
{
	HINSTANCE hInstance = LoadLibrary("add.dll");
	assert(hInstance);

	ADD add = (ADD)GetProcAddress(hInstance, "add"); // c 的函数名
	//ADD add = (ADD)GetProcAddress(hInstance, MAKEINTRESOURCE(2)); //it's ok
	if (add)
		std::cout << "the result of（add(1, 2)）:" << add(1, 2) << std::endl;

	//ADD sub = (ADD)GetProcAddress(hInstance, "sub");  // ERR
	ADD sub = (ADD)GetProcAddress(hInstance, "?sub@@YAHHH@Z");  // c++ 的函数名
	//ADD sub = (ADD)GetProcAddress(hInstance, MAKEINTRESOURCE(1)); //it's ok
	if (sub)
		std::cout << "the result of（sub(1, 2)）:" << sub(1, 2) << std::endl;

	FreeLibrary(hInstance);
	return 0;
}

// 似乎用不到头文件