// 轮转数组
//给你一个数组，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。
// https://leetcode.cn/problems/rotate-array/description/  
void rotate(int* nums, int numsSize, int k) {
    int newnums[numsSize];
    for(int i=0;i<numsSize;i++)//3
    {
        newnums[(i+k)%numsSize]=nums[i];
    }
    for(int i=0;i<numsSize;i++)
    {
        nums[i]=newnums[i];
    }

}