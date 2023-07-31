#include <iostream>
using namespace std;
#if 0
// C++11
// 智能指针原理：RAII+具有指针类似行为+如何解决浅拷贝问题
// 如何解决浅拷贝的问题？
// 浅拷贝的问题是如何引起的？--默认的拷贝构造函数和赋值运算符重载
// 在一个对象拷贝构造一个新对象或者用一个对象给另一个对象赋值
// unique_ptr设计时非常简单粗暴-->禁止共享
// unique_ptr设计原理：RAII+具有指针类似的行为+资源独占（禁止共享||防止拷贝）

#include <memory>
void TestUniquePtr()
{
    unique_ptr<int> up1(new int(10));
    *up1 = 100;

    // unique_ptr<int> up2(up1);

    unique_ptr<int> up3(new int(10));
    // up1 = up3;

    // 程序猿代码能力问题
    //  int *p = new int;
    //  unique_ptr<int> up4(p);
    //  unique_ptr<int> up5(p);
}
int main()
{
    TestUniquePtr();

    system("pause");
    return 0;
}
#endif

#if 0
// C++11：unique_ptr
// 最简单的方法：将 =delete 修饰拷贝构造函数和赋值运算符重载
class CopyBan
{
public:
    CopyBan(int c = 0)
        : _c(c)
    {
    }

    // 让编译器不要生成默认的拷贝构造函数
    CopyBan(const CopyBan &) = delete;
    CopyBan &operator=(const CopyBan &) = delete;

private:
    int _c;
};

int main()
{
    CopyBan cb1(1);
    // CopyBan cb2(cb1);

    CopyBan cb3(2);
    // cb3 = cb1;

    system("pause");
    return 0;
}
#endif

#if 0
// C++98中防止拷贝功能的类
// 将拷贝构造以及赋值运算符重载只声明，不定义
// 并将其访问权限设置为private
class CopyBan
{
public:
    CopyBan(int c = 0)
        : _c(c)
    {
    }

private:
    // 防止在类外定义
    // 让编译器不要生成默认的拷贝构造函数
    CopyBan(const CopyBan &);
    CopyBan &operator=(const CopyBan &);

private:
    int _c;
};
CopyBan::CopyBan(const CopyBan &)
{
}

int main()
{
    CopyBan cb1(1);
    // CopyBan cb2(cb1);
    CopyBan cb3(2);
    // cb1 = cb3;

    system("pause");
    return 0;
}
#endif
#if 0
namespace Zzxh
{
    template <class T>
    class DFDef
    {
    public:
        void operator()(T *ptr)
        {
            if (ptr)
            {
                delete ptr;
                ptr = nullptr;
            }
        }
    };
    // 定制删除器 C++中，大部分空间都是new来的，其他的方式让用户显式调用
    template <class T, class DF = DFDef<T>>
    class unique_ptr
    {
    public:
        // RAII
        unique_ptr(T *ptr = nullptr)
            : _ptr(ptr)
        {
        }
        // 注意析构函数
        ~unique_ptr()
        {
            if (_ptr)
            {
                // DF df;
                // df.operator()(_ptr);
                DF()
                (_ptr);
            }
        }

        // 具有指针类似的行为
        T &operator*()
        {
            return *this;
        }
        T *operator->()
        {
            return this;
        }

        T *get()
        {
            return _ptr;
        }

        // 防拷贝 C++11
        unique_ptr(const unique_ptr<T> &) = delete;
        unique_ptr<T> operator=(const unique_ptr<T> &) = delete;

    private:
        T *_ptr;
    };
}

template <class T>
class Free
{
public:
    void operator()(T *&ptr)
    {
        if (ptr)
        {
            free(ptr);
            ptr = nullptr;
        }
    }
};

class FClose
{
public:
    void operator()(FILE *&ptr)
    {
        if (ptr)
        {
            fclose(ptr);
            ptr = nullptr;
        }
    }
};

template <class T>
class deleArray
{
public:
    void operator()(T *&ptr)
    {
        if (ptr)
        {
            delete[] ptr;
            ptr = nullptr;
        }
    }
};

#include <malloc.h>
#include <stdlib.h>
void TestUniquePtr()
{
    Zzxh::unique_ptr<int> up1(new int(10));
    *up1 = 200;

    Zzxh::unique_ptr<int, Free<int>> up2((int *)malloc(sizeof(int)));

    Zzxh::unique_ptr<FILE, FClose> up3(fopen("111.txt", "w"));

    // Zzxh::unique_ptr<int> up4(new int[10]);
    //  unique_ptr能不能管理连续的空间？int [10]
    //  一般不会将连续的空间使用unique_ptr管理
    //  因为：STL中已经存在vector
}

// 缺陷：unique_ptr管理的资源无法共享
int main()
{
    TestUniquePtr();
    // VS2019中查看是否有内存泄漏函数
    //_CrtDumpMemoryLeaks();

    system("pause");
    return 0;
}
#endif

