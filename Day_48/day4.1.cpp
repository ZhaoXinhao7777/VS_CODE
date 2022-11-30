#include<iostream>
using namespace std;

// int main()
// {
//     int a[5]={1,3,5,7,9};
//     int *p=(int*)(&a+1);
//     printf("%d %d\n",*(a+1),*(p-1));

//     system("pause");
//     return 0;


// }

// void func(char **m)
// {
//     ++m;
//     cout<<*m<<endl;
// }

// int main()
// {
//     static char *a[]={"111","222","333"};
//     char **p;
//     p=a;
//     func(p);

//     system("pause");
//     return 0;
// }

#include<algorithm>
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    double A=(a+c)/2;
    double B=(b+d)/2;
    double C=d-B;

    double x=19.11;
    cout<<x-(int)x<<endl;
    cout<<"____________"<<endl;
    if(A-(int)A>0&&B-(int)B>0&&C-(int)C>0)
    {
        cout<<"No"<<endl;
        return 0;
    }
    if(A>=30||A<0&&B>=30||B<0&&C>=30||C<0){
        cout<<"No"<<endl;
    }
    else{
        cout<<A<<" "<<B<<" "<<C<<endl;
    }
    system("pause");
    return 0;
}