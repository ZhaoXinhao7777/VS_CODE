class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {

        int count = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            auto it = lower_bound(nums.begin() + i + 1, nums.end(), k + nums[i]);
            if (it == nums.end())
            {
                break;
            }
            if (*it == k + nums[i])
                count++;
        }
        return count;
    }
};