#include<stdio.h>
#include<windows.h>

void Select(int arr[],int n)
{
   for(int i=0;i<n-1;i++)
   {
    int min=i;
        for(int j=i+1;j<n;j++)
        {
        
            if(arr[min]>arr[j])
            {
                min=j;
            }
        }
    int temp=arr[i];
    arr[i]=arr[min];
    arr[min]=temp;
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
    Select(arr,n);
    Print(arr,n);   

    system("pause");
    return 0;
}