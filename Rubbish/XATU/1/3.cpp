#include<iostream>
#include<windows.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n][7];
    int i=0;
    //中奖号码
    int answer[7];
    while(i<n)
    {
        cin>>answer[i];
        i++;
    }
    i=0;
    while(i<n)
    {
        int j=0;
        while(j<7)
        {
            cin>>arr[i][j];
            j++;
        }   
        i++;
    }
    int han[7]={0};
    for(int i=n-1;i>=0;--i)
    {
        int count=0;
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<7;k++)
            {
                if(arr[i][j]==answer[k])
                {
                    count++;
                }
            }
        }
        han[i]=count;
    }
    for(int i=0;i<7;i++)
    {
        cout<<han[i] <<endl;
    }




    system("pause");
    return 0;
}