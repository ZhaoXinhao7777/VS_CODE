// 移除元素
// 给你一个数组 nums 和一个值 val，
// 你需要 原地 移除所有数值等于 val 的元素，
// 并返回移除后数组的新长度。
#include<stdio.h>
#include<windows.h>
int removeElement(int* nums, int numsSize, int val);

int main()
{
    int nums[]={3,2,2,3,2};
    printf("%d\n",removeElement(nums,5,2));

    system("pause");
    return 0;
}



int removeElement(int* nums, int numsSize, int val)
{
    int left=0,right=numsSize-1;
    while(left<=right)
    {
        if(nums[left]!=val)
        {
            left++;
        }
        else
        {
            nums[left]=nums[right];
            right--;
        }
    }
    return left;
}
// int removeElement(int* nums, int numsSize, int val){
//     int left=0,right=0;
//     for(;right<numsSize;right++)
//     {
//        if(nums[right]!=val)
//        {
//         nums[left]=nums[right];
//         left++;
//        }
//     }


//     return left;
// }