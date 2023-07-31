class Solution
{
public:
    int dominantIndex(vector<int> &nums)
    {
        if (nums.size() == 1)
            return 0;
        int max = 0;
        int max_i = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (max < nums[i])
            {
                max = nums[i];
                max_i = i;
            }
        }
        cout << max << endl;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0 || nums[i] == max)
                continue;
            if (max / nums[i] < 2)
                return -1;
        }
        return max_i;
    }
};