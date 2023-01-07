#include <iostream>
using namespace std;
#if 0
class Date
{
public:
    Date(int year = 1900, int month = 1, int day = 1)
    {
        m_year = year;
        m_month = month;
        m_day = day;
    }
    Date(const Date &d)
    {
        m_year = d.m_year;
        m_month = d.m_month;
        m_day = d.m_day;
        cout << "Date(const Date& d):" << this << endl;
    }
    ~Date()
    {
        cout << "~Date()" << this << endl;
    }

private:
    int m_year;
    int m_month;
    int m_day;
};

void TestDate1()
{
    // 只要是创建对象，就必须调用构造函数
    // 拷贝构造是：用已经存在的对象构造新对象时调用
    // 其余创建新对象的场景调用的基本都是构造函数

    Date d1(2022, 11, 15);

    // 拷贝构造函数调用场景1
    Date d2(d1);
}

// 拷贝构造函数调用场景2：以值传递的方式传参对象
void TestDate2(Date d)
{
    Date dd;
}

// 拷贝构造函数调用场景3：以值的方式返回对象
Date TestDate3()
{
    Date d;
    return d;
}

// Vs_2019
// 注意：
// 1.以值的方式返回时，如果返回的是匿名对象，则编译器不对匿名对象
// 拷贝构造临时对象，而是直接将其返回
// 匿名对象：没有名字的对象

// 2.如果参数时以值的方式传递，实参如果也是匿名对象，也会少一次拷贝构造

// 3.在C ++中，参数能使用引用尽量使用引用，如果不想通过形参修改外部实参，
// 将其设置为const类型的引用

int main()
{
    Date md;
    TestDate1();
    TestDate2(md);
    TestDate3();
    TestDate2(Date(2022, 11, 15));

    system("pause");
    return 0;
}
#endif
#if 0

class Date
{
public:
    Date(int year = 1900, int month = 1, int day = 1)
    {
        _year = year;
        _month = month;
        _day = day;
        cout << "Date(int,int,int):" << this << endl;
    }
    Date(const Date &d)
    {
        _year = d._year;
        _month = d._month;
        _day = d._day;
        cout << "Date(const Date& d):" << this << endl;
    }

    ~Date()
    {
        cout << "~Date():" << this << endl;
    }

private:
    int _year;
    int _month;
    int _day;
};

void Test()
{
    Date d1(2022, 11, 15); // 构造函数
    Date d2(d1);           // 拷贝构造函数
    Date d3;
    d3 = d2; // 用已经存在的对象给另一个已经存在的对象赋值

    Date d4 = d3; // 拷贝构造
}

int main()
{
    Test();
    return 0;
}
#endif
#if 0
#include <stdlib.h>
typedef int DataType;

class Stack
{
public:
    Stack(size_t capacity = 10)
    {
        m_arr = (DataType *)malloc(sizeof(DataType) * capacity);

        if (nullptr == m_arr)
        {
            perror("malloc申请空间失败\n");
            return;
        }
        m_size = 0;
        m_capacity = capacity;
    }
    void Push(const DataType &data)
    {
        // ChechCapacity();
        m_arr[m_size] = data;
        m_size++;
    }
    ~Stack()
    {
        if (m_arr)
        {
            free(m_arr);
            m_arr = nullptr;
            m_capacity = 0;
            m_size = 0;
        }
    }

private:
    DataType *m_arr;
    size_t m_size;
    size_t m_capacity;
};
void TestStack()
{
    Stack s1;
    s1.Push(2);
    s1.Push(4);
    s1.Push(6);
    s1.Push(8);
    s1.Push(10);

    Stack s2;
    // 如果调用编译器默认生成的赋值运算符重载，问题：
    // 1.内存泄漏 2.浅拷贝导致程序崩溃
    s2 = s1;
}

int main()
{
    TestStack();
    return 0;
}
#endif
#if 0
class Date
{
public:
    Date(int year = 1900, int month = 1, int day = 1)
    {
        m_year = year;
        m_month = month;
        m_day = day;
    }
    Date(const Date &d)
    {
        m_year = d.m_year;
        m_month = d.m_month;
        m_day = d.m_day;
    }

    // 需求：检测两个日期类型对象是否相等
    bool IsEqual(const Date &d)
    {
        return m_year == d.m_year &&
               m_month == d.m_month &&
               m_day == d.m_day;
    }
    bool operator==(const Date &d)
    {
        return m_year == d.m_year &&
               m_month == d.m_month &&
               m_day == d.m_day;
    }

    // private:
    int m_year;
    int m_month;
    int m_day;
};
bool operator<(const Date &left, const Date &right)
{
    return left.m_day < right.m_day;
}
// 在operator之后跟的一定是C++ 语言支持的运算符
// 不能凭空自己臆造运算符
// bool operator@(const Date &left, const Date &right)
// {
//     return left.m_day > right.m_day;
// }

