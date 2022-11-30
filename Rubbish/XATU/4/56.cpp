#include<iostream>

using namespace std;

int main()
{
    long long n,k,T;
    cin>>n>>k>>T;
    long long arr[n*T]={0};
    long long temp=1;
    arr[0]=1;
    while(temp<n*T)
    {
        arr[temp]=arr[temp-1]+temp;
        temp++;
        if(arr[temp]>k-1)
        {
            arr[temp]%=(k-1);
        }
    }
    long long count=arr[0];
    temp=n-1;
    while(temp<=n*T)
    {
        count+=arr[temp];
        temp+=n;
    }
    cout<<count<<endl;

    system("pause");
    return 0;
}