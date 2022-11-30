#include<iostream>
using namespace std;

int judge_num(int n)
{
    int temp=2;
    while(temp!=n)
    {
        //不符合条件
        if(n%temp==0)
        {
            return 1;
        }
        temp++;
    }
    //符合条件
    return 0;
}

int judge_arr(int arr[],int n)
{
    int temp=2;
    int cont=1;
    while(temp!=arr[n])
    {
        //判断其子集是否为质数
        if(arr[n]%temp!=0)
        {
            temp++;
        }
        else{
            if(0==judge_num(arr[n]/temp))
            {
                return 1;
            }
            else
            return 0;
            
        }

    }
    
}

int judge(int arr[],int n)
{
        //返回值为1，则不满足条件
        if(1==judge_arr(&arr[n],n))
        {
            return 1;
        }
        else
        return 0;
    
}
int main()
{
    int n;
    cin>>n;
    int arr[n]={0};
    int brr[n]={0};
    int i=0;
    while(i<n)
    {
        cin>>arr[i];
        i++;
    }

    for(int i=0;i<n;i++)
    {
        brr[i]=judge(&arr[i],i);
    }

    for(int i=0;i<n;i++)
    {
        if(brr[i]==1)
        {
            cout<<"No"<<endl;
        }
        else
        cout<<"yes"<<endl;
    }


    system("pause");
    return 0;
}