// 重载操作符必须有一个类类型参数
Date &operator+=(Date &d, int days)
{
    d.m_day += days;
    return d;
}

//"operator +"必须至少有一个类类型的形参
// int operatoe + (int a, int b)
//{
//   return a + b;
//}

// 重载的运算符必须满足其含义
//  Date &operator-=(Date&d,int days)
//  {
//      d.m_day+=days;
//      return d;
// }

//.*  :: sizeof ?:  .不可重载

int main()
{
    Date d1(2022, 11, 15);
    Date d2(d1);

    if (d1.IsEqual((d2)))
    {
        cout << "d1==d2" << endl;
    }
    else
    {
        cout << "d1!=d2" << endl;
    }

    int a = 10;
    int b = a;
    // 内置类型变量可以直接用==检测是否相等
    if (a == b)
    {
        cout << "a==b" << endl;
    }
    else
    {
        cout << "a!=b" << endl;
    }

    // 注意:自定义类型不支持==的运算符
    // 因为编译器不知道怎么该进行比较
    // 如果一定要用==来进行比较自定义类型的对象
    // 就必须告诉编译器比较规则-->运算符重载
    if (d1 == d2)
    // if(d1.operator==(d2))
    {
        cout << "d1==d2" << endl;
    }
    else
    {
        cout << "d1!=d2" << endl;
    }
    d1 < d2;
    return 0;
}
#endif
#if 0
class Date
{
public:
    Date(int year = 1900, int month = 1, int day = 1)
    {
        _year = year;
        _month = month;
        _day = day;
    }

    Date(const Date &d)
    {
        _year = d._year;
        _month = d._month;
        _day = d._day;
    }

    bool operator==(const Date &d)
    {
        return _year == d._year &&
               _month == d._month &&
               _day == d._day;
    }

    // 赋值运算符必须要符合其含义
    // d2=d1;       可以
    // d3=d2=d1;    可以
    // d2=d1        -->d2.operator(d1);
    // d2传给this    d1传给d

    Date &operator=(const Date &d)
    {
        if (this != &d)
        {
            _day = d._day;
            _month = d._month;
            _year = d._year;
        }

        // return d;
        return *this;
    }

    // private:
    int _year;
    int _month;
    int _day;
};
/*
// 报错： "operator ="必须是非静态成员
// 赋值运算符必须重载成成员函数
// 因为：类中没有显示实现，则编译器会默认生成一份
// 和全局冲突

Date operator=(Date &left, const Date &right)
{
    left._year = right._year;
    left._month = right._month;
    left._day = right._day;
    return left;
}
*/

int main()
{
    int a = 10;
    int b = 20;
    int c = 30;
    c = b = a; // 依次执行 b=a 然后用c=b
    Date d1(2022, 11, 15);
    Date d2;

    d2 = d1;
    Date d3;
    Date &d4 = d3;

    d3 = d2 = d1; // d3.operator(d2.operator(d1));

    d3 = d3; // 自己给自己赋值

    d4 = d3;
    return 0;
}
#endif
#if 0
class Date
{
public:
    Date(int year = 1900, int month = 1, int day = 1)
    {
        _year = year;
        _month = month;
        _day = day;
    }

    Date(const Date &d)
    {
        _year = d._year;
        _month = d._month;
        _day = d._day;
    }

    bool operator==(const Date &d)
    {
        return _year == d._year &&
               _month == d._month &&
               _day == d._day;
    }

    Date &operator=(const Date &d)
    {
        if (this != &d)
        {
            _year = d._year;
            _month = d._month;
            _day = d._day;
        }

        return *this;
    }
    // 前置++
    Date &operator++()
    {
        _day += 1;
        return *this;
    }
    // 后置++
    //  语法中，为了区分前置++和后置++
    //  规定：给后置++多添加了一个int类型的参数
    //  目的是为了让前置++和后置++形成重载
    Date operator++(int)
    {
        Date temp(*this);
        _day += 1;
        return temp;
    }

    // 前置--
    Date &operator--()
    {
        _day -= 1;
        return *this;
    }
    // 后置--
    Date operator--(int)
    {
        Date temp(*this);
        _day -= 1;
        return temp;
    }

private:
    int _year;
    int _month;
    int _day;
};
int main()
{
    int a=10;
    int ret=a++;
    cout<<a<<" "<<ret<<endl;
    ret=++a;
    cout<<a<<" "<<ret<<endl;

    Date d1(2022,11,15);
    Date d2;
    d2=d1++;

    d2=++d1;

    return 0;
}
#endif
// 2022-11-15-->517
#if 0
class Date
{
public:
    Date(int year = 1900, int month = 1, int day = 1)
    {
        _year = year;
        _month = month;
        _day = day;
    }

