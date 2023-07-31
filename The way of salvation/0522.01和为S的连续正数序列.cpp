class Solution
{
public:
    // 类似TCP滑动窗口机制
    vector<vector<int>> FindContinuousSequence(int sum)
    {
        vector<vector<int>> res;
        int low = 1, high = 2;
        while (low < high)
        {
            int temp_sum = (low + high) * (high - low + 1) >> 1;
            if (temp_sum == sum)
            {
                vector<int> temp_res;
                for (int i = low; i <= high; i++)
                {
                    temp_res.push_back(i);
                }
                res.push_back(temp_res);
                low++;
            }
            else if (temp_sum < sum)
            {
                high++;
            }
            else
            {
                low++;
            }
        }
        return res;
    }
};