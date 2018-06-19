#include <iostream>
#include <Windows.h>
#include <cassert>
#include <winuser.h>
#include <string>
#include <vector>
#include "../add/add.h"
#include "../sub/sub.h"
// 1. 先考虑不使用 def 文件。这种方式貌似有缺陷才出现的 __declspec(dllexport/dllimport)
// 2. 暂时也不考虑重载，c 和 C++ 在编译期间命名的区别
// 3. 函数的调用方式相关__cdecl / __stdcall / _fastcall 几个方式的修饰符号也不相同

#pragma comment(lib, "../Debug/addd.lib")
#pragma comment(lib, "../Debug/subd.lib")
//extern "C" __declspec(dllimport) int sub(const int a, const int b);

using namespace std;
int main(int argc, char* argv[])
{
    string niel("niel");
    //helloValue(niel);   // run failed
    helloRef(niel); // ok
    {
        /*auto str = returnValue();
        cout << str << endl;*/
    }   // run failed
        // 返回时 __acrt_first_block == header 错误
        // 反推出 str 是在 dll 模块完成赋值的！
    {
        auto str = returnRef();
        cout << str.size() << endl;
        str.resize(100);
        cout << str.size() << endl;
        cout << str << endl;
    }

    {
        //std::string niel();
        std::string niel("niel");
        /*cout << returnPointer(&niel);*/
        cout << returnPointer(nullptr);
    }   // run failed
        // 返回时 __acrt_first_block == header 错误

    {
        auto niel = std::make_shared<string>();
        /*cout << returnSmartPtr(niel);*/
        cout << returnSmartPtr(nullptr);
    }   // run failed
        // 返回时 __acrt_first_block == header 错误

    {
        auto niel = std::make_shared<string>();
        /*cout << returnSmartPtr2(niel);*/
    }   // run failed
        // 返回时 __acrt_first_block == header 错误

    {
        auto niel = std::make_shared<string>();
        /*cout << returnSmartPtr3(niel);*/
    }   // run failed
        // 返回时 __acrt_first_block == header 错误

    {
        auto names = std::make_shared<vector<string>>();
        /*fillv(names);*/
    }   // run failed
        // 返回时 __acrt_first_block == header 错误

    {
        auto ptr = returnv();
        cout << ptr->size() << endl;
        /*ptr->resize(100);*/
        for (size_t i = 0; i < 100; i++)
        {
            /*ptr->push_back("100");*/
        }
    }   // run failed
        // 返回时 __acrt_first_block == header 错误

    {
        cout << "2-1=" << sub(2, 1) << endl;
    }
    return 0;
}
