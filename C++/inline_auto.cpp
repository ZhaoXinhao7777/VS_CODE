#include<iostream>
#include <typeinfo>
#include<string>
using namespace std;

#if 0
void Swap(int& left,int& right)
{
    int temp=left;
    left=right;
    right=temp;
}

int main()
{
    int a=10,b=20;
    Swap(a,b);
    cout<<a<<" "<<b<<endl;

    int *pa=&a,*pb=&b;
    Swap(*pa,*pb);
    cout<<a<<" "<<b<<endl;

    system("pause");
    return 0;
}
#endif
//C++对C语言中的宏也进行了优化
#if 0
//宏常量
#define MAX 100
#define PI 3.14
//宏常量的优势：
//1.可以达到一改全改的效果，提高了程序的可扩展性
//2.可以提高程序的可读性

int main()
{
    int arr[MAX];
    for(int i=0;i<MAX;i++)
    {
        arr[i]=i*10;
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    double r=2.0;
    cout<<PI*r*r<<endl;
    cout<<2*PI*r<<endl;

    system("pasue");
    return 0;
}
#endif
#if 0
//宏常量的缺陷：
//宏常量在定义是时候没有类型，在预处理阶段发生的替换，也就不会进行类型检测
#define PI "3.14"

int main()
{
    double r=2.0;
    //cout<<PI*r*r<<endl; //cout<< "3.14" * r * r << endl;
    //cout<<2*PI*r<<endl;//cout<< 2 * "3.14" * r <<endl;

    system("pause");
    return 0;
}

#endif
#if 0
//因宏常量有缺陷，因此在C++中，使用const定义的常量取代宏

const int MAX=100;
const double PI=3.14;

int main()
{
    //注意：
    //在C++中，被const修饰的变量并不是变量，而是一个常量
    //在C语言中，被const修饰的变量不是常量，而是一个不能被修改的变量

    int arr[MAX];
    // int n;
    // int a[n];

    double r=2.0;
    cout<<PI*r*r<<endl;

    return 0;
}
#endif
#if 0
//const定义的常量也会发生替换，该替换是在编译时
//在所有读取a常量中内容的位置，比如打印常量，都会使用常量本身替换
int main()
{
    const int a=10;
    int *pa=(int*)&a;

    *pa=100;
    cout<<a<<" "<<*pa<<endl;// 10 100
    cout<<&a<<" "<<&pa<<endl;


    return 0;
}
#endif
#if 0
//宏函数
//优点：在预处理阶段会展开，(展开：就是宏体替换宏使用的位置)少了函数调用的开销
//缺陷：
//  1.不会进行类型检测
//  2.不能调试
//  3.有副作用 见"122"行代码
//  4.会造成代码膨胀
#define Add(x,y) x*y
//#define Add(x,y) (x)*(y)
#define MAX(x,y) (x)>(y)?(x),(y);

int main()
{
    int count=Add(1+2,3+4);//输出：11 1+2*3+4 而不是（1+2）*（3+4）
    cout<<count<<endl;

    system("pause");
    return 0;
}
#endif
#if 0
//内联函数：
inline int Add(int x,int y)
{
    //Add(x,y);
    return x+y;
}
int main()
{
    int a=10,b=20;
    int ret=Add(a,b);
    cout<<ret<<endl;

    system("pause");
    return 0;
}
#endif

#if 0
#include<map>
#include<string>
typedef std::map<std::string,std::string>Map;

int main()
{
    Map m;
    m["apple"]="apple";
    m["orange"]="orange";
    m["pear"]="pear";
    m["banana"]="banana";

    Map::iterator it=m.begin();
    while(it!=m.end())
    {
        cout<<it->first<<"->"<<it->second<<endl;
        it++;
    }
    system("pause");
    return 0;
}
#endif

#if 0
typedef char* pstring;
int main()
{
    //const在*之前，表示指针指向空间中的内容不允许被修改，指针的指向是可以修改的
    const char *p;
    const int a1=10;

    int const a2=20;

    const pstring p1=NULL;
    pstring const p3=NULL;
    const pstring *p2;

    return 0;
}
#endif
//---------------------------------------------//
//C语言中：auto  用来定义自动存储类型的局部变量，表明变量可以被自动销毁
//        但是局部变量本来就在函数结束后就自动销毁
//        显得auto有些多余，没有什么实际的含义

//C++11中，auto被赋予新的含义：用来定义变量的一个占位符，告诉编译器在编译阶段，
//  推到初始化列表的类型作为变量真正的类型
#if 0
int TestRet()
{
    return 0;
}

void func()
{}

void *func1()
{return NULL;}

int main()
{
    int a=10;
    double d=12.34;
    auto a1=10;
    auto d1=12.33;
    auto ret=TestRet();

    //auto定义变量时必须要初始化，否则编译器没有办法进行推演
    //b的实际类型时没有办法确认的
    //auto b;

    cout<<typeid(a1).name()<<endl;
    cout<<typeid(d1).name()<<endl;
    cout<<typeid(ret).name()<<endl;

    system("pause");
    return 0;
}

#endif
#if 0
//auto和指针与引用结合
int main()
{
    int a=10;
    //auto 定义指针变量时，*可加可不加
    auto pa=&a;
    auto *pb=&a;
    cout<<typeid(pa).name()<<endl;
    cout<<typeid(pb).name()<<endl;

    auto& ra=a;
    ra=100;
    cout<<a<<endl;//100
    system("pause");
    return 0;
}
#endif
#if 0
int main()
{
    int a,b,c;
    auto a1=10,b1=20;
    //auto c1=30,d1=12.34;

    return 0;
}
#endif
#if 0
//注意：auto不能作为函数的形参使用
//void Test(auto a){}

auto Test()
{return 0;}
#endif
#if 0
//auto不能用来声明数组

int main()
{
    int arr1[]={1,2,3};
    auto arr2={1,2,3};//initializer_list
    //auto arr2[]={1,2,3};
    cout<<sizeof(arr2)<<endl;
    cout<<sizeof(int)<<endl;

    //auto arr2[]={1,2,3};
    cout<<typeid(arr2).name()<<endl;
    cout<<sizeof(arr2)<<endl; 
    return 0;

}
#endif
//--------------------------------------------------------------
#if 0
int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9,0};
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
    {
        arr[i]*=2;
    }

    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}
