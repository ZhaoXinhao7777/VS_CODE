class Solution
{
public:
    // 数学知识
    // 左+nums[i]+右=数组和(total)
    // 左==右(sum)
    // 2*sum+nums[i]==total
    int pivotIndex(vector<int> &nums)
    {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (total == 2 * sum + nums[i])
                return i;
            sum += nums[i];
        }
        return -1;
    }
};