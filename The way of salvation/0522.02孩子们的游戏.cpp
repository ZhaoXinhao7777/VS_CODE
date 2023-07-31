class Solution
{
public:
    // 循环数组
    int LastRemaining_Solution(int n, int m)
    {
        if (n < 0 || m < 0)
            return -1;
        vector<int> res(n, 0);
        // index-位置  step-步数  count-数组中元素的个数
        int index = -1, step = 0, count = n;
        while (count)
        {
            index++;
            if (index >= n)
                index = 0;
            if (res[index] == -1)
                continue;
            step++;
            if (step == m)
            {
                res[index] = -1;
                step = 0;
                count--;
            }
        }
        return index;
    }
};

// 约瑟夫环的问题