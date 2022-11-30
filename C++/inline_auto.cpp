??#include<iostream>
#include <typeinfo>
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
//C++??C?????��????????????
#if 0
//????
#define MAX 100
#define PI 3.14
//???????????
//1.????????????��????????????????
//2.???????????????

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
//??????????????????????????��??????�I????????????????
#define PI "3.14"

int main()
{
    double r=2.0;
    //cout<<PI*r*r<<endl; //"??????????????????��?????��??????????",

    //cout<<2*PI*r<<endl;

    system("pause");
    return 0;
}

#endif
#if 0
//?????C++?��????const??????????????
const int MAX=100;
const double PI=3.14;

int main()
{
    //???
    //??C++?��???const???��????????????????????????
    //??C?????��???const???��????????????????????????????????
    int arr[MAX];
    // int n;
    // int a[n];

    double r=2.0;
    cout<<PI*r*r<<endl;

    return 0;
}
#endif
#if 0
//const??????????????�I?????�I?????????
//?????��??a????????????��?????????a????????��??????????�I
int main()
{
    const int a=10;
    int *pa=(int*)&a;//????????

    *pa=100;
    cout<<a<<" "<<*pa<<endl;// 10 100
    cout<<&a<<" "<<&pa<<endl;


    return 0;
}
#endif
#if 0
//????
//????????????��??????????????????��????�I??????��??????????????????
//???
//  1.?????????????
//  2.???????
//  3.???��?????? ??120????
//  4.????????
#define Add(x,y) x*y
//#define Add(x,y) (x)*(y)
#define MAX(x,y) (x)>(y)?(x),(y);

int main()
{
    int count=Add(1+2,3+4);//???? 11 1+2*3+4 ???????1+2??*??3+4??
    cout<<count<<endl;

    system("pause");
    return 0;
}
#endif
#if 0
//????????
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
    m["apple"]="???";
    m["orange"]="????";
    m["pear"]="????";
    m["banana"]="??";

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
    //const??*??????????????��???????????????????????????
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
//C?????��?auto????????????��????????????????????????????????
//        ?????????????????????????????????????
//        ???auto?��??????????????

//C++11?��?auto???????????��??????????????��????????????????????
//  ????????????????????????????????
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

    //auto????????????????????????????????????????
    //b????????????��?????
    //auto b;

    cout<<typeid(a1).name()<<endl;
    cout<<typeid(d1).name()<<endl;
    cout<<typeid(ret).name()<<endl;

    system("pause");
    return 0;
}

#endif
#if 0
//auto??????????????
int main()
{
    int a=10;
    //auto ??????????????*???????
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
    //auto c1=30,d1=12.34;//??????????????????double,???????????int

    return 0;
}
#endif
#if 0
//???auto??????????????��????
//void Test(auto a){}//????????????????????auto

auto Test()
{return 0;}
#endif
#if 0
//auto????????????????
int main()
{
    int arr1[]={1,2,3};
    auto arr2={1,2,3};//initializer_list
    auto arr2[]={1,2,3};//????
    cout<<sizeof(arr2)<<endl;
    cout<<sizeof(int)<<endl;

    //auto arr2[]={1,2,3};//??????auto?????????????????????
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
//???????????
// ?????????????????????????��????????????
// ?????????????????????????????����?��???????????????
// C++11:?????��for???????��for
// for(auto e:??��)??e???????��??????????????????????��?e????��?��?????
// for(auto& e:??��)??e???????��?????????????????????e????��?��????

int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9,0};
    cout<<"?????"<<endl;
    
    for(auto e:arr)
    {
        cout<<e<<" ";
    }
    cout<<endl;

    cout<<"????"<<endl;
    //e??arr?????????????
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

    cout<<"????"<<endl;
    //e??arr?????????????
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

// ?????
// 1 2 3 4 5 6 7 8 9 0
// ????
// 2 4 6 8 10 12 14 16 18 0
// 1 2 3 4 5 6 7 8 9 0
// ????
// 2 4 6 8 10 12 14 16 18 0
// 2 4 6 8 10 12 14 16 18 0

    system("pause");
    return 0;
}
#endif

//��������Ϊ�������βΣ��Ѿ��˻�Ϊָ��-->ָ�����������Ԫ??
//void  Print(int *arr)
void Print(int arr[10])
{
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
    return 0
}





