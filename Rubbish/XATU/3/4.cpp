#include<iostream>

using namespace std;
void Sort(unsigned long long arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<n-i;j++)
        {
            if(arr[j-1]>arr[j])
            {
                long long temp=arr[j-1];
                arr[j-1]=arr[j];
                arr[j]=temp;
            }
        }
    }
}
int main()
{
    while(1)
    {

    
    int n;
    cin>>n;
    int i=1;
    unsigned long long arr[n+1]={0};
    while(i<n+1)
    {
        cin>>arr[i];
        i++;
    }
    Sort(&arr[1],n);
    arr[0]=arr[n];
    for(int i=0;i<n+1;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    unsigned long long count=0;
    for(int i=0;i<n-1;i++)
    {
        count+=arr[i]*arr[i+1]*arr[i+2];
    }
    if(n%2==0)
    count-=arr[1]*arr[2]*arr[3];

    count+=arr[0]*arr[0]*arr[n-1];
    cout<<count<<endl;
    }
    system("pause");
    return 0;
}