    // this的类型：Date* const -->this的指向不能修改，this指向空间中的内容可以修改
    // 可写入：可以修改成员变量
    void Show()
    {
        _day += 1;
        cout << _year << " " << _month << " " << _day << endl;
    }
    // const成员函数：被const修饰的成员函数
    // 特性：不能修改"成员变量"
    // const修饰成员函数，实际是在修饰this指针
    // this的类型：const Date* const只读：只能读取this中的成员，不能修改
    void Print() const
    {
        //_day+=1;
        // this->_day += 1;

        int a = 10;
        a = 100;
        cout << _year << " " << _month << " " << _day << endl;
    }
    // 如果成员函数内部一定不会修改成员变量
    // 该成员函数设置为const成员函数

    int GetYear() const
    {
        return _year;
    }
    void SetYear(int year)
    {
        _year = year;
    }

private:
    int _year;
    int _month;
    int _day;
};
void TestDate()
{
    Date d1(2022, 11, 15);
    d1.Print();

    // d1._year=2023;
    // 如果要设置，只能提供公有方法

    // 需求：d2创建好之后，不允许被修改
    // d2成为const类型对象
    const Date d2(d1);
    d2.Print();
    // d2.show();//const对象不能调用普通成员函数
    // 报错，因为_year是私有的
    // 如果一定要打印，可以给类设置public的方法
    // cout<<d2._year<<endl;
    cout << d2.GetYear() << endl;
}

int main()
{
    TestDate();
    return 0;
}
#endif
#if 0
class Date
{
public:
    Date(int year = 1900, int month = 1, int day = 1)
    {
        _year = year;
        _month = month;
        _day = day;
    }
    // 普通成员函数：没有const修饰的成员函数
    // 该成员函数中，可以对象成员变量进行修改
    // this的类型：Date* const -->this指向不能修改，this指向空间的值可以修改
    // 可写入：可以修改成员变量
    void Show()
    {
        _day += 1;
        this->_day += 1;
        cout << _year << " " << _month << " " << _day << endl;
    }
    // const成员函数：被const修饰的成员函数
    // 特性：不能修改"成员变量"
    // const修饰成员函数，实际是修饰this指针
    // this指针类型：const Date* const
    // 只读：只能读取this中的成员，不能修改

    void Print() const
    {
        cout << _year << " " << _month << " " << day << endl;
    }

private:
    int _year;
    int _month;
    int _day;
};

int main()
{
    // 普通对象既可以调用普通成员函数，也可调用const成员函数
    // d1对象，是可读可写对象
    Date d1(2022, 11, 19);
    d1.Show();
    d1.Print();

    // const对象:只能调用const成员函数
    // d2对象：只读的对象，成员函数只能读取该对象中的内容，不能修改
    const Date d2(d1);
    d2.Print();
    // d2.Show();
    // 编译报错，d2是只读对象，不允许修改对象中的内容，
    // 但是如果该对象调用普通的成员函数，在该成员函数中完全有可能会修改const对象中的内容
    // 代码不安全 

    return 0;
}
#endif
#if 0
class Date
{
public:
    Date(int year = 1900, int month = 1, int day = 1)
    {
        _year = year;
        _month = month;
        _day = day;
    }
    void Fun1() {}
    void Fun2() const {}
    // 非const成员函数内可以调用其他const成员嘛？ 答案：可以
    // Show():普通方法，该方法内部可以修改也可以不修改成员变量
    // this的类型：Date* const 即：当前对象可以修改，也可不修改
    void Show()
    {
        Fun1();
        Fun2();
        _day += 1;
        cout << _year << " " << _month << " " << _day << endl;
    }
    // const成员函数内部可以调用其他非const成员函数嘛？ 答案：不可以
    // const成员函数内部只能调用const成员函数
    // const成员函数：const本质修改this指针，表明该成员函数内部一定不会修改成员变量
    //               是一个只读的成员函数
    //               this的类型：const Date* const

    void Print() const
    {
        // Fun1();//编译报错
        Fun2();

        //_day=1;//编译报错
        cout << _year << " " << _month << " " << _day << endl;
    }
    // 如果在const成员函数中，一定要修改某个成员变量时
    // 在定义该成员变量的时候，使用mutable关键字修改该成员即可。
    void Fun3() const
    {
        //_month += 1;//编译报错
        _day += 1;
    }

private:
    int _year;
    int _month;
    mutable int _day;
};
#endif
#if 0
class Date
{
public:
    Date(int year = 1900, int month = 1, int day = 1)
    {
        _year = year;
        _month = month;
        _day = day;
    }
    void Print() const
    {
        cout << _year << " " << _month << " " << _day << endl;
    }

