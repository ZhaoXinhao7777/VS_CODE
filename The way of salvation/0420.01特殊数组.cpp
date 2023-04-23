#include <iostream>
using namespace std;

int specialArray(int* nums, int numsSize)
{
    int temp = numsSize;
    for (int i = 0; i < numsSize; i++)
    {
        int count = 0;
        for (int j = 0; j < numsSize; j++)
        {
            if (nums[j] >= temp)
            {
                count++;
            }
        }
        if (count == temp)
        {
            return count;
        }
        temp--;
    }
    return -1;
}

int main()
{
    int nums[] = { 3,5};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    cout<<specialArray(nums, numsSize);
    system("pause");
    return 0;
}