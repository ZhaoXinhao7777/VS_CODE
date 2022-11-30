#include<iostream>
#include<stdlib.h>

using namespace std;
#if 0
//之前在全局作用域中可以定义的内容，在命名空间中都可以定义
//命名空间实际就是一个作用域
namespace Zxh
{
    //定义变量
    int a=10;
    int b=20;
    
    //定义函数
    int Add(int x,int y){
        return x+y;
    }

    //定义结构体
    struct BTNode
    {
        struct BTNode* left;
        struct BTNode* right;
        int data;
    }Node;

    //定义类...
}

int a=10,b=20;
int Add(int x,int y)
{
    return x+y;
}


//命名空间可以嵌套：一个命名空间中，可以包括其他的命名空间
//类似于：计算机学院可以看成一个命名空间
//       假设计算机学院下包括：计科，软工，网工...

namespace N1
{
    int a=10;
    int b=20;

    int Add(int x,int y)
    {
        return x+y;
    }

    namespace N2
    {
        int x=20;
        int y=30;
        int Sub(int left,int right)
        {
            return left-right;
        }
    }
}

//注意:在同一个工程中，也可以定义名字相同的命名空间
namespace N1
{
    int Mul(int x,int y)
    {
        return x*y;
    }
}
#endif
#if 0
//命名空间中的成员使用
//方式一:命名空间的名字::成员名字
namespace N
{
    int a=10;
    int Add(int x,int y)
    {
        return x+y;
    }

    //int a=20;
}

//在同一个作用域中不能存在相同的命名
//在不同的作用域中可以
int a=20;

int main()
{
    int a=30;
    printf("%d\n",a);//打印30-->就近原则

    //打印全局作用域中的a
    //::作用域运算符
    printf("%d\n",::a);//编译器会找全局作用域中的a

    //N的命名空间中也有一个a
    printf("%d\n",N::a);

    printf("%d\n",N::Add(100,200));


    system("pause");
    return 0;
}
#endif

#if 0
//假设:命名空间中某个成员在当前文件中使用频繁
namespace N
{
    int a=10;
    int Add(int x,int y)
    {
        return x+y;
    }

}

//命名空间中成员使用方法二:
using N::a;
//相当于a变成文件中的全局变量
//注意:此时全局变量作用域是不能存在相同的成员变量，否则会发生重定义
int a=100;
//如果存在，按照方式一使用计即可

int main()
{
    printf("%d\n",N::a);
    printf("%d\n",N::a);
    printf("%d\n",N::a);
    printf("%d\n",N::a);
    printf("%d\n",N::a);
    return 0;

}
#endif
#if 0
//命名空间中好些成员都要在当前文件使用
namespace N
{
    int a=10;
    int Add(int x,int y)
    {
        return x+y;
    }
}

// using N::a;
// using N::Add;



//方式三
using namespace N;

//命名空间中所有成员都可以看成当前文件中的全部成员
//缺陷：比较容易发生冲突，如果冲突了，再按照方式一使用即可

int main()
{
    printf("%d\n",a);
    printf("%d\n",a);
    printf("%d\n",a);
    printf("%d\n",a);

    printf("%d\n", Add(100, 200));
    printf("%d\n", Add(100, 200));
    printf("%d\n", Add(100, 200));
    printf("%d\n", Add(100, 200));

    system("pause");
    return 0;
}
#endif

#if 0
//命名空间嵌套时，内部命名空间中成员的使用方法：
namespace N1
{
    int a=10;
    namespace N2
    {
        int b=20;
    }
}

int main()
{
    printf("N1::a=d\n",N1::a);
    printf("N1::N2::b=%d\n",N1::N2::b);
    return 0;

}
#endif

#if 0
//一个工程中存在命名空间相同的命名空间？

namespace N1
{
    int a=10;
    int Add(int x,int y)
    {
        return x+y;
    }
}

