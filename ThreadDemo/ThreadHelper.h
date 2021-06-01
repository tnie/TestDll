#pragma once
//���߳���ռ���
#include <iostream>
#include <process.h>
#include <Windows.h>

using namespace std;

static unsigned int WINAPI  threadProc(LPVOID lpParam);

#ifdef __THREAD_DLL
#define _THREAD_API __declspec(dllexport)
#else
#define _THREAD_API __declspec(dllimport)
#endif

class ThreadHelper
{
public:
    ThreadHelper() { _hThreadID = 0; }
    ~ThreadHelper()
    {
    }
public:
    _THREAD_API bool start()
    {
        unsigned long long ret = _beginthreadex(NULL, 0, threadProc, (void *) this, 0, NULL);

        if (ret == -1 || ret == 0)
        {
            printf("log4z: create log4z thread error! \r\n");
            return false;
        }
        _hThreadID = ret;
        return true;
    }
    bool wait()
    {
        if (WaitForSingleObject((HANDLE)_hThreadID, INFINITE) != WAIT_OBJECT_0)
        {
            return false;
        }
        DWORD hh;
        auto succeed = GetExitCodeThread((HANDLE)_hThreadID, &hh);
        cout << "ExitCodeThread: " << succeed << " ExitCode: " << hh << endl;
        return true;
    }
    virtual void run() = 0;
private:
    unsigned long long _hThreadID;
};

unsigned int WINAPI  threadProc(LPVOID lpParam)
{
    ThreadHelper * p = (ThreadHelper *)lpParam;
    p->run();
    return 87;
}

class MyThread : public ThreadHelper
{
public:
    _THREAD_API static MyThread & instance()
    {
        static MyThread _instance;
        return _instance;
    }
    ~MyThread()
    {
        for (int i = 0; i < 5; ++i) { //��ռѭ��
            cout << "���̵߳�" << i << "����������ʱ��" << endl; //�����Ϣ
            Sleep(100); //��ռ��ʱ
        }
        ThreadHelper::wait();
    }
private:
    MyThread() = default;
    void run() override
    {
        cout << "���߳̿�ʼ" << endl;
        for (int i = 0; i < 10; ++i) { //��ռѭ��
            cout << "���̵߳�" << i << "��ѭ����ռ��" << endl; //�����Ϣ
            Sleep(100); //��ռ��ʱ
        }
        cout << "���߳̽���" << endl;
    }
};


