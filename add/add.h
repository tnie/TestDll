#pragma once
#include <string>
#include <memory>

#ifdef __ADD_DLL
#define _ADD_API __declspec(dllexport)
#else
#define _ADD_API __declspec(dllimport)
#endif

_ADD_API size_t sum(const std::string&, const std::string&);

class _ADD_API Student
{
public:
    class Date
    {
    public:
        int year();
        int month();
        int _ADD_API day();
    private:
        long _date;
    };
    /*Student();
    ~Student();*/

    inline int age();
    bool sex();
    /*_ADD_API*/ void change(std::string name);
private:
    int m_age;
    bool m_sex;
    std::string m_name;
    void do_nothing()
    {
        // inline
    }
};

_ADD_API Student * CreateInstance();
_ADD_API std::shared_ptr<Student> CreateInstance2();
_ADD_API void ReleaseInstance(Student const * const ptr);

//template<class T>
//T * CreateInstance()
//{
//    return new T();
//}
//template<class T>
//void ReleaseInstance(T const * const ptr)
//{
//    delete ptr;
//}

#undef  _ADD_API