#endif
#if 0
//上述代码的缺陷：
// 编译器讲数组编译完成之后，数组的范围实际就是确定的。
// 当需要数组变量时，由用户负责确定数组的范围有点多余，甚至很容易出错而导致程序崩溃
// C++11:基于范围for循环：范围for
// for(auto e:范围)：e将是范围中每个元素的拷贝，即不能通过e修改范围中的数据
// for(auto& e:范围)：e将是范围中每个元素的别名，既可以通过e修改范围中的元素

int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9,0};
    cout<<"auto: "<<endl;
    
    for(auto e:arr)
    {
        cout<<e<<" ";
    }
    cout<<endl;

    cout<<"e * 2"<<endl;
    //e将来就是arr中每一个元素的一份拷贝
    for(auto e:arr)
    {
        e*=2;
        cout<<e<<" ";
    }
    cout<<endl;

     for(auto e:arr)
    {
        cout<<e<<" ";
    }
    cout<<endl;

    cout<<"&e * 2"<<endl;
    //e将来就是arr中每一个元素的一份拷贝
    for(auto& e:arr)
    {
        e*=2;
        cout<<e<<" ";
    }
    cout<<endl;

     for(auto e:arr)
    {
        cout<<e<<" ";
    }
    cout<<endl;

// auto 
// 1 2 3 4 5 6 7 8 9 0
// e * 2
// 2 4 6 8 10 12 14 16 18 0
// 1 2 3 4 5 6 7 8 9 0
// &e * 2
// 2 4 6 8 10 12 14 16 18 0
// 2 4 6 8 10 12 14 16 18 0

    system("pause");
    return 0;
}
#endif
#if 0
//数组名作为函数的形参，已经退化为指针-->指向的是数组的首元素
//void  Print(int *arr)
void Print(int arr[10])
{
    //数组名作为函数的形参，已经退化为指针
    //而对于指针，是无法确定范围的
    //自定义类型如果要支持范围for就必须提供迭代器begin和end的方法
    //所以此方法不能达到遍历数组的目的
    for(auto e:arr)
    {
        cout<<e<<" ";
    }
    cout<<endl;
}
int main()
{
    int arr[]={1,2,3,4,5};
    for(auto &e:arr)
    {
        if(e&0x01){
            break;
        }
        e*=2;
    }
    Print(arr);

    system("pause");
    return 0;
}
#endif
#if 0
//NULL和nullptr
//在C++11之前。统一使用NULL表示空值指针
int main()
{
    //C++98
    int *p1=NULL;
    //C++11
    int *p2=nullptr;

    system("pause");
    return 0;
}
#endif
#if 0
#include<stddef.h>
int main()
{
    TestNULLPtr(10);
    TestNULLPtr(NULL);
    TestNULLPtr(nullptr);
    /*vs2019下是，但在vscode中报错，显示TestNULLPtr(NULL) is ambiguous（模糊不清的）。
    TestNULLPtr(int)
    TestNULLPtr(int)
    TestNULLPtr(int*)
    */
    
    system("pause");
    return 0;
}
#endif







