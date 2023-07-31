// 官方解答：
// 从左到右循环，记录最大值为 max，
// 若 nums[i] < max,
// 则表明位置 i 需要调整，
// 记录需要调整的最大位置 i 为 low;
// 同理，从右到左循环，
// 记录最小值为 min,
// 若 nums[i] > min,
// 则表明位置 i 需要调整，
// 记录需要调整的最小位置 i 为 high.

// 其实并不是的，而是从左向右，
// 保存该过程中的最大值，
// 当当前值与MAX进行对比，
// 如果小于的话说明已经到达了无序列表中了，
// 那就记录当前值，一直到有序列表为止，
// 此时后半部分的有序列表中的第一个值，
// 也要比前面的大或等于前面的最大值，
// 记录下的位置值就不会再改动了，
// 从右到左的部分类似
class Solution
{
public:
    // 从左往右找最大，从右往左找最小
    // 因此需要记录每一个maxNum和low,当maxNum>nums[i]时，就需要记录下标了，因为我们希望这时一个递增的数列，同理使用minNum也是这个道理
    //
    int findUnsortedSubarray(vector<int> &nums)
    {
        int len = nums.size();
        int maxNum = nums[0], minNum = nums[len - 1];
        int low = 0, high = len - 1;
        for (int i = 1; i < len; i++)
        {
            maxNum = max(maxNum, nums[i]);
            minNum = min(minNum, nums[len - 1 - i]);
            if (maxNum > nums[i])
                low = i;
            if (minNum < nums[len - i - 1])
                high = len - i - 1;
        }
        return low > high ? low - high + 1 : 0;
    }

    // int findUnsortedSubarray(vector<int>& nums) {
    //     vector<int> temp=nums;
    //     sort(nums.begin(),nums.end());
    //     int size=nums.size()-1;
    //     int count=0;
    //     bool res=1;
    //     // for(int i=0,j=size;i<j;i++,j--)
    //     int i=0,j=size;
    //     while(i<=j)
    //     {
    //         if(res)
    //         {
    //             if(nums[i]==temp[i])
    //             {
    //                 i++;
    //                 count++;
    //             }else
    //                 res=0;
    //         }
    //         else{
    //             if(nums[j]==temp[j])
    //             {
    //                 j--;
    //                 count++;
    //             }else
    //                 break;
    //         }

    //     }
    //     return size-count+1;
    // }
};