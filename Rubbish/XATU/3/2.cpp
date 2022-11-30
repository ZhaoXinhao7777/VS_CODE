#include<iostream>
using namespace std;

int judge(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        if(arr[i-1]!=arr[i])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n;//n名学生
    cin>>n;
    int arr[n]={0};
    int i=0;
    int jug=0;
    //输入分发糖果数目
    while(i<n)
    {
        cin>>arr[i];
        i++;
    }

    //如果每一人糖果不相等，则进while调整
    while(1)
    {
        if(judge(arr,n)==1)
        {
            break;
        }
        int cur[n]={0};
        for(int i=0;i<n;i++)
        {
            cur[i]=(arr[i]/2);
        }
        for(int i=0;i<n;i++)
        {
            if(i==n-1)
            arr[n-1]=arr[n-1]/2+cur[0];
            else
            arr[i]=arr[i]/2+cur[i+1];
        }
        for(int i=0;i<n;i++)
        {
            if(arr[i]%2!=0)
            {
                arr[i]++;
                jug++;
            }
        }
    }
    
    cout<<jug<<endl;



    system("pause");
    return 0;
}