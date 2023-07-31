#include <iostream>
using namespace std;

#if 0
#include <memory>
void TestSharePtr()
{
    shared_ptr<int> sp1(new int(10));
    shared_ptr<int> sp2(sp1);
    cout << *sp1 << " " << *sp2 << endl;
    cout << sp1 << " " << sp2 << endl;
    cout << &sp1 << " " << &sp2 << endl;

    shared_ptr<int> sp3;
    sp3 = sp1;
    *sp3 = 200;
    cout << *sp1 << " " << *sp2 << endl;
    cout << sp1 << " " << sp2 << endl;
    cout << &sp1 << " " << &sp2 << endl;

    // 10 10
    // 0x6524b0 0x6524b0
    // 0x62fe00 0x62fdf0

    // 200 200
    // 0x6524b0 0x6524b0
    // 0x62fe00 0x62fdf0

    cout << sp1.get() << endl;
    // 0x6524b0
}
int main()
{
    TestSharePtr();
    // _CrtDumpMemoryLeaks();
    system("pause");
    return 0;
}
#endif
#if 0
// shared_ptr : RAII + 具有指针类似的行为 + 引用计数
// 资源可以共享：浅拷贝的基础上，可以保证资源不论有多少个，最终只释一次

namespace Zzxh
{
    template <class T>
    class DFDef
    {
    public:
        // ()运算符重载
        void operator()(T*& ptr)
        {
            if (ptr)
            {
                delete ptr;
                ptr = nullptr;
            }
        }
    };

    template <class T, class DF = DFDef<T>>
    class shared_ptr
    {
    public:
        shared_ptr(T* ptr = nullptr)
            : _ptr(ptr), _count(0)
        {
            if (_ptr)
            {
                _count = 1;
            }
        }
        ~shared_ptr()
        {
            if (_ptr && --_count == 0)
            {
                DF()
                    (_ptr);
            }
        }
        // 具有指针类似行为
        T& operator*()
        {
            return *_ptr;
        }
        T* operator->()
        {
            return _ptr;
        }

        // 解决浅拷贝，引用计数
        shared_ptr(shared_ptr<T>& sp)
            : _ptr(sp._ptr), _count(++sp._count)
        {
        }

    private:
        T* _ptr;
        int _count; // 计数有问题，不能是普通的成员变量，必须要能够共享
        // static int _count;// 计数有问题：静态成员变量是所有对象共享的，而现在需要的计数应该和资源的份数对应起来，因为记录的是一份资源被多少个对象使用
    };

}

void TestSharePtr()
{
    Zzxh::shared_ptr<int> sp1(new int(10));
    Zzxh::shared_ptr<int> sp2(sp1);
}

int main()
{
    TestSharePtr();

    _CrtDumpMemoryLeaks();

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
        // ()运算符重载
        void operator()(T*& ptr)
        {
            if (ptr)
            {
                delete ptr;
                ptr = nullptr;
            }
        }
    };

    template <class T, class DF = DFDef<T>>
    class shared_ptr
    {
    public:
        shared_ptr(T* ptr = nullptr)
            : _ptr(ptr)
        {
            if (_ptr)
            {
                _count = 1;
            }
        }
        ~shared_ptr()
        {
            if (_ptr && --_count == 0)
            {
                DF()
                    (_ptr);
            }
        }
        // 具有指针类似行为
        T& operator*()
        {
            return *_ptr;
        }
        T* operator->()
        {
            return _ptr;
        }

        // 解决浅拷贝，引用计数
        shared_ptr(shared_ptr<T>& sp)
            : _ptr(sp._ptr)
        {
            _count++;
        }

    private:
        T* _ptr;
        // int _count; // 计数有问题，不能是普通的成员变量，必须要能够共享
        static int _count;// 计数有问题：静态成员变量是所有对象共享的，而现在需要的计数应该和资源的份数对应起来，因为记录的是一份资源被多少个对象使用
    };

    template<class T, class DF>
    int Zzxh::shared_ptr<T, DF>::_count = 0;
}

void TestSharePtr()
{
    Zzxh::shared_ptr<int> sp1(new int(10));
    Zzxh::shared_ptr<int> sp2(sp1)

        Zzxh::shared_ptr<int> sp3(new int(100));
}

int main()
{
    TestSharePtr();

    _CrtDumpMemoryLeaks();

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
        // ()运算符重载
        void operator()(T*& ptr)
        {
            if (ptr)
            {
                delete ptr;
                ptr = nullptr;
            }
        }
    };

    template <class T, class DF = DFDef<T>>
    class shared_ptr
    {
    public:
        shared_ptr(T* ptr = nullptr)
            : _ptr(ptr), _pcount(nullptr)
        {
            if (_ptr)
            {
                _pcount = new int(1);
            }
        }
        ~shared_ptr()
        {
            Release();
        }
        // 具有指针类似行为
        T& operator*()
        {
            return *_ptr;
        }
        T* operator->()
        {
            return _ptr;
        }

        // 解决浅拷贝，引用计数
        shared_ptr(const shared_ptr<T>& sp)
            : _ptr(sp._ptr), _pcount(sp._pcount)
        {
            ++(*_pcount);
        }
        shared_ptr<T>&operator=(const shared_ptr<T>& sp)
        {
            if (this != &sp)
            {
                //不理解调试一遍代码即可
                //1.先让*this和离开之前的资源
                Release();

                //2.*this和sp共享资源和计数
                _ptr = sp._ptr;
                _pcount = sp._pcount;
                ++(*_pcount);
            }
            return *this;
        }
    private:

        void Release()
        {
            if (_ptr && 0 == --(*_pcount))
            {
                DF()(_ptr);
                delete _pcount;
                _pcount = nullptr;
            }
        }
        T* _ptr;
        int* _pcount;
    };

}

