// 把只包含质因子2、3和5的数称作丑数

class Solution
{
public:
    // 三指针法
    int GetUglyNumber_Solution(int index)
    {
        // 能整除给定正整数的质数
        if (index < 7)
            return index;
        vector<int> res(index, 0); // 初始化数组
        res[0] = 1;
        int A = 0, B = 0, C = 0;
        for (int i = 1; i < index; i++)
        {
            int min_num = min(min(res[A] * 2, res[B] * 3), res[C] * 5);
            if (min_num == res[A] * 2)
                A++;
            if (min_num == res[B] * 3)
                B++;
            if (min_num == res[C] * 5)
                C++;
            res[i] = min_num;
        }
        return *(res.end() - 1);
    }
};