    // this：Date* const
    Date *operator&()
    {
        cout << this << endl;
        return this;
    }

    // this的类型：const Date* const
    // 注意：在参数列表中不能加任何参数，否则编译器会将&当成按位与&来处理
    // const Date *operator&(int) const
    // {
    // cout << this << endl;
    // return this;
    // }

    // this的类型：const Date* const
    const Date *operator&() const
    {
        cout << this << endl;
        return this;
    }

private:
    int _year;
    int _month;
    int _day;
};
int main()
{
    Date d1(2022, 11, 19);

    // 需求：在对对象取地址的同时需要将对象的地址打印出来
    Date *p = &d1;

    const Date d2(d1);
    const Date *p2 = &d2;
    return 0;
}
#endif
#if 0
//2022-11-19代码：
class Date
{
public:
    Date(int year=1900,int month=1,int day=1)
    {
        //构造方法内部：并不是对成员变量进行初始化，而是赋值
        //初始化只能初始化一次，但赋值可以赋值多次
        _year = year;
		_month = month;
		_day = day;

		_year = year;
		_year = year;
		_year = year;

        _a=10;

    }
    void Print()const
    {
        cout << _year << " " << _month << " " << _day << endl;
    }
private:
    int _year;
    int _month;
    int _day
    const int a;
};

//问题：类中成员变量应该如何进行初始化
int main()
{
    const int a=10;
    return 0;
}
#endif
#if 0
//构造方法：有初始化列表，初始化列表位置才是真正的对成员变量初始化的位置
//  而构造方法内部是赋值。

class Date
{
public:
    //Date(int year=1900,int month=1,int day=1):_year(year),_month(month),_day(day)
    Date(int year=1900,int month=1,int day=1)
        :_year(year)
        ,_month(month)
        ,_day(day)
        ,_day(1)//每个成员变量在初始化列表中只能出现一次（初始化只能出现一次）
        ,_a(10);
        ,_rday(_day)
    {
        //构造方法内部：并不是对成员变量进行初始化，而是赋值
        //初始化只能初始一次，而赋值可以赋值多次

        // _year=year;
        // _month=month;
        // _day=day;

        //_a=10;//赋值
    }
    void Print()const
    {
        cout << _year << "/" << _month << "/" << _day << endl;
    }
private:
	int _year;
	int _month;
	int _day;

	const int _a;
	int& _rday;  
}

int main()
{
    Date A1(2022,11,19);
    return 0;
}
#endif
#if 0
class Time
{
public:
    Time(int hour, int minute, int second)
        : _hour(hour), _minute(minute), _second(second)
    {
        cout << "Time()" << endl;
        this->Print();
    }
    Time(int hour)
        : _hour(hour), _minute(0), _second(0)
    {
    }
    void Print() const
    {
        cout << _hour << "h " << _minute << "m " << _second << "s" << endl;
    }

private:
    int _hour;
    int _minute;
    int _second;
};
class Date
{
private:
    int m_year;
    int m_month;
    int m_day;
    Time m_t;

public:
    Date(int year, int month, int day)
        : m_year(year), m_month(month), m_day(day), m_t(10, 50, 30)
    {
        cout << "Date(int int int)" << endl;
        this->Print();
        // this->m_t.Print();
    }
    Date(int year)
        : m_year(year), m_month(1), m_day(1), m_t(10)
    {
    }

    void Print() const
    {
        cout << m_year << " " << m_month << " " << m_day << endl;
    }
};
int main()
{
    Date d1(2022, 11, 19);
    Date d2(2022);
    system("pause");
    return 0;
}
#endif
#if 0
// Date 类中包含一个Time类对象
class Time
{
private:
    int _hour;
    int _minute;
    int _second;

public:
    Time(int hour = 0, int minute = 0, int second = 0)
        : _hour(hour), _minute(minute), _second(second)
    {
        cout << "Time()" << endl;
    }
};

// 1.初始化列表可以不写，不写不代表编译器不执行初始化列表
//   如果用户没有显示写出初始化列表，编译器会自动补全
//   对于类中内置类型成员变量，使用随机值填充
//   对于类中自定义类型的成员变量，调用对应类的无参或者全缺省的构造方法初始化该成员

