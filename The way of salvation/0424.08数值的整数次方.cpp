class Solution
{
public:
    // https://leetcode.cn/problems/shu-zhi-de-zheng-shu-ci-fang-lcof/solution/shu-zhi-de-zheng-shu-ci-fang-by-leetcode-yoqr/
    //  递归
    double quickMul(double x, long long N)
    {
        if (N == 0)
            return 1.0;

        double y = quickMul(x, N / 2);
        //

        return N % 2 == 0 ? y * y : y * y * x;
    }
    double Power(double base, int exponent)
    {
        long long N = exponent;
        return N >= 0 ? quickMul(base, N) : 1.0 / quickMul(base, -N);
    }

    // 迭代
    double quickMul(double x, long long N)
    {
        double res = 1.0;
        // 贡献的初始值为x,
        double x_con = x;
        // 在对N进行二进制拆分的同时计算答案
        while (N > 0)
        {
            // 如果N的二进制表示二点最低位位1，那么需要计入贡献
            if (N % 2 == 1)
            {
                res *= x_con;
            }
            // 将贡献不断地平方
            x_con *= x_con;
            // 舍弃N二进制表示的最低位，这样只需每次判断最低位即可
            N /= 2;
        }
        return res;
    }
    double Power(double x, int n)
    {
        long long N = n;
        return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }
    // double Power(double base, int exponent)
    // {
    //     double count = base;
    //     if (exponent == 0)
    //         return 1;
    //     if (base == 0.0)
    //         return 0.0;
    //     // 注意exponent的正负
    //     if (exponent > 0)
    //     {
    //         while (exponent != 1)
    //         {
    //             count *= base;
    //             exponent--;
    //         }
    //     }
    //     else
    //     {
    //         while (exponent != 1)
    //         {
    //             count /= base;
    //             exponent++;
    //         }
    //     }
    //     if (base < 0 && exponent % 2 == 0)
    //     {
    //         count = -count;
    //     }
    //     return count;
    // }
};

//  当n == INT_MIN时正数是大于INT_MAX的，所以要用一个大于 INT_MAX的类型来保存，
//  同时在将他转正的时候， n*(-1)的结果依然是一个 int，
//  此时的int是个隐藏类型，然后才将这个结果赋值给 exp，
//  所以用来保存结果值的不应该是个int型，我们用double型的 -1 ,
//  这样就可以将相乘的结果值保存为一个 double类型了，然后再进行赋值
