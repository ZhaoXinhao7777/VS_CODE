#include <iostream>
using namespace std;
#if 0
//在C语言中，不能再结构体内定义方法
//
struct WashMashine
{
    double lenght;
    double width;
    double height;
    int color;
}
void InitWashMashine(WashMashine *pw)
{
    printf("InitWashMashine\n");
}
void WashClothes(WashMashine *pw)
{
    printf("Wash clothes\n");
}
void DryClothes(WashMashine *pw)
{
    printf("Dry clothes\n");
}
void SetTime(WashMashine *pw)
{
    printf("Set time\n");
}
void Alarm(WashMashine *pw)
{
    printf("Alarm\n");
}
#endif
#if 0
//在C++中，结构体内部可以定义方法
struct WashMashine
{
    double lenght;
    double width;
    double height;
    int color;

    void InitWashMashine(WashMashine *pw)
    {
        printf("InitWashMashine\n");
    }
    void WashClothes(WashMashine *pw)
    {
        printf("Wash clothes\n");
    }
    void DryClothes(WashMashine *pw)
    {
        printf("Dry clothes\n");
    }
    void SetTime(WashMashine *pw)
    {
        printf("Set time\n");
    }
    void Alarm(WashMashine *pw)
    {
        printf("Alarm\n");
    }
}
#endif

#if 0
//类：类中内容就是在对对象进行的描述
class WashMashine
{
public:
    double lenght;
    double width;
    double height;
    int color;

    //对洗衣机功能的描述
    void InitWashMashine(WashMashine *pw)
    {
        printf("InitWashMashine\n");
    }
    void WashClothes(WashMashine *pw)
    {
        printf("Wash clothes\n");
    }
    void DryClothes(WashMashine *pw)
    {
        printf("Dry clothes\n");
    }
    void SetTime(WashMashine *pw)
    {
        printf("Set time\n");
    }
    void Alarm(WashMashine *pw)
    {
        printf("Alarm\n");
    }
};
int main()
{
    //w就是对象
    WashMashine w;
    

    system("pause");
    return 0;
}
#endif

#if 0
#include <cstdlib>

//stack
struct Stack
{
    //成员变量 成员数据 属性
    int *arr;
    int size;
    int capacity;

    //成员方法 成员函数 功能
    bool IsEmpty()
    {
        return size==0;
    }
    void Init(int cap=10)
    {
        arr=(int*)malloc(cap);
        capacity=cap;
        size=0;
    }
    void Push(int x)
    {
        //检测是否要扩容
        //CheckCapacity();
        
        arr[size]=x;
        size++;
    }
    void Pop()
    {
        if(IsEmpty())
        {
            return;
        }
        size--;
    }
    int Top()
    {
        if(size==0)
        return -1;

        return arr[size-1];
    }
    int Size()
    {
        return size;
    }
    void Destory()
    {

        free(arr);
        arr=nullptr;
        size=0;
        capacity=0;
    }
};

int main()
{
    Stack s;
    s.Init();
    s.Push(1);
    s.Push(2);
    s.Push(3);
    s.Push(4);
    
    cout<<s.Top()<<endl;

    s.Pop();
    s.Pop();
    cout<<s.Top()<<endl;

    s.Destory();
    
    system("pause");
    return 0;
}
#endif
#if 0
#include <stdlib.h>

typedef int DataType;

struct Stack
{
public:
    Stack()
    {
        m_arr=(DataType*)malloc(10*(sizeof(DataType)));
        if(NULL==m_arr)
        {
            return;
        }

        m_capacity=10;
        m_size=0;

        cout<<"stack():"<<this<<endl;
    }
    void Push(DataType data)
    {
        //_checkCapacity();
        m_arr[m_size]=data;
        m_size++;
    }
    void Pop()
    {
        if(Empty())
        {
            return;
        }

        m_size--;
    }
    DataType Top()
    {
        return m_arr[m_size-1];
    }
    bool Empty()
    {
        return 0==m_size;
    }
    int Size()
    {
        return m_size;
    }
    ~Stack()
    {
        if(m_arr)
        {
            free(m_arr);
            m_arr=nullptr;
            m_capacity=0;
            m_size=0;
        }
        cout<<"~Stack"<<this<<endl;
    }
private:
    void _checkCapacity()
    {
        //待补全
    }

private:
    DataType *m_arr;
    size_t m_capacity;
    size_t m_size;
};

