#include <iostream>
using namespace std;
#if 0
// C++中动态申请的资源需要自己手动释放
// 如果操纵不当，容易造成内存泄露
// 能否做到让资源自动被释放：RAII
// RAII:将资源交给对象管理，对象销毁时自动调用析构函数可以在析构函数中将资源释放掉

template <class T>
class smart_ptr
{
public:
    smart_ptr(T *ptr = nullptr)
        : _ptr(ptr)
    {
    }

    // 具有指针类似的效果
    T &operator*()
    {
        return *_ptr;
    }

    T *operator->()
    {
        return _ptr;
    }

    ~smart_ptr()
    {
        if (_ptr)
        {
            delete _ptr;
            _ptr = nullptr;
        }
    }

    T *get()
    {
        return _ptr;
    }

private:
    T *_ptr;
};

void TestSmartPtr1()
{
    // int *p = new int(10);
    // smart_ptr<int> sp(p);

    // //...
    // delete p;

    smart_ptr<int> sp(new int(10));
    *sp = 100;
}

struct A
{
    int a;
    int b;
    int c;
};

void TestSmartPtr2()
{
    smart_ptr<int> sp1(new int(10));
    *sp1 = 100;

    smart_ptr<A> sp2(new A());
    sp2->a = 10;
    sp2->b = 20;
    sp2->c = 30;
}

int main()
{
    TestSmartPtr1();
    TestSmartPtr2();

    system("pause");
    return 0;
}
// 上述smart_ptr已经很好，达到了刚开始的需求
// 新的问题：类中涉及资源的管理时，如果没有显式的实现 拷贝构造函数 以及 赋值运算符重载
// 则编译器则会以浅拷贝的方式进行，smart_ptr就会有问题
// 解决：能够实现深拷贝吗？ 答案：不能
#endif
#if 0
// 智能指针：对原生态指针进行封装，以类的方式管理用户资源，在析构方法中将资源释放掉
// RAII+具有指针类似的行为+如何解决浅拷贝的问题
// 因此，解决浅拷贝的方式不同，实现了不同版本的智能指针

// 第一种智能指针
// C++98 auto_ptr 原理
//  RAII+具有指针类似的行为+资源转移来解决浅拷贝的问题
#include <memory>
class A
{
public:
    A()
    {
        cout << "A::A()" << endl;
    }
    ~A()
    {
        cout << "A::~A()" << endl;
    }

    int _a;
    int _b;
};

void TestAutoPtr()
{
    auto_ptr<A> ap1(new A());
    ap1->_a = 10;
    ap1->_b = 20;

    // 当拷贝构造ap2时候，ap1会将自己管理的资源转移给ap2
    // 然后ap1不在管理了，即：指向空
    auto_ptr<A> ap2(ap1);
    ap2->_a = 100;
    ap2->_b = 200;

    // ap1->_a = 10; //运行崩溃：因为ap1将资源转移之后指向NULL

    auto_ptr<A> ap3;
    // 当ap2给ap3赋值时，ap2会将自己的管理的资源转移给ap3
    // 然后ap2就不在管理资源了，即：指向空
    ap3 = ap2;

    A *pa1 = new A();
    A *pa2 = nullptr;

    pa2 = pa1;
    pa1->_a = 10;
    pa1->_b = 20;
}

int main()
{
    TestAutoPtr();

    system("pause");
    return 0;
}
#endif
#if 0
// C++98中auto_ptr的改造
// RAII+具有指针类似的行为+解决浅拷贝的方式：资源管理权限的转移
// 资源管理权限：对资源释放的权限
namespace Zzxh
{
    template <class T>
    class auto_ptr
    {
        // RAII
    public:
        auto_ptr(T *ptr = nullptr)
            : _ptr(ptr), _owner(false)
        {
            if (_ptr)
            {
                _owner = true;
            }
        }

        ~auto_ptr()
        {
            if (_ptr && _owner)
            {
                delete _ptr;
                _ptr = nullptr;
                _owner = false;
            }
        }

        // 具有指针类似的行为
        T &operator*()
        {
            return *_ptr;
        }

        T *operator->()
        {
            return _ptr;
        }

        // 资源转移
        // 拷贝构造函数
        auto_ptr(const auto_ptr<T> &ap)
            : _ptr(ap._ptr), _owner(ap._owner)
        {
            ap._owner = false;
            return this;
        }

        // 赋值运算符重载
        auto_ptr<T> &operator=(const auto_ptr<T> &ap)
        {
            if (this != &ap)
            {
                if (_ptr && _owner)
                {
                    delete _ptr;
                }
                _ptr = ap._ptr;
                _owner = ap._owner;
                ap._owner = false;
            }
            return *this;
        }

    private:
        T *_ptr;
        mutable bool _owner; // 如果为true,则表示该对象具有释放资源的权限
    };
}
class A
{
public:
    A()
    {
        cout << "A::A()" << endl;
    }
    ~A()
    {
        cout << "A::~A()" << endl;
    }

    int _a;
    int _b;
};

void TestAutoPtr1()
{
    Zzxh::auto_ptr<A> ap1(new A());
    ap1->_a = 10;
    ap1->_b = 20;

    // 当ap1拷贝构造ap2时候，ap1会将自己管理的资源转移给ap2
    // 然后ap1不在进行管理，即：指向空

    Zzxh::auto_ptr<A> ap2(ap1);
    ap2->_a = 100;
    ap2->_b = 200;

    ap1->_a = 10; // 运行成功

    Zzxh::auto_ptr<A> ap3;
    ap3 = ap2;
    A *pa1 = new A();
    A *pa2 = nullptr;

    pa2 = pa1;
    pa1->_a = 10;
    pa1->_b = 20;
    delete pa1;
}
void TestAutoPtr2()
{
    Zzxh::auto_ptr<A> ap1(new A());
    ap1->_a = 10;
    ap1->_b = 20;

    if (1)
    {
        Zzxh::auto_ptr<A> ap2(ap1);
        ap1->_a = 100;
        ap1->_b = 200;
    }

    // 当if结束，ap2已经将资源释放，因此ap1内部就为野指针
    ap1->_a = 1000;
    ap1->_b = 2000;
}
// C++标准建议：什么情况下都不要使用auto_ptr
int main()
{
    TestAutoPtr1();
    TestAutoPtr2();

    system("pause");
    return 0;
}
#endif