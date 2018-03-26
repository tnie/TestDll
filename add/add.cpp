#include <string>
#define __ADD_DLL
#include "add.h"
#include <iostream>

using namespace std;
int _add(const int a, const int b)
{
	return a + b;
}

int add(const int a, const int b)
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

std::string add(const std::string& str1, const std::string& str2)
{
	return str1 + str2;
}

size_t sum(const std::string& str1, const std::string& str2)
{
    std::string str = str1 + str2;
    return str.size();
}

void add2(const std::string &str1, const std::string &str2, std::string & res)
{
    res = str1 + str2;
    //cout << "capacity in add2() is: " << res.capacity() << endl;
}
