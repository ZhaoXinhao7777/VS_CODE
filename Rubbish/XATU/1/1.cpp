//打印出所有"水仙花数"，所谓"水仙花数"是指一个三位数，\
//其各位数字立方和等于该本身。 例如：153是一个水仙花数，因为153=1^3+5^3+3^3。 
#include<iostream>
#include<math.h>
#include<windows.h>
using namespace std;
void func(int n)
{
    int temp=n;
    int count=0;
    while(temp>0)
    {
        count+=pow((temp%10),3);
        temp/=10;
    }
    if(count==n)
    cout<<count<<endl;
     
}
int main()
{
    int n=100;
    while(n<1000)
    {
        func(n);
        n++;
    }
    system("pause");
    return 0;
}