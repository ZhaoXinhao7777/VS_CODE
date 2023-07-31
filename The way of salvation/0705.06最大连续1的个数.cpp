class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        size_t result = 0, cut = 0;
        for (auto &num : nums)
        {
            if (num == 1)
                cut++;
            else
            {
                result = max(result, cut);
                cut = 0;
            }
        }
        result = max(result, cut); // 这一步千万别忘了
        return result;
    }
};