class Solution
{
public:
    // 借助数组存储前k个最小的数字
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    {
        sort(input.begin(), input.end());
        vector<int> arr;
        for (int i = 0; i < k; i++)
        {
            arr.push_back(input[i]);
        }
        return arr;
    }
    // 堆排序
    vector<int> GetLeastNumbers_Solution1(vector<int> input, int k)
    {
        vector<int> ret;
        if (k == 0 || k > input.size())
            return ret;
        priority_queue<int, vector<int>> pq;
        for (int i = 0; i < input.size(); i++)
        {
            if (pq.size() < k)
                pq.push(input[i]);
            else
            {
                if (input[i] < pq.top())
                {
                    pq.pop();
                    pq.push(input[i]);
                }
            }
        }
        while (!pq.empty())
        {
            ret.push_back(pq.top());
            pq.pop();
        }
        return ret;
    }
};
