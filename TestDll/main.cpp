#include <iostream>
#include "../add/add.h"
// 1. 先考虑不使用 def 文件。这种方式貌似有缺陷才出现的 __declspec(dllexport/dllimport)
// 2. 暂时也不考虑重载，c 和 C++ 在编译期间命名的区别
// 3. 函数的调用方式相关__cdecl / __stdcall / _fastcall 几个方式的修饰符号也不相同


using namespace std;
int main(int argc, char* argv[])
{
    std::cout << sum("love ", " liyw") << std::endl;
    std::string res;
    res.resize(100);


    cout << "#################" << endl;
    Student niel;
    cout << "age: " << niel.age() << endl;
    {
        auto ptr = CreateInstance2();
    }
    auto ptr = CreateInstance();
    //delete ptr;   // bang
    ReleaseInstance(ptr);

    {
        Student::Date date;
        date.day();
        //date.month();   // err
    }
    return 0;
}

// 似乎用不到头文件
// 经过试验，在 GetProcAddress() 中不推荐使用函数名，而是使用 MAKEINTRESOURCE(n)