#include<iostream>
#include<windows.h>
using namespace std;

int main()
{
    int n;
    long long count=1;
    cin>>n;
    int temp=n;
    while(temp>0)
    {
        int i=temp;
        long long fcount=1;
        while(i>0)
        {
            fcount*=i;
            i--;
        }
        temp--;
        count+=fcount;
    }
    if(n==0)
    cout<<1<<endl;
    else
    cout<<count-1<<endl;
   
   system("pause");
   return 0;
}