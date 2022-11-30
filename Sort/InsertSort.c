#include<stdio.h>
#include<windows.h>
void Insert(int arr[],int n)
{
    int i,j,key;
    for(i=1;i<n;i++)
    {
        key=arr[i];
        j=i-1;
        while((j>=0)&&(key<arr[j]))
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
void Print(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main()
{
    int arr[]={0,49,48,65,97,76,13,27};
    int n=sizeof(arr)/sizeof(arr[0]);
    Print(arr,n);
    Insert(arr,n); 
    Print(arr,n);
    system("pause");
    return 0;
}