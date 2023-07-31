class Solution
{
public:
    int findShortestSubArray(vector<int> &nums)
    {
        unordered_map<int, vector<int>> mp;
        int span = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]].push_back(i);
            span = span > mp[nums[i]].size() ? span : mp[nums[i]].size();
        }
        int minLen = nums.size(), temp;
        for (auto &r : mp)
        {
            if (r.second.size() == span)
            {
                temp = r.second[r.second.size() - 1] - r.second[0];
                minLen = minLen < temp ? minLen : temp;
            }
        }
        return minLen + 1;
    }
};