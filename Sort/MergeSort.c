#include<stdio.h>
#include<string.h>
#include<windows.h>
//左闭右开区间   所以begin2为mid 而不是mid+1 不然越界，会出错
void MergeData(int arr[],int left,int mid, int right,int *temp)
{
    int begin1=left;
    int end1=mid;

    int begin2=mid;
    int end2=right;

    int index=left;

    while ( begin1 < end1 && begin2 < end2 )
    {
        if(arr[begin1]<=arr[begin2])
        {
            temp[index++]=arr[begin1++];
        }
        else
        {
            temp[index++]=arr[begin2++];
        }
    }

//将另一个空间的剩余元素搬到temp中
    while(begin1<end1)
    {
        temp[index++]=arr[begin1++];
    }

    while(begin2<end2)
    {
        temp[index++]=arr[begin2++];
    }


}

void _MergeSort(int arr[],int left,int right,int *temp)
{
//二路归并 将两个有序序列归并为一个有序序列
    if(right-left<=1)
    {
        return;
    }
    //先将空间均分为两部分
    int mid=left+((right-left)>>1);

//递归排左半侧
    _MergeSort(arr,left,mid,temp);

//递归排右半侧
     _MergeSort(arr,mid,right,temp);

//将有序的左半侧 和 有序右半侧 合并为一个
     MergeData(arr,left,mid,right,temp);

     memcpy(arr+left,temp+left,(right-left)*sizeof(int));

}

//递归方法
void MergeSort(int arr[],int size)
{
    int *temp=(int*)malloc(sizeof(int)*size);

    _MergeSort(arr,0,size,temp);
    
}


//循环
void MergeSortNor(int arr[],int size)
{
    int *temp=(int*)malloc(sizeof(int)*size);

    int gap=1;
    while(gap<size)
    {
        for(int i=0;i<size;i+=2*gap)
        {
            int left=i;
            int mid=left+gap;
            int right=mid+gap;
 //加完gap后，mid和size  可能会越界
            if(mid>size)
            {
                mid=size;
            }
            if(right>size)
            {
                right=size;
            }

            MergeData(arr,left,mid,right,temp);
        }
        memcpy(arr,temp,sizeof(int)*size);
        gap*=2;//归并排序   特性
    }
}


void TestMergeSort()
{
    int arr[]={5,7,8,2,3,1,9,6,4,0};
    int size=sizeof(arr)/sizeof(arr[0]);
    //MergeSort(arr,size);
    MergeSortNor(arr,size);

    for(int i=0;i<size;i++)
    {
        printf("%d--",arr[i]);
    }
}
int main()
{
    TestMergeSort();

    system("pause");
    return 0;
}