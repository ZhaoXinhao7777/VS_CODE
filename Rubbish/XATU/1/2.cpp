//用选择法对10个整数从小到大排序。
#include<iostream>
#include<windows.h>


using namespace std;












int func(int arr[],int len)
{
    for(int i=0;i<=len-1;++i)
    {
        for(int j=1;j<len-i;++j)
        {
            if(arr[j-1]>=arr[j])
            {
                int temp=arr[j-1];
                arr[j-1]=arr[j];
                arr[j]=temp;
            }
        }  
    }
    for(int i=0;i<len;i++)
    {
        cout<<arr[i]<<endl;
    }
}
int main()
{
    int arr[10]={0};
    int len=10;
    int i=0;
    while(i<10)
    {
        cin>>arr[i];
        i++;
    }
    func(arr,len);
    system("pause");
    return 0;
}