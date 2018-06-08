# TestDll
学习 dll 导出函数、导出变量

包括以下主题：

## 如何从 dll 中导出：

http://www.cnblogs.com/enterBeijingThreetimes/archive/2010/08/04/1792099.html

[通过 `__declspec(dllexport)` 导出][1]，或者[通过定义 `.def` 文件导出][2]

1. 导出函数；
2. 导出变量；
3. 导出类；

    http://www.cppblog.com/suiaiguo/archive/2009/07/20/90663.html， 其导出类的方式是错误的！在 msvc2015 中导入/导出描述必须放在 `class` 关键词和类名之间，否则报错“构造函数、成员函数等未定义”——有点莫名
    
    ```cpp
    _ADD_API class Student  // err
    {
    public:
        Student();
        int age();
        bool sex();
    private:
        int m_age;
        bool m_sex;
        char m_name[10];
    };
    ```
    
    > : warning C4091: “__declspec(dllimport)”: 没有声明变量时忽略“Student”的左侧
    
    > : error LNK2019: 无法解析的外部符号 "public: __thiscall Student::Student(void)" (??0Student@@QAE@XZ)，该符号在函数 _main 中被引用
    
    > : error LNK2019: 无法解析的外部符号 "public: int __thiscall Student::age(void)" (?age@Student@@QAEHXZ)，该符号在函数 _main 中被引用
    
## 如何使用 dll 文件：

显示调用、隐式调用

## 为什么会出现 ` __acrt_first_block == header` 错误？

http://www.cnblogs.com/xuhuajie/p/7444716.html

https://stackoverflow.com/questions/35310117/debug-assertion-failed-expression-acrt-first-block-header

简而言之，就是「dll 申请内存，exe 释放内存」或者「exe 申请内存，dll 释放内存」造成的。

「跨模块管理内存」只是“在 dll 中使用 stl”风险之一.

同时我们也应该认识到「跨模块管理内存」并不局限于在接口中使用 stl（或者 std::string）才会出现：
它是一个广泛存在的问题，在 [跨DLL的内存分配释放问题][4] 中作者给出了普适性的描述：

> 在一个DLL里面分配内存，然后在DLL的调用者EXE那里释放内存。
> 当DLL和EXE里面**有一个是使用MT连接CRT的时候**就有问题。如果DLL和EXE**都使用MD**，那么就没有问题。

https://blog.csdn.net/ilvu999/article/details/8219179

## 在 dll 接口中使用 stl 或者 std::string 的风险

在 [不要在公共接口中传递STL容器][3] 中作者列举了四个方面：
 
> 客户端使用的STL版本可能不同

    主要的梗在于使用不同版本的 msvc 开发
    
> 编译选项

    如果多个模块中有一个使用 MT[d] 运行时，就有很大概率造成程序崩溃。也就是上面讨论的 ` __acrt_first_block == header` 错误
    
> 静态变量

    有关冲突只会出现在 dll 中，so 并不会。

> 客户端的STL被自定义

    这种情况概率太小，修改 stl 库很蠢。
    
静态成员不同步：https://blog.csdn.net/lewutian/article/details/6786193




[1]:https://msdn.microsoft.com/en-us/library/a90k134d.aspx#annotations:epC1-i2vEeiXZeM0K3qNow
[2]:https://msdn.microsoft.com/en-us/library/d91k01sh.aspx#annotations:Vj3D4i2uEeiEu_PBl1x4Ig
[3]:http://www.cnblogs.com/baiyanhuang/archive/2011/07/10/2102484.html
[4]:https://blog.csdn.net/zj510/article/details/35290505
