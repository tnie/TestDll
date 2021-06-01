#include <iostream>
#include <Windows.h>
#include <cassert>
#include <winuser.h>
#include <string>
#include <vector>
#include "../add/add.h"
#include "../sub/sub.h"
#include "../ThreadDemo/ThreadHelper.h"
// 1. �ȿ��ǲ�ʹ�� def �ļ������ַ�ʽò����ȱ�ݲų��ֵ� __declspec(dllexport/dllimport)
// 2. ��ʱҲ���������أ�c �� C++ �ڱ����ڼ�����������
// 3. �����ĵ��÷�ʽ���__cdecl / __stdcall / _fastcall ������ʽ�����η���Ҳ����ͬ

#pragma comment(lib, "../Debug/addd.lib")
#pragma comment(lib, "../Debug/subd.lib")
//extern "C" __declspec(dllimport) int sub(const int a, const int b);

using namespace std;
int main(int argc, char* argv[])
{
    {
        cout << "> ���߳̿�ʼ" << "\n";
        MyThread::instance().start();
        Sleep(10);          // �̱߳���ֹ��code 0
        //Sleep(10 * 1000);   // �߳�ִ����ϣ�code 87
        cout << "> ���߳̽���" << "\n";
        return 27;
    }
    string niel("niel");
    //helloValue(niel);   // run failed
    helloRef(niel); // ok
    {
        /*auto str = returnValue();
        cout << str << endl;*/
    }   // run failed
        // ����ʱ __acrt_first_block == header ����
        // ���Ƴ� str ���� dll ģ����ɸ�ֵ�ģ�
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
        // ����ʱ __acrt_first_block == header ����

    {
        auto niel = std::make_shared<string>();
        /*cout << returnSmartPtr(niel);*/
        cout << returnSmartPtr(nullptr);
    }   // run failed
        // ����ʱ __acrt_first_block == header ����

    {
        auto niel = std::make_shared<string>();
        /*cout << returnSmartPtr2(niel);*/
    }   // run failed
        // ����ʱ __acrt_first_block == header ����

    {
        auto niel = std::make_shared<string>();
        /*cout << returnSmartPtr3(niel);*/
    }   // run failed
        // ����ʱ __acrt_first_block == header ����

    {
        auto names = std::make_shared<vector<string>>();
        /*fillv(names);*/
    }   // run failed
        // ����ʱ __acrt_first_block == header ����

    {
        auto ptr = returnv();
        cout << ptr->size() << endl;
        /*ptr->resize(100);*/
        for (size_t i = 0; i < 100; i++)
        {
            /*ptr->push_back("100");*/
        }
    }   // run failed
        // ����ʱ __acrt_first_block == header ����

    {
        cout << "2-1=" << sub(2, 1) << endl;
    }
    return 0;
}
