#include<iostream>
using namespace std;

int main()
{
    int n;
    long long k,T;
    cin>>n,k,T;
    //中间变量
    long long temp=1;
    //返回值
    long long count=0;
    //
    long long cur=0;
    // if(T==1)
    // {
    //     cout<<1<<endl;
    //     return 0;
    // }
    while(T>=0)
    {
        if(cur>k-1)
        {
            cur=cur%(k-1);
            count+=cur;
        }
       
        int zhouqi=n;
        for(;zhouqi>0;zhouqi--)
        {
            cur+=temp;
            temp++;
        }
        
        T--;
    }
    cout<<count-1<<endl;


    system("pause");
    return 0;
}