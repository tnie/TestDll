#include <string>
#define __ADD_DLL
#include "add.h"
#include <iostream>

using namespace std;

string g_str("global value");

void helloValue(std::string name)
{
    cout << "hello world, " << name << endl;
}   // 返回时 __acrt_first_block == header 错误
    // 反推出 name 是在 exe 模块完成赋值的！

void helloRef(const std::string & name)
{
    cout << "hello kitty, " << name << endl;
}

std::string returnValue(void)
{
    return "value";
}

std::string & returnRef(void)
{
    return g_str;
}

bool returnPointer(std::string * const out)
{
    if (out)
    {
        cout << "before " << out->size() << endl;
        cout << "before " << out->capacity() << endl;
        // 重新分配内存？或者只有追加，并未释放？
        //out->resize(100);
        //out->~basic_string();
        cout << "resize: " << out->size() << endl;

        // 重新分配内存？或者只有追加，并未释放？
        *out = "niel0123456789niel0123456789niel0123456789";
        return true;
    }
    return false;
}

bool returnSmartPtr(std::shared_ptr<std::string> out)
{
    if (out)
    {
        cout << "before " << out->size() << endl;
        cout << "before " << out->capacity() << endl;
        out->resize(100);
        cout << "resize: " << out->size() << endl;

        *out = "niel";
        return true;
    }
    return false;
}

bool returnSmartPtr2(std::shared_ptr<std::string>& out)
{
    if (out)
    {
        cout << "before " << out->size() << endl;
        cout << "before " << out->capacity() << endl;
        out->resize(100);
        cout << "resize: " << out->size() << endl;

        *out = "niel";
        return true;
    }
    return false;
}

bool returnSmartPtr3(const std::shared_ptr<std::string>& out)
{
    if (out)
    {
        cout << "before " << out->size() << endl;
        cout << "before " << out->capacity() << endl;
        out->resize(100);
        cout << "resize: " << out->size() << endl;

        *out = "niel";
        return true;
    }
    return false;
}

bool fillv(std::shared_ptr<std::vector<std::string>>& out)
{
    if (out)
    {
        cout << "before " << out->size() << endl;
        cout << "before " << out->capacity() << endl;
        out->resize(100);
        cout << "resize: " << out->size() << endl;

        out->push_back("niel");
        return true;
    }
    return false;
}

std::shared_ptr<std::vector<std::string>> returnv()
{
    return std::make_shared<std::vector<std::string>>(2, "niel");
}
