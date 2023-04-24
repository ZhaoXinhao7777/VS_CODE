class Solution
{
public:
    int jumpFloor(int num)
    {
        // 逆向思维，从第n个台阶往下走
        // 一次下一个台阶或者两个
        // 即：f(n)=f(n-1)+f(n-2);
        // 就是斐波那契数列数列

        // 递归
        //  if(num<=1) return 1;
        //  return jumpFloor(num-1)+jumpFloor(num-2);

        // 循环：
        if (num < 3)
            return num;
        int first = 1, second = 2, third = 0;
        for (int i = 3; i <= num; ++i)
        {
            third = first + second;
            first = second;
            second = third;
        }
        return third;
    }
};