class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        // 将二维数组的首元素进行排序
        sort(intervals.begin(), intervals.end(),
             [](vector<int> &a, vector<int> &b)
             { return a[0] < b[0]; });
        vector<vector<int>> res{intervals[0]};
        for (int i = 1; i < intervals.size(); i++)
        {
            if (res.back()[1] >= intervals[i][0])
            {
                res.back()[1] = max(intervals[i][1], res.back()[1]);
            }
            else
            {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};