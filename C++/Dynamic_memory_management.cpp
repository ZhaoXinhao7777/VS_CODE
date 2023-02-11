#include <iostream>
using namespace std;
#if 0
// c语言中：
// 堆上申请空间：malloc,calloc realloc
// 堆上释放空间：free

// C++ 中任可以使用，因为C++ 兼容C语言

// C++:new和delete来进行动态内存管理
//
// 申请空间使用new 在new之后类型即可
// new T;申请单个T类型空间
// new T[N];申请N个T类型得一段连续空间
//

int main()
{
    // 空间申请：堆上
    // 申请单个T类型得空间
    int *p1 = new int;
    int *p2 = new int(10);

    // 申请N个T类型得一段连续的空间
    int *p3 = new int[10];
    int *p4 = new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    // 注意：申请和释放一定要匹配起来使用
    // 释放：
    delete p1;
    delete p2;

    // 释放连续空间
    delete[] p3;
    delete[] p4;

    system("pause");
    return 0;
}
#endif
#if 0
// 注意：new/delete new[]/delete[] malloc/free
// 一定要匹配起来使用 否则会造成内存泄漏 或者 程序崩溃

// 发现：下面的程序既没有内存泄漏，也没有崩溃
// 为什么C++中强调:new/delete new[]/delete[] malloc/free
// 不匹配起来的后果：会造成内存泄漏 或者和程序崩溃
//
// 内置类型:是否匹配起来使用，没有任何问题
// 建议：new/deletw new[]/delete[] malloc/free匹配起来使用
void TestMemory()
{
    int *p1 = new int;
    int *p2 = new int;
    delete p1, p2;
    free(p1);
    delete[] p2;

    int *p3 = new int[10];
    int *p4 = new int[10];
    delete p3;
    free(p4);

    int *p5 = (int *)malloc(sizeof(int) * 10);
    int *p6 = (int *)malloc(sizeof(int) * 10);
    // free(p5),(p6);
    delete p5;
    delete[] p6;
}

int main()
{
    TestMemory();
    //_CrtDumpMemoryLeaks();//仅限vs

    system("pause");
    return 0;
}
#endif
#if 0
#include <stdlib.h>
#include <assert.h>

class Stack
{
private:
    int *_arr;
    // size_t  unsigned int
    size_t _capcaity;
    size_t _size;

public:
    Stack(size_t cap = 10)
    {
        _capcaity = (cap == 0 ? 3 : cap);
        _arr = (int *)malloc(_capcaity * sizeof(int));
        if (nullptr == _arr)
        {
            assert(false);
            return;
        }
        _size = 0;
    }
    void Push(int x) {}
    void Pop() {}
    ~Stack()
    {
        if (_arr)
        {
            free(_arr);
            _arr = nullptr;
            _capcaity = 0;
            _size = 0;
        }
        cout << "~Stack()" << endl;
    }
};

// 测试：对于自定义类型，如果没有匹配起来使用，会有什么后果？
// 程序：要么内存泄漏，要么程序崩溃
       void TestMemory()
{
    // 程序崩溃
    //  Stack *ps1 = (Stack *)malloc(sizeof(Stack));
    //  Stack *ps2 = (Stack *)malloc(sizeof(Stack));

    // // free(ps1);
    // // free(ps2);

    // delete ps1;
    // delete[] ps2;

    // 内存泄漏
    Stack *ps1 = new Stack(10);
    free(ps1);

    //程序崩溃
    Stack* ps1=new Stack[10];
}

int main()
{
    TestMemory();

    system("pause");
    return 0;
}
#endif
#if 0
// 为什么C++没有继续使用malloc/free呢? 而是需要自己提供new和delete?
//
// 原因：C++是面向对象的程序设计语言
// 而C语言中的malloc,只负责从堆上申请空间，并不会用构造方法对对象的空间进行初始化
// free 只将堆空间释放掉，在释放时并不会调用析构函数清理对象中的资源
//
// new:在申请空间之后,也会调用构造方法将空间中的内容初始化处理
// delete:在释放空间前，也会调用析构函数将对象中的资源释放掉。
//
// 疑问：C++为甚不对C语言中的malloc和free进行修改呢?
// 让malloc申请空间成功后调用析构方法，让free释放空间是调用析构函数呢？
//
// 答：C语言和C++是两门语言，malloc和free是C语言标准函数库中的库函数，C++如何去修改库函数呢》
// 而C语言是面向对象的过程，在C语言世界中，根本没有对象这一说，也就不存在构造函数和析构函数，
// C语言中的malloc和free使用稍微麻烦一些
// 所以：C++只能自己重新设计一套内存管理的机制new|delete 同时为了兼容C语言，malloc和free必须保留
class Test
{
private:
    int _t;

public:
    Test(int t = 10)
        : _t(t)
    {
        cout << "Test(int):" << this << endl;
    }
    ~Test()
    {
        cout << "~Test()" << this << endl;
    }
};

