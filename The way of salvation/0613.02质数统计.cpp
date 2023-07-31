class Solution
{
public:
    // 新思想：厄拉多塞筛法
    // 假设n=20，因为0，1不是质数，2为第一个质数，
    // 而2的倍数一定不为质数，所以将2的倍数全部置为0，依此类推...
    // 后面的数字不断被更新
    int countPrimes(int n)
    {
        vector<int> arr(n);
        int count = 0;
        // 因为0，1不为质数，2为第一个质数，所以从2开始
        for (int i = 2; i < n; i++)
        {
            arr[i] = 1;
        }
        for (int i = 2; i < n; i++)
        {
            // 判断数组内数字是否为质数
            if (arr[i])
            {
                count++;
                for (int j = 2 * i; j < n; j += i) // 质数的倍数一定不为质数，更新数组
                {
                    arr[j] = 0;
                }
            }
        }
        return count;
    }
    // int judge(int n)
    // {
    //     for (int i = 2; i < n; i++)
    //     {
    //         if (n % i == 0)
    //             return 0;
    //     }
    //     return 1;
    // }
    // int countPrimes(int n)
    // {
    //     if (n <= 2)
    //         return 0;
    //     int count = 0;
    //     for (int i = 2; i < n; i++)
    //     {
    //         count += judge(i);
    //     }
    //     return count;
    // }
};