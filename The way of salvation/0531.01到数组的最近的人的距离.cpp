class Solution
{
public:
    // 将数组划分为三段
    // 1.最左侧有人
    // 2.最右侧有人
    // 3.两侧都有人
    int maxDistToClosest(vector<int> &seats)
    {
        int first, prev, last;
        int maxdis, count = 0;
        int n = seats.size();
        for (int i = 0; i < n; i++)
        {
            if (seats[i] == 1)
            {
                // 最左侧有人
                if (count == 0)
                {
                    first = i;
                    last = i;
                }
                else if (count >= 1)
                {
                    prev = last;
                    last = i;
                    maxdis = max(maxdis, last - prev);
                }
                count++;
            }
        }
        return max({first, n - 1 - last, maxdis / 2});
        // first 左边没人
        // n-1-last 右边没人
        // maxdis/2 两侧都有人
    }
};