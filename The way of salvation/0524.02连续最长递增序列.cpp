class Solution
{
public:
    int findLengthOfLCIS(vector<int> &nums)
    {
        int count = 0;
        int temp = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] < nums[i])
            {
                temp++;
            }
            else
            {
                count = max(temp, count);
                temp = 0;
            }
        }
        // 防止for中的else走不进去，即：原数组是递增的
        count = max(temp, count);
        return count + 1;
    }
};