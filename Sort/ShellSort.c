#include<stdio.h>
#include<windows.h>
//希尔排序--分治
void ShellSort(int arr[],int n)
{
    int d,i,j;
    //分支区间 d 
    for(d=n/2;d>=1;d=d/2)
    {
        for(i=d+1;i<=n;++i)
        {
            if(arr[i]<arr[i-d])
            {
                arr[0]=arr[i];
            
                for(j=i-d;j>0&&arr[0]<arr[j];j-=d)
                {
                    arr[j+d]=arr[j];
                }
                arr[j+d]=arr[0];
            }
        }
    }

    

}
int main()
{
    int arr[]={0,49,48,65,97,76,13,27};
    int n=sizeof(arr)/sizeof(arr[0]);

    ShellSort(arr,n);
    for(int i=1;i<n;i++)
    {
        printf("arr[%d]=%d ",i,arr[i]);
    }
    printf("\n");
    
    system("pause");
    return 0;
}