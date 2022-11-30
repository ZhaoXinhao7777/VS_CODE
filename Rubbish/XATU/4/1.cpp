#include<iostream>
using namespace std;
int  func(int n,long long k,long long T)
{
    //中间变量
    long long temp=1;
    //返回值
    long long count=0;
    //
    long long cur=1;

    if(T==1)
    {
        cout<<1<<endl;
        return 0;
    }
    while(T>0)
    {
        count+=cur; 

        int zhouqi=n;
        for(;zhouqi>0;zhouqi--)
        {
            cur+=temp;
            if(cur>k-1)
            {
                cur=cur%(k-1);
                cur=cur-1;

                 
            }
            temp++;
        }   

        T--;
    }
    cout<<count<<endl;
    return 0;
}
int main()
{
    int n;
    long long k,T;
    cin>>n;
    cin>>k;
    cin>>T;

    func(n,k,T);


    system("pause");
    return 0;
}