namespace N1
{
    //int a=20;重定义
    int b=30;
    int sub(int x,int y)
    {
        return x-y;
    }
}

int main()
{
   printf("%d\n",N1::a);
   printf("%d\n",N1::Add(200,100));


    return 0;
}
#endif

#if 0
//C++兼容C语言的，因此C语言中的输入和输出在C++中可以继续使用
//但是C语言中的输入与输出不方便
//因此，在输入和输出时，需要记大量的格式控制，而且非法使用编译器不会报错，在代码运行时崩溃或者出现一些奇奇怪怪的结果

int main()
{
    //printf("Hello World!\n");
    cout<<"Hello World!"<<endl;

    int a=10;
    //printf("a=%d\n",a);
    cout<<"a="<<a<<endl;

    //printf("%d %s %f",a); //输出奇奇怪怪
    return 0;
}
#endif

#if 0
// C++标准库中的内容，基本都在std的命名空间中
using namespace std;

int main()
{
    //写项目时，更推荐
    std::cout<<"Hello world!"<<std::endl;
    cout<<"hello Zxh\n";
    cout<<10<<12.13<<"hello C++"<<endl;

    int a=0;
    cin>>a;
    double b=0.0;
    cin>>b;
    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;

    cin>>a>>b;
    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;

//注意:cin在从来接受输入时，不能接受空白字符：空格 TAB 回车
//如要接受，需要使用C语言中的getchar()
    char ch;
    cin>>ch;
    cout<<ch<<endl;
//如果要进行更复杂的格式控制，建议使用C语言中的方式
    return 0;
}
#endif
#if 0
//C++和C语言函数方式不同
//C++在函数返回值位置控制更加严格
//C语言中

#include<stdio.h>

//没有给出明确的返回值类型
Add(int a,int b)
{
    x+y;
}

int Sub(int a,int b)
{
    x+y;
}

int main()
{
    int a=Add(10,20);
    printf("%d\n",a);
    a=Sub(20,10);
    printf("%d\n",a);
    return 0;
}
#endif
#if 0
//函数参数返回值方面也有区别
void func()
{
    printf("func\n");
}

int main()
{
    func();
    func(10,20);
    func(10,20,30);

//在C++中就是错误
    return 0;
}
#endif
#if 0
//缺省参数:声明或者定义时，可以给函数带上默认值
//        在调用函数时，如果用户没有指定实参，就使用默认值，
//        如果指定了实参，就使用用户传递的实参

//备胎:

void func(int a=0)
{
    cout<<"func(a):"<<a<<endl;
}

int main()
{
    func();
    func(10);

    return 0;
}
#endif

#if 0
//缺省参数分类：
//1.全缺省参数：所有的参数都有默认值
void func(int a=1,int b=2,int c=3)
{
    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;
    cout<<"c="<<c<<endl;
    cout<<"_______________"<<endl;
}

//2.半缺省参数：部分参数带有默认值
//缺省参数只能从右至左依此给出
void func2(int a,int b=2,int c=3)
{
    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;
    cout<<"c="<<c<<endl;
    cout<<"_______________";
}

int main()
{
    func();
    func(10);
    func(10,20);
    func(10,20,30);

    cout<<"_______________"<<endl;;
    func2(10);
    func2(10,20);
    func2(10,20,30);

    return 0;  
}

//缺省值：只能在声明或者定义的位置给出，不能同时给出
//因此:假设声明和定义的位置可以同时给出，如果两位置值不一样
//     编译器就不知道到底使用声明处的还是定义处的默认值
//结论：在函数声明位置给出
void func3(int a=10);

void func3(int a)
{
    cout<a<<endl;
}
int main()
{
    func3();
    return 0;
}
#endif

#if 0
//函数重载
//在相同作用域中，多个函数函数名相同，参数列表不同，与返回值类型无关
int Add(int x,int y)
{
    return x+y;
}

double Add(double x,double y)
{
    return x+y;
}