void TestStack()
{
    Stack s;
    s.Push(5);
    s.Push(4);
    s.Push(3);
    s.Push(2);
    s.Push(1);

    cout<<"s.Top()="<<s.Top()<<endl;
    cout<<"s.Size()="<<s.Size()<<endl;

    s.Pop();
    s.Pop();
    
    cout<<"s.Top()="<<s.Top()<<endl;
    cout<<"s.Size()="<<s.Size()<<endl; 
}

int main()
{
    TestStack();

    system("pause");
    return 0;
}
#endif
#if 0
/*
注意:
像Data类一样，如果对象没有设计任何资源管理的时候
该类的析构函数可不用给出
*/
class Date
{
public:
    Date(int year=1900,int month=1,int day=1)
    {
        m_year=year;
        m_month=month;
        m_day=day;
    }
    void Print()
    {
        cout<<m_year<<" "<<m_month<<" "<<m_day<<endl;
    }
    ~Date()
    {
        cout<<"~Date():"<<this<<endl;
    }
private:
    int m_year;
    int m_month;
    int m_day;
};

void TestDate()
{
    Date d(2020,11,12);
    d.Print();
}
int main()
{
    TestDate();

    system("pause");
    return 0;
}
#endif
#if 0
class Date
{
public:
    Date(int year=1900,int month=1,int day=1)
    {
        m_year=year;
        m_month=month;
        m_day=day;
    }

    //拷贝构造
    Date(const Date& d)
    {
        m_year=d.m_year;
        m_month=d.m_month;
        m_day=d.m_day;
    }

    void Print()
    {
        cout<<m_year<<" "<<m_month<<" "<<m_day<<endl;
        cout<<this<<endl;
    }
private:
    int m_year;
    int m_month;
    int m_day;
};

int main()
{
    int a1;
    int a2=10;
    int a3(6);
    int a4=a3;
    int a5(a4);

    Date d1(2022,11,12);
    //...
    //d1++;

    //需求：d2创建好后，想和第一中的日期完全相同
    //Date d2(2022,11,12);
    Date d2(d1);
    d1.Print();
    d2.Print();

    system("pause");
    return 0;


}
#endif
#if 0
#include "Student.h"
int main()
{
    //strcpy(Student.m_name,"peter");    

    //用Student类定义出来的s1,s2,s3都是对象

    Student s1;
    s1.InitStudent("XiaoMing","boy",18,76);
    s1.Print();
    s1.DoClass();
    s1.DoHomework();
    s1.Exam();
    cout<<s1.m_name<<endl;
    cout<<s1.m_gender<<endl;
    cout<<"-----"<<endl;
    Student s2;
    s2.InitStudent("Alax","girl",16,100);
    s2.Print();

    Student s3;
    s3.InitStudent("Ts","women",36,78);
    s3.Print();

    system("pause");
    return 0;
}
#endif
#if 0
// 定义不应放在函数之前吗？ 待解决

class Date
{
    // 一般情况下，成员方法的权限是公有的，成员变量的权限的私有的
    // 成员的权限到底应该设置为公有还是私有，需根据应用场景来
public:
    void InitDate(int year, int month, int day)
    {
        m_year = year;
        m_month = month;
        m_day = day;
    }
    void Print()
    {
        cout << m_year << " " << m_month << " " << m_day << endl;
    }

    int m_year;
    int m_month;
    int m_day;
};

// 结论：只要将类中的"成员变量"加起来，但是要注意内存对齐
// 即：和计算结构体的方法是一样的

int main()
{
    Date d;
    d.InitDate(2022, 11, 8);
    d.Print();

    Date dd;
    dd.InitDate(2022, 11, 9);
    dd.Print();

    cout << sizeof(Date) << endl;
    cout << sizeof(d) << endl;
    return 0;
}
#endif
#if 0
// 用C语言实现上述相同操作
struct Date
{
    int year;
    int month;
    int day;
};
void InitDate(struct Date *pthis, int year, int month, int day)
{
    pthis->year = year;
    pthis->month = month;
    pthis->day = day;
}

void Print(struct Date *pthis)
{
    printf("%d %d %d\n", pthis->year, pthis->month, pthis->day);
}
int main()
{
    struct Date d1;
    InitDate(&d1, 2022, 11, 12);
    Print(&d1);

    system("pause");
    return 0;
}
#endif
#if 0
class A
{
public:
    void Func()
    {}
    int m_a;
};
class B
{
public:
    void Func(int)
    {}
};