class Date
{
private:
    int _year;
    int _month;
    int _day;
    Time _t;

public:
    Date(int year, int month, int day)
    {
        cout << "Date(int int int)" << endl;
    }
    // 上述构造方法经过编译后，变成如下形式：
    // Date(int year, int month, int day)
    // :_year(随机值)
    // ，_monrh(随机值)
    // ,_day(随机值)
    // ,_t()//调用Time类的无参或者全缺省的构造方法
    // {
    // cout<<"Date(int int int)"<<endl;
    // }
    void Print() const
    {
        cout << _year << " " << _month << " " << _day << endl;
    }
};
#endif
#if 0
class Time
{
private:
    int _hour;
    int _minute;
    int _second;

public:
    // 无参或非全缺省参数的构造方法
    Time(int hour, int minute, int second)
        : _hour(hour), _minute(minute), _second(second)
    {
        cout << "Time()" << endl;
    }
};

// 1.初始化泪飙可以不写，不写不代表编译器不执行初始化列表
//   如果用户灭有显示写出初始化列表，编译器会自动补全
//   对于类中内置类型成员变量，使用随机值填充
//   对于类中自定义类型的成员变量，调用对应类的无参或者全缺省的构造方法初始化该成员
//
// 2.如果类中包含的自定义对象对应类中，没有全缺省或无参的构造，则报错
//      解决方法:a.给Time类中添加无参或者全缺省的构造方法（不推荐，因为Time类可能不是自己实现的）
//              b.给Data类初始化类表显示给出，然后调用Time类带有参数的构造方法初始化_t
class Date
{
private:
    int _year;
    int _month;
    int _day;
    Time _t;

public:
    Date(int year, int month, int day)
        : _t(11, 26, 32)
    {
        cout << "Date(int,int,int)" << endl;
    }

    /*
    * 上述构造方法经过编译之后，变成如下形式：
    * Date(int year, int month, int day)
    *    : _year(随机值)
    *    , _month(随机值)
    *    , _day(随机值)
    *    , _t()   //调用Time类的无参或者全缺省个的构造方法
      {
        cout << "Date(int,int,int)" << endl;
      }
    */

    void Print() const
    {
        cout << _year << "/" << _month << "/" << _day << endl;
    }
};
#if 0
int main()
{
    Date d1(2022, 11, 19);
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
    Date(int year, int month)
        : _year(year), _day(month), _month(_day)
    {
        cout << "Date(int int int)" << endl;
    }
    void Print() const
    {
        cout << _year << " " << _month << " " << _day << endl;
    }
};
int main()
{
    Date d1(2022, 11);
    d1.Print(); // 2022 0 11
    // 初始化类表中的初始化顺序是由类成员属性定义顺序决定的
    // 如果在Date类中将_month和_day顺序交换(996,997行)，则输出结果为：2022 11 11
    system("pause");
    return 0;
}
#endif
#if 0
// 拷贝构造函数初始化列表

class Time
{
private:
    int _hour;
    int _minute;
    int _second;

public:
    // 无参或者非全缺省参数的构造方法
    Time(int hour, int minute, int second)
        : _hour(hour), _minute(minute), _second(second)
    {
        cout << "Time()" << endl;
    }
    Time(const Time &t)
        : _hour(t._hour), _minute(t._minute), _second(t._second)
    {
        cout << "Time(const Time& t)" << endl;
    }
    void Print() const
    {
        cout << _hour << "h " << _minute << "m " << _second << "s" << endl;
    }
};

class Date
{
private:
    int _year;
    int _month;
    int _day;
    Time _t;

public:
    Date(int year, int month, int day)
        : _year(year), _month(month), _day(day), _t(11, 52, 30)
    {
        cout << "Date(int int int)" << endl;
    }
    Date(const Date &d)
        : _year(d._year), _month(d._month), _day(d._day), _t(d._t)
    {
        cout << " Date(const Date& d)" << endl;
    }
    void Print() const
    {
        this->_t.Print();
        cout << _year << " " << _month << " " << _day << endl;
    }
};
int main()
{
    Date d1(2022, 11, 19);
    d1.Print();
    cout << &d1 << endl;
    Date d2(d1);
    d2.Print();
    cout << &d2 << endl;

    // 输出  //
    //  Time()
    //  Date(int int int)
    //  11h 52m 30s
    //  2022 11 19
    //  0x62fe00
    //  Time(const Time& t)
    //   Date(const Date& d)
    //  11h 52m 30s
    //  2022 11 19
    //  0x62fde0
    system("pause");
    return 0;
}
#endif
#if 0
// explicit 关键字
class Date
{
private:
    int _year;
    int _month;
    int _day;

public:
    explicit Date(int year)
        : _year(year), _month(1), _day(1)
    {
        cout << "Date(int int int)" << this << endl;
    }
    Date &operator=(const Date &d)
    {
        cout << this << "=" << &d << endl;
        if (this != &d)
        {
            _year = d._year;
            _month = d._month;
            _day = d._day;
        }
        return *this;
    }
    ~Date()
    {
        cout << "~Date():" << this << endl;
    }
};
void TestDate()
{
    Date d(2022);
    // d = 2023;// 报错
}
int main()
{
    TestDate();

    system("pause");
    return 0;
}
#endif
#if 0
// 需求：一个类创建了多少个对象
//      需要一个计数来记录该类创建了多少个对象-->计数肯定是整形
class Date
{
private:
    int _year;
    int _month;
    int _day;
    int _count; // 用来记录对象的个数
public:
    Date(int year, int month, int day)
        : _year(year), _month(month), _day(day), _count(0)
    {
        ++_count;
    }
    Date(Date &d)
        : _year(d._year), _month(d._month), _day(d._day), _count(d._count)
    {
    }
    ~Date()
    {
        _count--;
        cout << "~Date():" << this << endl;
    }
};