int main()
{
    cout<<Add(1,2)<<endl;
    cout<<Add(1.2,3.4)<<endl;

    //cout<<Add(1,2.3)<<endl;

    float f1=12.34f;
    float f2=23.45f;

    Add(f1,f2);//float-->double
    //Add("he;lo","world");char *,char *
    return 0;
}
#endif
#if 0
//重载概念补充：
//什么是参数列表不同，什么是与返回值类型无关？
//参数列表不同体现在：参数个数不同，参数类型不同，类型的次序不同

void func()
{}

// int func()
// {}

void func(int a)
{}

void func(double a)
{}

void func(int a,double b)
{}

void func(double a,int b)
{}

//注意：前提是 作用域 要相同
namespace N
{
    void func()
    {}
    void func(int a,double b)
    {}
}
//如果两个函数仅仅因为返回值类型不同，则无法构成函数重载
int main()
{
    //func(); //void func()和 int func()仅仅因为返回值类型不同，无法构成重载
    return 0;
}
#endif

#if 0
C++底层是如何实现函数重载的？
结论：C++编译器将参数类型编译到

为什么C语言不支持？
C语言编译器对函数名字的修改仅仅是在函数名前加一个下划线'_'


void func(int a)
{
    printf("一个参数\n");
    printf("func\n");
}
void func(int b, int c)
{
    printf("两个参数\n");
    printf("func\n");
}
void func(int a, int b, int c)
{
    printf("三个参数\n");
    printf("func\n");
}


int main()
{
    func(0);
    func(10, 20);
    func(10, 20, 30);

    return 0;

}
#endif
#if 0
//实现一个交换两个int类型变量的swap方法
//按照值的方式进行传递
void Swap(int left,int right)
{
    int temp=left;
    left=right;
    right=temp;
}
//按址传递
void Swap(int *left,int *right)
{
    int temp=*left;
    *left=*right;
    *right=temp;
}