// 空类
class C
{};
//
// 空类的大小为什么是1不是0？
int main()
{
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;
    cout << sizeof(C) << endl;
    // 4 1 1

    B b1, b2, b3;
    cout << &b1 << " " << &b2 << " " << &b3 << endl;
    // 0x62fe1f 0x62fe1e 0x62fe1d
    int a, b, c;
    system("pause");
    return 0;
}
#endif
#if 0
// this存储在栈上
class Date
{
public:
    void InitDate(int year, int month, int day)
    {
        Date *const &p = this;
        cout << &p << endl;
        m_year = year;
        m_month = month;
        m_day = day;
    }

    void Print()
    {
        cout << m_year << " " << m_month << " " << m_day << endl;
    }
    int m_year;
    int m_month;
    int m_day;
};

int main()
{
    Date d1;
    d1.InitDate(2022, 11, 9); // 编译之后：Date::InitDate(&d1,2022,11,9);

    d1.Print(); // Date::Print(&d1);

    Date d2;
    d2.InitDate(2022, 11, 10);
    d2.Print();

    system("pause");
    return 0;
}
#endif
#if 0
// this是否为空  可以为空
class A
{
public:
    void Print()
    {
        cout << this << endl;
        cout << this->m_a << endl;
        cout << "Print()" << endl;
    }

private:
    int m_a;
};

int main()
{
    A a;
    a.Print();

    A *pa = &a;
    pa->Print();

    pa = nullptr;
    // pa->Print(); // 段错误
    cout << sizeof(A) << endl;//4
    cout << sizeof(a) << endl;//4
    // 0x62fe14
    // 0
    // Print()
    // 0x62fe14
    // 0
    // Print()

    system("pause");
    return 0;
}
#endif
#if 0
// 变量在使用时，编译器必须先看到改变量的定义或者声明
// int a = 10;
int main()
{
    printf("%d", a);
    return 0;
}
int a = 10;
#endif

#if 0
//
// 变量在使用时，编译器必须先看到改变量的声明或者定义
// 但，在类的定义中，成员变量定义在后，成员变量在函数中使用在前
// 为什莫编译器不报错？
// 搞清楚这个问题，必须知道编译器如何处理类的
//
// 假设你没女朋友，请朋友介绍一个
// 女性朋友：群体 类别
// 特征：年龄，身高，胖瘦，长相
// 要求：会做饭，唱歌，跳舞

// 编译器如何处理类的
// 1.识别类名
// 2.编译器在识别类中成员变量
// 3.最后是被类中的成员方法 & 对类中的成员方法进行修改
//      修改：a.还原this指针
//           b.所有成员变量通过this访问

class Date
{
public:
    /*
        void InitDate(Date *const this, int year, int month, int day)
        {
            this->m_year = year;
            this->m_month = month;
            this->m_day = day;
        }
    */
    void InitDate(int year, int month, int day)
    {
        this->m_year = year;
        this->m_month = month;
        this->m_day = day;
    }
/*
    void Print(Date *const this)
    {
        cout << this->m_year << " " << this->m_month << " " << this->m_day << endl;
    }
*/
    void Print()
    {
        cout << m_year << " " << m_month << " " << m_day << endl;
    }

private:
    int m_year;
    int m_month;
    int m_day;
};
#endif
#if 0
class Date
{
public:
    void Init(int year, int month, int day)
    {
        m_year = year;
        m_month = month;
        m_day = day;
    }
    void Print()
    {
        cout << m_year << " " << m_month << " " << m_day << endl;
    }

private:
    int m_year;
    int m_month;
    int m_day;
};

int main()
{
    // 先定义变量，然后给变量赋值
    int a;
    a = 10;

    // 定义并初始化
    int b = 20;
    int c(10);

    Date d1;
    // d1.m_year = 2022;
    d1.Init(2022, 11, 12);
    d1.Print();

    Date d2;
    d2.Init(2022, 11, 13);
    d2.Print();

    // 需求：能否在对象创建好之后，就把初始值设置进去。
    // 就不需要Init方法了
    // Date d3(2022, 12, 14);
    // d3.Print();

    return 0;
}
#endif
#if 0
// 构造函数：特殊的成员函数
// 函数名必须和类名相同，而且不能有返回值
// 在创建对象时编译器调用，在整个对象的生命周期内只调用一次
// 目的：给对象中的成员变量设置合适的初始值

class Date
{
public:
    Date(int year, int month, int day)
    {
        m_year = year;
        m_month = month;
        m_day = day;

        cout << "Date(int int int)" << this << endl;
    }

