#include<stdio.h>
#include<windows.h>

int main()
{
    int n;
    int count=0;
    scanf("%d",&n);
    //1.申请空间
    int *arr=(int*)malloc(sizeof(int)*n);
    //2.输入元素
    for(int i=0;i<n;i++)
    {
        int n;
        scanf("%d",&n);
        arr[i]=n;
    }

    for(int i=0;i<n;i++)
    {
        if(arr[i]!=0)
        count++;
    }
    int *cur=(int*)malloc(sizeof(int)*count);
    for(int i=0,j=0;i<n;i++)
    {
        if(arr[i]!=0){
        cur[j]=arr[i];
        j++;
        }   
    }
    for(int i=0;i<count;i++)
    {
        printf("%d",cur[i]);
        if(i!=count-1)
        printf(" ");
    }
    printf("\n");

    printf("%d",count);
    // for(int i=0;i<n;i++)
    // {
    //     printf("%d ",arr[i]);
    // }
    

    system("pause");
    return 0;
}