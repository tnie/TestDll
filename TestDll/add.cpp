#include <string>

int _add(const int a, const int b)
{
	return a + b;
}

__declspec(dllexport) int add(const int a, const int b)
{
	return _add(a, b);
}

extern "C" __declspec(dllexport) int sub(const int a, const int b)
{
	return a-b;
}
// c
//1    0 000110E1 add = @ILT+220(_add)
// c++  
//1    0 00011208 ? add@@YAHHH@Z = @ILT+515(? add@@YAHHH@Z)

__declspec(dllexport) std::string add(const std::string& str1, const std::string& str2)
{
	return str1 + str2;
}