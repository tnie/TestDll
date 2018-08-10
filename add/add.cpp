#include <string>
#define __ADD_DLL
#include "add.h"
#include <iostream>
#include <Windows.h>

using namespace std;
size_t sum(const std::string& str1, const std::string& str2)
{
    std::string str = str1 + str2;
    return str.size();
}

Student * CreateInstance()
{
    return new Student();
}

std::shared_ptr<Student> CreateInstance2()
{
    return std::make_shared<Student>();
}

void ReleaseInstance(Student const * const ptr)
{
    delete ptr;
}


Student::Student():m_age(20), m_sex(true), m_name("niel")
{
    cout << "Student ctor" << endl;
}

inline Student::~Student()
{
    cout << "Student dtor" << endl;
}

int Student::age()
{
    return m_age;
}

bool Student::sex()
{
    return m_sex;
}

void Student::change(std::string name)
{
    m_name.swap(name);
}

int Student::Date::year()
{
    return 0;
}

int Student::Date::month()
{
    return 0;
}

int Student::Date::day()
{
    return 0;
}