#endif
#include <mutex>
namespace Zzxh
{
    template <class T>
    class DFDef
    {
    public:
        // ()运算符重载
        void operator()(T *&ptr)
        {
            if (ptr)
            {
                delete ptr;
                ptr = nullptr;
            }
        }
    };

    template <class T, class DF = DFDef<T>>
    class shared_ptr
    {
    public:
        shared_ptr(T *ptr = nullptr)
            : _ptr(ptr), _pcount(nullptr), _pMutex(nullptr)
        {
            if (_ptr)
            {
                _pcount = new int(1);
                _pMutex = new mutex();
            }
        }
        ~shared_ptr()
        {
            Release();
        }
        // 具有指针类似行为
        T &operator*()
        {
            return *_ptr;
        }
        T *operator->()
        {
            return _ptr;
        }

        // 解决浅拷贝，引用计数
        shared_ptr(const shared_ptr<T> &sp)
            : _ptr(sp._ptr), _pcount(sp._pcount), _pMutex(sp._pMutex)
        {
            AddRef();
        }
        shared_ptr<T> &operator=(const shared_ptr<T> &sp)
        {
            if (this != &sp)
            {
                // 不理解调试一遍代码即可
                // 1.先让*this和离开之前的资源
                Release();

                // 2.*this和sp共享资源和计数
                _ptr = sp._ptr;
                _pcount = sp._pcount;
                _pMutex = sp._pMutex;
                AddRef();
            }
            return *this;
        }
        T *get()
        {
            return _ptr;
        }

    private:
        void AddRef()
        {
            _pMutex->lock();
            ++(*_pcount);
            _pMutex->unlock();
        }

        void Release()
        {
            bool flag = false;
            _pMutex->lock();
            if (_ptr && 0 == --(*_pcount))
            {
                DF()
                (_ptr);
                delete _pcount;
                _pcount = nullptr;

                flag = true;
            }
            _pMutex->unlock();

            if (flag)
            {
                delete _pMutex;
                _pMutex = nullptr;
            }
        }
        T *_ptr;
        int *_pcount;
        mutex *_pMutex;
    };

}
void TestSharePtr()
{
    Zzxh::shared_ptr<int> sp1(new int(10));
    Zzxh::shared_ptr<int> sp2(sp1);

    Zzxh::shared_ptr<int> sp3(new int(100));

    Zzxh::shared_ptr<int> sp4(sp3);

    sp3 = sp2; // sp1,sp2,sp3 共享, sp4 独享
}
struct Date
{
    int _year = 0;
    int _month = 0;
    int _day = 0;
};
#if 0
//C++11下的线程安全 标准库
//线程安全如何判断？
// 1.程序是否正常退出
// 2.是否有内存泄漏
void SharePtrFunc(std::shared_ptr<Date>& sp, size_t n,mutex& mtx)
{
    cout << sp.get() << endl;
    for (size_t i = 0; i < n; i++)
    {
        std::shared_ptr<Date> copy(sp);
        //需要程序猿自己实现对资源访问的安全
        unique_lock<mutex> lk(mtx);
        copy->_year++;
        copy->_month++;
        copy->_day++;
    }
}

void TestSharedPtr3()
{
    std::shared_ptr<Date> sp(new Date);
    cout << sp.get() << endl;

    size_t n = 1000;
    mutex m;
    thread t1(SharePtrFunc,std::ref(sp), n, std::ref(m));
    thread t2(SharePtrFunc,std::ref(sp), n, std::ref(m));

    t1.join();
    t2.join();

    cout << sp->_year << endl;
    cout << sp->_month << endl;
    cout << sp->_day << endl;
}
#endif
#if 0
void SharePtrFunc(Zzxh::shared_ptr<Date>& sp, size_t n, mutex& mtx)
{
    cout << sp.get() << endl;
    for (size_t i = 0; i < n; i++)
    {
        Zzxh::shared_ptr<Date> copy(sp);
        //需要程序猿自己实现对资源访问的安全
        //范围锁
        unique_lock<mutex> lk(mtx);
        copy->_year++;
        copy->_month++;
        copy->_day++;
    }
}

void TestSharedPtr3()
{
    Zzxh::shared_ptr<Date> sp(new Date);
    cout << sp.get() << endl;

    size_t n = 1000;
    mutex m;
    thread t1(SharePtrFunc, std::ref(sp), n, std::ref(m));
    thread t2(SharePtrFunc, std::ref(sp), n, std::ref(m));

    t1.join();
    t2.join();

    cout << sp->_year << endl;
    cout << sp->_month << endl;
    cout << sp->_day << endl;
}

#include <thread>
int main()
{
    //TestSharePtr();
    //thread t1, t2;
    TestSharedPtr3();
    _CrtDumpMemoryLeaks();

    system("pause");
    return 0;
}
#endif

using namespace std;
#if 0
struct ListNode
{
    ListNode* next;
    ListNode* prev;
    int data;

    ListNode(int x = 0)
        :next(nullptr)
        ,prev(nullptr)
        ,data(x)
    {}
};
#endif
