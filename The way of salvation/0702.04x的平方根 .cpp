class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 0)
            return 0;
        if (x <= 3)
            return 1;
        int max = x, min = 0;
        while (max - min > 1)
        {
            int m = (max + min) >> 1;
            if (x / m < m)
                max = m;
            else
                min = m;
        }
        return min;
    }
    // 穷举法：
    //  int mySqrt(int x) {
    //  if(x==0) return 0;
    //  if(x<=3) return 1;
    //  long int i=2;
    //  for(;i<x;i++)
    //  {
    //      if((i*i<=x)&&(i+1)*(i+1)>x)
    //          return i;
    //  }
    //      return i;
    //  }
};