class Solution
{
public:
    bool IsContinuous(vector<int> numbers)
    {
        sort(numbers.begin(), numbers.end());
        // 统计王的个数
        int zero = 0;
        int i = 0;
        while (numbers[i] == 0)
        {
            zero++;
            i++;
        }
        // 计算相邻两张牌的差值
        int temp = 0;
        for (; i < numbers.size() - 1; i++)
        {
            if (numbers[i] == numbers[i + 1])
                return false;
            temp += numbers[i + 1] - numbers[i] - 1;
        }
        if (zero >= temp)
            return true;
        return false;
    }
};