int main()
{
    int a=10,b=20;
    Swap(a,b);
    printf("%d %d\n",a,b);

    Swap(&a,&b);
    printf("%d %d",a,b);

    return 0;
}
#endif
#if 0
//引用：
//使用引用的好处：代码可以按照值的方式来实现，最终还可以达到指针的效果
//修饰了形参之后，可以提到对实参修改的目的
void Swap(int &left,int &right)
{
    int temp=left;
    left=right;
    right=temp;
}
int main()
{
    int a=10;
    int &ra=a;
    ra=20;
    cout<<a<<"  "<<ra<<endl;
    //注意：引用类型必须和引用实体是同种类型
    //long &la=a; "message": "无法用 \"int\" 类型的值初始化 \"long &\" 类型的引用(非常量限定)",

    double d=12.23;
    double &rd=d;
    d=23.34;

    system("pause");
    return 0;
}
#endif
#if 0
//引用的特性：
int main()
{  
    //1.引用在定义时必须初始化
    //int &a;

    //2.一个变量可以有多个引用--一个人可以有多个外号
    // int a=10;
    // int &ra=a;
    // int &raa=a;
    // ra=20;
    // raa=30;

    //3.引用一旦引用一个实体，再不能引用其他实体
    // int a=10;
    // int &ra=a;
    // int b=20;
    // ra=b;//注意，该语句并不是将ra引用b，而是将b的值赋值给ra
    // &ra=b; //无法从int转换为int*

    //注意：&只有在类型之后才表示引用的标记
    //在变量之前表示取地址 在两个变量之间表示按位与

    return 0;
}
#endif
#if 0
//常引用：将const类型的引用成为const引用
int main()
{
    const int a=10;
    //const修饰a，表示a是一个常量，常量的值不允许被修改
    //a=100;//a必须是可修改的左值
    
    //因为a是常量，如果普通的引用变量ra可以引用a
    //完全可以通过ra将a常量修改掉，代码不安全
    //int &ra=a;
    //ra=100;

    const int &ra=a;
    //ra=100;

    int b=100;
    const int rb=b;
    return 0;

}
#endif
#if 0
int main()
{
    const int &ra=10;
    //ra=100;

    return 0;
}
#endif
#if 0
int main()
{
    int a=10;
    const int &ra=a;
    cout<<a<<" "<<ra<<endl;
    cout<<&a<<" "<<&ra<<endl;
    //ra=100; ra被const修饰
    a=100;
    cout<<a<<" "<<ra<<endl;
    cout<<&a<<" "<<&ra<<endl;
    // 10 10
    // 0x62fe14 0x62fe14
    // 100 100
    // 0x62fe14 0x62fe14

    system("pause");
    return 0;
}
#endif
#if 0
int main()
{  
    double d=12.34;
    const int &rd=d;//rd是一个匿名对象?
    //否 首先，内置类型的一般成为变量 用类定义出来的才称为对象
    //其次，rd是int类型，d是double类型，所以发生隐式类型转换
    //此时，编译器创建一个临时变量，把d中的整形放入临时变量中
    //临时变量用户不知道其名字，也不知道地址，是没有办法修改的，具有常性
    //所以前面加一个const
    cout<<d<<" "<<rd<<" "<<&d<<" "<<&rd<<endl;
    d=23.45;
    cout<<d<<" "<<rd<<" "<<&d<<" "<<&rd<<endl;
    // 12.34 12 0x62fe08 0x62fe14
    // 23.45 12 0x62fe08 0x62fe14

    system("pause");
    return 0；
}
#endif
#if 0
//引用的使用场景
//1.为了简化代码 直接给一个复杂的变量取别名
struct A{
    int a;
};
struct B{
    A aa;
    int b;
};
struct C{
    B bb;
    int c;
};
int main()
{
    struct C cc;
    cc.c=1;
    // cc.bb.b=2;
    // cc.bb.aa.a=3;

    //为了简化代码 直接给一个复杂的变量取别名
    B &bb=cc.bb;
    bb.b=2;
    bb.aa.a=3;

    int aaaaaabbbbbbbbbbbcdddd=10;
    //aaaaaabbbbbbbbbbbcdddd+=1;
    int &abcd=aaaaaabbbbbbbbbbbcdddd;
    abcd+=1;
    cout<<abcd<<endl;

    return 0;
}
#endif
#if 0
//2.用引用作为函数参数的形参
void Swap(int &ra,int &rb)
{
    int temp=ra;
    ra=rb;
    rb=temp;
}

int main()
{
    int a=10,b=20;
    //在调用时，形参ra就是a的别名，rb就是b的别名
    //在Swap方法中操作形参时，实际就是在操作实参a和b
    Swap(a,b);
    cout<<a<<" "<<b<<endl;
    return 0;
}
#endif
#if 0
#include<assert.h>
#include<string.h>
struct Student{
    char name[20];
    char gender[3];
    int age;
    int stuId;
};
#if 0
void InitStudent(struct Student *ps,const char name[],const char gender[],int age,int stuId)
{
    assert(ps);
    strcpy(ps->name,name);
    strcpy(ps->gender,gender);
    ps->age=age;
    ps->stuId=stuId;
}

void Print(struct Student *ps)
{
    assert(ps);
    cout<<ps->name<<" "<<ps->age<<" "<<ps->stuId<<" "<<ps->gender<<endl;
}
#endif

//引用作参数时，可以达到和指针类似的效果，可以通过形参修改外部实参
void InitStu(struct Student &rs,const char name[],const char gender[],int age,int stuId)
{
    strcpy(rs.name,name);
    strcpy(rs.gender,gender);
    rs.age=age;
    rs.stuId=stuId;
}