    Date()
    {
        m_year = 1900;
        m_month = 1;
        m_day = 1;
    }
    void Init(int year, int month, int day)
    {
        m_year = year;
        m_month = month;
        m_day = day;
    }
    void Print()
    {
        cout << m_year << " " << m_month << " " << m_day << endl;
    }

private:
    int m_year;
    int m_month;
    int m_day;
};
void TestDate()
{
    Date dd(2022, 11, 12);
    dd.Print();
}
int main()
{
    // TestDate();
    Date d1(2022, 11, 12);
    d1.Print();

    Date d2;
    d2.Print();
    // 注意：d3并不是创建一个新对象，而是一个函数声明
    // 即，编译器认为声明了一个函数名为d3，没有参数，返回值类型为Date类型的函数
    // d3.Print();编译报错
    // 当调用构造函数创建对象时，对象之后的括号必须省略
    Date d3();
    // d3.Print(); // 编译报错，认为是一个 d3是Date(*)()函数指针

    system("pause");
    return 0;
}
#endif
#if 0

class Date
{
public:
    Date(int year, int month, int day)
    {
        m_year = year;
        m_month = month;
        m_day = day;
    }
    void Print()
    {
        cout << m_year << " " << m_month << " " << m_day << endl;
    }

private:
    int m_year;
    int m_month;
    int m_day;
};

int main()
{
    // 注意：如果用户没有显式实现任何构造方法
    // 编译器会给该类生成一个无参的默认构造方法

    // Date d;//报错，因为已经提供了构造方法，编译器不会再生产默认构造方法

    return 0;
}
#endif
#if 0
// 如果用户并没有显示定义任何方法，则编译器会生成一份无参数的默认构造方法
// 问题：无参构造的方法有用吗？
// 注意下面Date类例子，编译器的无参构造意义不大
// 但并不代表没有意义
class Date
{
public:
    // 编译器生成的无参构造方法和下面类似，即什么作用都没

    Date() {}
    void Print()
    {
        cout << m_year << " " << m_month << " " << m_day << endl;
    }

private:
    int m_year;
    int m_month;
    int m_day;
};

int main()
{
    Date d;
    d.Print();

    return 0;
}
#endif
#if 0
class Time
{
public:
    Time(int hour = 0, int minute = 0, int second = 0)
    {
        m_hour = hour;
        m_minute = minute;
        m_second = second;
        cout << "Time(int, int, int)" << endl;
    }
    void Print()
    {
        cout << m_hour << " " << m_minute << " " << m_second << endl;
    }

private:
    int m_hour;
    int m_minute;
    int m_second;
};

class Date
{
public:
    // 编译器生成的无参构造方法和下类似，即什么作用都没有
    // Date()
    // {
    // call Time::Time();
    // }
    void Print()
    {
        cout << m_year << " " << m_month << " " << m_day << endl;
    }

private:
    int m_year;
    int m_month;
    int m_day;
};

int main()
{
    Date d;
    d.Print();

    return 0;
}
#endif
#if 0
// C++ 语法规定
// 在类中，如果用户没有显式定义任何构造函数
// 编译器一定会生成一份无参构造函数

class Date
{
public:
    Date() {}
    void Print()
    {
        cout << m_year << " " << m_month << " " << m_day << endl;
    }

private:
    int m_year;
    int m_month;
    int m_day;
};

int main()
{
    Date d;
    d.Print();
    return 0;
}
#endif
#if 0
class Time
{
public:
    Time(int hour = 0, int minute = 0, int second = 0)
    {
        m_hour = hour;
        m_minute = minute;
        m_second = second;
        cout << "Time(int,int,int)" << endl;
    }

    void Print()
    {
        printf("%02d%02d%02d\n", m_hour, m_minute, m_second);
    }

private:
    int m_hour;
    int m_minute;
    int m_second;
};
class Date
{
public:
    void Print()
    {
        cout << m_year << " " << m_month << " " << m_day << endl;
    }

private:
    // C++11提供
    int m_year = 1900;
    int m_month = 1;
    int m_day = 1;

public:
    Time t;
};
int main()
{
    Date d;
    d.Print();
    d.t.Print();
    system("pause");
    return 0;
}
#endif

// 无参的构造函数和缺省函数都成为默认构造函数
// 并且默认构造函数只能有一个
class Date
{
public:
    // 全缺省的构造函数
    Date(int year = 1900, int month = 1, int day = 1)
    {
        m_year = year;
        m_month = month;
        m_day = day;
    }
    void Print()
    {
        cout << m_year << " " << m_month << " " << m_day << endl;
    }
    // 无参的构造函数
    // Date()
    // {
    // m_year = 1900;
    // m_month = 1;
    // m_day = 1;
    // }

private:
    // C++11提供
    int m_year;
    int m_month;
    int m_day;
};
int main()
{
    Date d1(2022, 11, 12);
    Date d2;

    return 0;
}
