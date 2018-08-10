#include <iostream>
#include "../add/add.h"
// 1. 先考虑不使用 def 文件。这种方式貌似有缺陷才出现的 __declspec(dllexport/dllimport)
// 2. 暂时也不考虑重载，c 和 C++ 在编译期间命名的区别
// 3. 函数的调用方式相关__cdecl / __stdcall / _fastcall 几个方式的修饰符号也不相同


using namespace std;
int main(int argc, char* argv[])
{
    Student niel;
    cout << "age: " << niel.age() << endl;
    {
        string liyw = "liyw";
        niel.change(liyw);  // swap 后并不会马上引发崩溃
        // do something
        // swap1：释放对象 liyw 时，其内部存储已经指向 dll 中，BANG
    }
    {
        auto ptr = CreateInstance2();
    }
    auto ptr = CreateInstance();
    //delete ptr;   // bang
    string cat("miao");
    //ptr->change(cat);
    ReleaseInstance(ptr);   // swap2：释放dll 中 m_name 时，因其存储执行 exe 中，BANG

    {
        Student::Date date;
        date.day();
        //date.month();   // err
    }
    return 0;
}

// 似乎用不到头文件
// 经过试验，在 GetProcAddress() 中不推荐使用函数名，而是使用 MAKEINTRESOURCE(n)