 //删除有序数组中的重复项
 //给你一个 升序排列 的数组 nums ，
 //请你 原地 删除重复出现的元素，使每个元素 只出现一次 
 //返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。


#include<stdio.h>
#include<windows.h>

int removeDuplicates(int* nums, int numsSize);

int main()
{
    int nums[]={1,2,2,3,3};
    printf("%d\n",removeDuplicates(nums,5));

    system("pause");
    return 0;
}
int removeDuplicates(int* nums, int numsSize){
    if(numsSize==0)
    return 0;

    int fast=1,slow=1;

    while(fast<numsSize)
    {
        if(nums[fast]!=nums[fast-1])    
        {
            nums[slow]=nums[fast];  
            slow++;
        }
        fast++;
    }
    return slow;
}