void TestDate()
{
    Date d1(2022, 11, 19);
    Date d2(d1);

    if (true)
    {
        Date d3(d2);
    }
}

int main()
{
    TestDate();
    return 0;
}
#endif
#if 0
// 需求：一个类创建了多少个对象
//      需要一个计数器来记录该类创建了多少个对象-- > 计数肯定是整数
// 结论：可以使用全局变量来进行计数
// 不太好，因为全局变量，程序可以在任意位置进行修改

// private:
int _count = 0;

class Date
{
private:
    int _year;
    int _month;
    int _day;
    int _count; // 用来记录对象的个数
public:
    Date(int year, int month, int day)
        : _year(year), _month(month), _day(day), _count(0)
    {
        ++_count;
    }
    Date(Date &d)
        : _year(d._year), _month(d._month), _day(d._day), _count(d._count)
    {
    }
    ~Date()
    {
        _count--;
        cout << "~Date():" << this << endl;
    }
};
void TestObjCount()
{
    Date d3(2022, 11, 19);
    Date d4(d3);
}

void TestDate()
{
    Date d1(2022, 11, 19);
    Date d2(d1);
    if (true)
    {
        Date d3(d2);
    }
    _count = 100;
    TestObjCount();
}
#endif
// 静态成员变量
#if 0
// 如果类中有多个对象可以共享的成员变量，可以完美的解决上述问题
class Date
{
private:
    // 普通成员变量
    int _year;
    int _month;
    int _day;

public:
    // 静态成员变量
    // 静态成员变量在类中声明，类外定义
    static int _count;

public:
    Date(int year, int month, int day)
        : _year(year), _month(month), _day(day)
    //, _count(0)//无法通过构造函数初始化静态类数据
    {
        ++_count;
    }
    Date(Date &d)
        : _year(d._year), _month(d._month), _day(d._day)
    {
        ++_count;
    }
    ~Date()
    {
        _count--;
        cout << "~Date():" << this << endl;
    }
};

// 类中静态成员变量在类外定义时：
// 1.必须在成员变量前加类名以及作用域限定符
// 2.在类外定义时不需要再添加static关键字
int Date::_count = 0;

void TestObjCount()
{
    cout << Date::_count << endl;
    Date d3(2022, 11, 19);
    Date d4(d3);
    // cout << d3._count << endl;
}
void TestDate()
{
    Date d1(2022, 11, 19);
    Date d2(d1);

    // 注意：sizeof并不会计算静态成员变量的大小
    //      因为静态成员变量并没有包含在对象中
    if (true)
    {
        Date d3(d2);
    }
    cout << d1._count << endl;
    cout << d2._count << endl;
    cout << &d1._count << " " << &d2._count << endl;
    TestObjCount();
    //      输出：    //
    // ~Date():0x62fdbc  d3的析构函数
    // 2
    // 2
    // 0x408030 0x408030
    // 2
    // ~Date():0x62fd68
    // ~Date():0x62fd74
    // ~Date():0x62fdc8
    // ~Date():0x62fdd4

    // cout << d2._count << endl;
}
int main()
{
    TestDate();

    system("pause");
    return 0;
}
#endif
// 静态成员函数
#if 0
class Date
{
private:
    // 普通成员变量
    int _year;
    int _month;
    int _day;

private:
    static int _count;

public:
    Date(int year, int month, int day)
        : _year(year), _month(month), _day(day)
    //, _count(0)    // “_count”: 无法通过构造函数初始化静态类数据
    {
        ++_count;
    }

    Date(Date &d)
        : _year(d._year), _month(d._month), _day(d._day)
    {
        ++_count;
    }

    ~Date()
    {
        _count--;
        cout << "~Date():" << this << endl;
    }

    void Func()
    {
        cout << this << endl;
        cout << _count << endl;
        GetCount();
    }

