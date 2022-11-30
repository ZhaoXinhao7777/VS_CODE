//连续子数组的最大和
//没成功 30%通过率
#include<iostream>
using namespace std;


int main()
{
    int N;
    cin>>N;
    int arr[N+1];
    int i=0,j=0,count=0;
    while(i<N)
    {
        cin>>arr[i];
        i++;
    }
    arr[N]=0;
    for(int i=0;i<N;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
    while(j<=N)
    {
        int temp=0;
        while(arr[j]+1==arr[j+1]||arr[j]-1==arr[j+1])
        {
            if(arr[j]>0)
            {
                temp+=arr[j];
            }
            j++;
        }
        if(arr[j]+1==arr[j-1]||arr[j]-1==arr[j-1])
        {
            if(arr[j]>0)
            {
                temp+=arr[j];
            }
        }
        if(temp>count)
        count=temp;

        j++;
    }
    cout<<count<<endl;
    system("pause");
    return 0;
}