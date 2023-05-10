class Solution
{
public:
    // int NumberOf1Between1AndN_Solution(int n) {
    //     if(n<=0) return 0;
    //     if(n<10) return 1;

    //     int count=0;
    //     while(n)
    //     {
    //         int temp=n;
    //         while(temp)
    //         {
    //             if(temp%10==1)
    //             {
    //                 count++;
    //             }
    //             temp/=10;
    //         }
    //         n--;
    //     }
    //     return count;
    // }

    // 纯数学方法：首位Cn 1 *10^（n-1）+末尾;
    int NumberOf1Between1AndN_Solution(int n)
    {
        if (n <= 0)
            return 0;
        if (n < 10)
            return 1;
        int high = n, pow = 1; // 最高位 以及 最高位的权重

        // 取最高位系数
        while (high >= 10)
        {
            high /= 10;
            pow *= 10;
        }

        int last = n - high * pow;            // 去除最高位数字
        int cnt = high == 1 ? last + 1 : pow; // high是否为1，最高位的1个数不同
        return cnt + high * NumberOf1Between1AndN_Solution(pow - 1) + NumberOf1Between1AndN_Solution(last);
    }
};