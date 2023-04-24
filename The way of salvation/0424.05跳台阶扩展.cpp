class Solution
{
public:
    // f(n)=f(n-1)+f(n-2)+..+f(1)
    // f(n-1)=f(n-2)+f(n-3)+..+f(1)
    // f(n)=2*f(n-1)

    // 递归
    //  int jumpFloorII(int number) {
    //      if(number==1) return 1;
    //      return 2*jumpFloorII(number-1);
    //  }

    // 循环
    //  int jumpFloorII(int number)
    //  {
    //      int count=0,a=1;
    //      if(number==1)
    //          return 1;
    //     for(int i=2;i<=number;i++)
    //     {
    //          count=2*a;
    //          a=count;
    //     }
    //     return count;
    //  }

    // 规律：2的n-1次方
    int jumpFloorII(int number)
    {
        if (number == 1)
            return 1;
        return pow(2, number - 1);
    }
};