void TestMallocFree()
{
    Test *pt = (Test *)malloc(sizeof(Test));
    //...

    free(pt);
}

int main()
{
    TestMallocFree();
    _CrtDumpMemoryLeaks();
    return 0;
}
#endif
#if 0
class Test
{
private:
    int _t;

public:
    Test(int t = 10)
        : _t(t)
    {
        cout << "Test(int):" << this << endl;
    }
    ~Test()
    {
        cout << "~Test()" << this << endl;
    }
};

void TestNewDelete()
{
    int *p = new int(10);
    delete p;

    Test *pt = new Test(10);

    delete pt;
}

void TestNewDeleteArray()
{
    int *p = new int[10];

    delete[] p;

    Test *ps = new Test[10];

    //...

    delete[] ps;
}

int main()
{
    TestNewDeleteArray();
    return 0;
}
#endif
#if 0
class Test
{
private:
    int _t;

public:
    Test(int t = 100)
        : _t(t)
    {
        cout << "Test(int):" << this << endl;
    }
    ~Test()
    {
        cout << "~Test():" << this << endl;
    }
    void *operator new(size_t size)
    {
        void *p = malloc(size);
        cout << p << endl;
        return p;
    }
};

// operator new一般不重载，直接使用系统提供的即可
// 除非有特殊需求，比如：在申请空间的时候需要打印内存地址
void *operator new(size_t size)
{
    void *p = malloc(size);
    cout << p << endl;
    return p;
}

int main()
{
    int *p = new int;
    delete p;

    Test *pt = new Test;
    delete pt;
    _CrtDumpMemoryLeaks();
    return 0;
}
#endif
#if 0
// 申请空间时，打印一些调试信息：那个文件的那个函数的哪一行申请了多少个字节的内存空间
void *operator new(size_t size, const char fileName[], const char funcNeme[], size_t LineNo)
{
    void *p = operator new(size);
    cout << fileName << "_" << funcNeme << "_" << LineNo << ":" << p << "--->" << size << "Byte" << endl;
    return p;
}

void operator delete(void *p, const char fileName[], const char funcName[], size_t LineNo)
{
    cout << fileName << "_" << funcName << "_" << LineNo << ":" << p << endl;
    operator delete(p);
}
// 采用条件编译：如果Debug模式下，在申请空间时候，打印一些调试信息
#if _DEBUG
#define new new (__FILE__, __FUNCDNAME__, __LINE__)

#define delete(p) operator delete(p, __FILE__, __FUNCDNAME__, __LINE__)
#endif

int main()
{
    int *p = (int *)malloc(10 * sizeof(int));
    free(p);

    int *p1 = new int;
    delete (p1);

    int *p2 = new int;
    return 0;
}
#endif

class Date
{
private:
    int _year;
    int _month;
    int _day;

public:
    Date(int year = 1900, int month = 1, int day = 1)
        : _year(year), _month(month), _day(day)
    {
        cout << "Date(int,int,int)" << endl;
    }

    ~Date()
    {
        cout << "~Date()" << endl;
    }
};

Date *New(size_t size)
{
    // 1.申请内存空间
    Date *pd = (Date *)malloc(sizeof(Date));

    // 2.在申请的内存空间上执行构造方法
    new (pd) Date();
    return pd;
}

// 模拟实现delete
void Delete(Date *pd)
{
    if (pd)
    {
        // 注意：析构函数可以调用，但是一般情况不需要自己调用
        // 1.调用析构函数清理对象中的资源
        pd->~Date();
        // 2.调用free释放空间内存
        free(pd);
    }
}

int main()
{
    // d指向的堆空间并不是对象，因为malloc在申请堆空间的时候，并不会调用构造方法
    // 而是和对象大小一样的一块内存空间
    Date *pd = (Date *)malloc(sizeof(Date));

    // 如果可以再d指向的空间上执行构造方法，就可以将d指向的空间变为对象
    // 需要用到placement-new
    new (pd) Date(2022, 11, 26);
    delete pd;

    pd = New(sizeof(Date));
    Delete(pd);

    system("pause");
    return 0;
}
//