    // 静态成员函数
    static int GetCount(); // const
    // {
        // Func(); // 无法传递this指针
        // // 只能在非静态成员函数或非静态数据成员初始值设定项的内部引用
        // cout << this << endl;
        // cout << _day << endl; // 会被编译为：cout<<this->_day<<endl;
        // return _count;
    // }
};
int Date::_count = 0;
void TestObjCount()
{
    Date d3(2022, 11, 19);
    Date d4(d3);
}
void TestDate()
{
    Date d1(2022, 11, 19);
    Date d2(d1);
    cout << d1.GetCount() << endl;
    if (true)
    {
        Date d3(d2);
    }
    TestObjCount();
}
int main()
{
    // 现在需要知道打印Date类型总共创建了多少个对象
    // 打印对象的个数
    cout << Date::GetCount << endl;
    Date d(2022, 11, 19);
    cout << d.GetCount() << endl;
    // 这种方式虽然可以，但是打印的结果不准确，多了一个对象

    // 能不能不创建对象，也可以直接调用getCount的方法呢？
    // 答案是可以，只需要将GetCount的方法使用static修饰

    d.Func();
    Date::GetCount;

    TestDate();
    system("pause");
    return 0;
}
#endif

// 741--2022.11.19
#if 0
class Date
{
private:
    int _year;
    int _month;
    int _day;

public:
    /*static*/ Date(int year, int month, int day) /*const*/
        : _year(year), _month(month), _day(day)
    {
    }
    /*static*/ Date(Date &d) /*const*/
        : _year(d._year), _month(d._month), _day(d._day)
    {
    }
    /*static*/ ~Date() // const
    {
        cout << "~Date():" << this << endl;
    }
};
#endif

// 友元
#if 0
class Date
{
    friend void TestFriend();

private:
    int _year;
    int _month;

protected:
    int _day;
    friend void PrintDate(const Date &d);

public:
    Date(int year, int month, int day)
        : _year(year), _month(month), _day(day)
    {
    }
    // 一般情况下，私有的成员都会在类中提供get，set方法
public:
    void SetYear(int year)
    {
        _year = year;
    }
    int GetYear() const
    {
        return _year;
    }

    void SetMonth(int month)
    {
        _month = month;
    }
    int GetMonth() const
    {
        return _month;
    }
    void SetDay(int day)
    {
        _day = day;
    }
    int GetDay() const
    {
        return _day;
    }

    // PrintDate现在就是Date类的友元函数
    // 可以在PrintDate方法中访问Date类中的私有变量
    // friend void PrintDate(const Date &d);
};
class Time
{
private:
    int _hour;
    int _minute;
    int _second;

public:
    Time(int hour, int minute, int second)
        : _hour(hour), _minute(minute), _second(second)
    {
    }
    friend void TestFriend();
};
// 友元函数并不是类的成员函数，所以没有this指针
// 友元函数不能被const修饰
// 友元函数不受访问限定符的约束，因为友元函数不是类的成员函数
// 一个函数可以是多个类的友元函数，比如：一个人能可以是多个人的朋友

void PrintDate(const Date &d) // const//报错：非静态成员函数不允许杯const修饰
{
    // cout << this << endl; // 报错 // this只能用于非静态成员函数的内部
    cout << d._year << " " << d._month << " " << d._day << endl;

    // 如果一定要访问
    // 1.可以在类中提供public的共有方法
    cout << d.GetDay() << endl;
    cout << d.GetMonth() << endl;
    cout << d.GetYear() << endl;

    // 2.友元函数
    cout << d._year << " " << d._month << " " << d._day << endl;
}
void TestFriend()
{
    Date d(2022, 11, 19);
    // d._day += 1;//报错 注意权限
    d._month += 1;

    Time t(16, 18, 20);
    t._second += 1;
}
int main()
{
    Date d(2022, 11, 19);
    PrintDate(d);
    system("pause");
    return 0;
}
#endif
// 运算符重载
#if 0
class Date
{
private:
    int _year;
    int _month;
    int _day;

public:
    Date(int year, int month, int day)
        : _year(year), _month(month), _day(day)
    {
    }
    void Print() const
    {
        cout << _year << " " << _month << " " << _day << endl;
    }
    // void operator<<(Date *const this, osteram &out);
    void operator<<(ostream &cout)
    {
        cout << _year << " " << _month << " " << _day << endl;
    }
};
int main()
{
    Date d(2022, 11, 19);
    d.Print();

    int a = 10;
    double b = 12.34;
    const char *str = "hello world";
    cout << a << " " << b << " " << str << endl;
    // cout:可以支持内置类型数据的直接打印
    // 但是不支持自定义类型对象的直接打印
    // 因为类中有多个成员，打印时的格式问题无法确定

    // cout<<d;
    // 如果要使用cout输出d，必须再Date类中对<<进行重载
    d << cout; // 编译通过，但不符合逻辑
    d.operator<<(cout);

    // 流插入运算符<<:不能重载成类的成员函数
    // 因为调用不符合常规：d<<cout;
    system("pause");
    return 0;
}
#endif

