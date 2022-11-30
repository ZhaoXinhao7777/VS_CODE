#include<stdio.h>
#include<windows.h>


void Bubble(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int main()
{
    int arr[]={0,49,48,65,97,76,13,27};
    int n=sizeof(arr)/sizeof(arr[0]);
    Bubble(arr,n);
    system("pause");
    return 0;
}