void Print(const struct Student &rs)
{
    cout<<rs.name<<" "<<rs.age<<" "<<rs.gender<<" "<<rs.stuId<<endl;
}
int main()
{
    struct Student s;
    InitStu(s,"peter","man",18,123456);
    Print(s);

    system("pause");
    return 0;
    
}
#endif
#if 0
//3.引用作为函数返回值
//  注意：不能是返回函数在栈上的空间
int &Add(int left,int right)
{
    int temp=left+right;
    return temp;
}
int main()
{
    int &ret=Add(1,2);
    printf("%d\n",ret);
    printf("%d\n",ret);
    printf("%d\n",ret);
    //  3
    // -858993460
    // -858993460
    system("pause");
    return 0;

}


int g_ret=0;
//只有函数结束后，返回的实体没有随着函数调用而销毁都可以
//比如：全局变量，static修饰的变量，堆空间等...

//注意：引用作为函数的返回值，不能返回函数栈上的空间
//  因为：当函数调用结束后，栈上的空间就被回收了，
//  如果在外部以引用的方式接受函数返回值
//  外部的引用实际引用的是一块非法的空间
int &Add(int left,int right)
{
    g_ret=left+right;
    return g_ret;
}
int main()
{
    int &ret=Add(1,2);
    printf("%d\n",ret);
    printf("%d\n",ret);
    printf("%d\n",ret);
    system("pause");
    return 0;
}
#endif
#if 0
#include<time.h>
struct SeqList
{
    int arr[10000];
    int size;
};
//测试函数调用时间,毫秒为单位
void Value(SeqList s){}//值传递
void Ptr(SeqList *ps){}//指针传递
void Ref(SeqList &rs){}//引用传递

// clock()函数的返回值就是你程序当前运行的时间（），
// 类型是长整型,
// 如果你想求某一个函数或者代码段运行的时间，
// 那么可以设置两个变量分别在代码段的前面和代码段的后面

void Time(int n)
{
    SeqList s;
    //获取起始时间
    size_t beginVal=clock();
    for(int i=0;i<n;i++)
    {
        Value(s);
    }
     //获取中止时间
    size_t endVal=clock();
    cout<<"Value Time:"<<endVal-beginVal<<endl;

    //获取起始时间
    size_t beginPtr=clock();
    for(int i=0;i<n;i++)
    {
        Ptr(&s);
    }
     //获取中止时间
    size_t endPtr=clock();
    cout<<"Ptr Time:"<<endPtr-beginPtr<<endl;

    size_t beginRef=clock();
    for(int i=0;i<n;i++)
    {
        Ref(s);
    }
     //获取中止时间
    size_t endRef=clock();
    cout<<"Ref Time:"<<endRef-beginRef<<endl;

}
// Value Time:1141
// Ptr Time:2
// Ref Time:2
// Value Time:1130
// Ptr Time:1
// Ref Time:2
// Value Time:1133
// Ptr Time:2
// Ref Time:1
// Value Time:1112
// Ptr Time:2
// Ref Time:2

int main()
{
    for(int i=0;i<10;i++)
    {
        Time(1000000);
    }

    system("pause");
    return 0;
}
#endif
#if 0
int main()
{
    int a=10;

    int*pa=&a;
    *pa=100;

    int &ra=a;
    ra=200;
    return 0;
}
#endif
#if 0
int main()
{
    //引用必须初始化，但是指针并没有要求，如果没有合法的指向，最好让其指向空
    // int &ra;
    // int *pa;
    int a=10;
    int& ra=a;
    int* pa=&a;

    int* const cpa=&a;
    int b=20;
    ra=b;
    pa=&b;

    //cpa=&b;报错 cpa为const类型

    char ch='A';
    char& rc=ch;
    char* pc=&ch;
    cout<<sizeof(rc)<<endl; //1
    cout<<sizeof(pc)<<endl; //8

    char** ppc=&pc;
    //char&& rrc=ch;//char&& 并不是多级引用，后续C++11中的右值引用

    char&& rrc='A';

    system("pause");
    return 0;
}
#endif