// 939
#if 0
class Date
{
private:
    int _year;
    int _month;
    int _day;

public:
    Date(int year, int month, int day)
        : _year(year), _month(month), _day(day)
    {
    }
    friend ostream &operator<<(ostream &cout, const Date &d);
    friend istream &operator>>(istream &cin, Date &d);
};

// 流插入运算符<<，规定
// 第一个参数必须是ostream&,因为该运算符不能重载成员函数，不符合调用常规
// 必须要有返回值类型，必须是ostream&,目的是为了支持连续输入
// 在输出时，最好不要加格式控制，比如换行
// 一般情况下都从再成类的友元函数
// 只能将其重载为全局函数
ostream &operator<<(ostream &cout, const Date &d)
{
    cout << d._year << " " << d._month << " " << d._day;
    return cout;
}
istream &operator>>(istream &cin, Date &d)
{
    cin >> d._year >> d._month >> d._day;
}
int main()
{
    int a = 10;
    int b = 20;
    cout << a << " " << b << endl;
    Date d1(2022, 11, 19);
    Date d2(d1);
    cout << d1 << " " << d2 << endl;

    cin >> d1;
    cout << d1 << endl;

    system("pause");
    return 0;
}
#endif
#if 0
class Time
{
private:
    int _hour;
    int _minute;
    int _second;
    // Date现在时Time的友元类，可以再Date的每个方法中访问Time类的私有和保护的成员
    friend class Date;

public:
    Time(int hour, int minute, int second)
        : _hour(hour), _minute(minute), _second(second)
    {
    }

protected:
    void Fun1() {}

private:
    void Fun2() {}
};

class Date
{
private:
    int _year;
    int _month;
    int _day;
    Time _t;

public:
    Date(int year, int month, int day)
        : _year(year)
        , _month(month)
        , _day(day)
        , _t(17, 20, 30)
    {}
    void Print()
    {
        cout<<_year<<" "<<_month<<" "<<_day<<endl;
        cout<<_t._hour<<" "<<_t._minute<<" "<<_t._second<<endl;
    }
    void Func()
    {
        _t.Fun1();
        _t.Fun2();
    }
};
#endif
#if 0
class List
{
public:
    // ListNode定义在List的内部，将ListNode成为内部类
    class ListNode
    {
    private:
        int _data;
        ListNode *_next;

    public:
        ListNode(int data = 0)
            : _next(nullptr), _data(data)
        {
        }
    };

public:
    void PushBack(int data)
    {
    }
    void PushFront(int data)
    {
    }
    void PopBack()
    {
    }
    void PopFront()
    {
    }

public:
    List()
        : _head(nullptr)
    {
    }

private:
    ListNode *_head; // 注意定义顺序，要定义在类ListNode定义之后
};
int main()
{
    cout << sizeof(List) << endl;
    // 8
    List l;
    l.PushBack(10);
    l.PushBack(20);
    l.PushBack(30);
    system("pause");
    return 0;
}
#endif
#if 0
// 演示：内部类时外部类的友元
class A
{
private:
    int _a;
    static int _c;

public:
    A(int a = 10)
        : _a(a)
    {
    }

private:
    class B
    {
    private:
        int _b;

    public:
        B(int b = 0)
            : _b(b)
        {
        }

        // 内部类就是外部类的友元类
        void Func()
        {
            A aa;
            aa._a = 10;
            cout << _c << endl;
        }
    };
};
int A::_c = 0;
int main()
{
    cout << sizeof(A) << endl;
    // 4
    system("pause");
    return 0;
}
#endif
#if 0
class Sum
{
private:
    static int n;
    static int sum;

public:
    Sum()
    {
        ++n;
        sum += n;
    }
    static int GetSum()
    {
        return sum;
    }
    static void Reset()
    {
        n = 0;
        sum = 0;
    }
};
int Sum::n = 0;
int Sum::sum = 0;
class Solution
{
public:
    int Sum_Solution(const int n)
    {
        Sum::Reset();
        Sum s[5];
        return Sum::GetSum();
    }
};
//有问题，还未完成，见下次理解。
int main()
{
    Solution s;

    int ret = s.Sum_Solution(5);
    cout << ret << endl;

    ret = s.Sum_Solution(4);
    cout << ret << endl;

    ret = s.Sum_Solution(3);
    cout << ret << endl;

    system("pause");
    return 0;
}
#endif