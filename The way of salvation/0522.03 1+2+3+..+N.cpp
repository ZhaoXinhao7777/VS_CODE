// 求1+2+3+...+n，
// 要求不能使用乘除法、
// for、while、if、else、switch、case等关键字
// 及条件判断语句（A?B:C）。
class Solution
{
public:
    // //利用逻辑与短路特性实现递归终止
    //     int Sum_Solution(int n) {
    //         int sum=n;
    //         bool ret=(n>0)&&(sum+=Sum_Solution(n-1));
    //         return sum;
    //     }

    //  画图，理解矩阵（bool的大小为1个字节，char也可）
    int Sum_Solution(int n)
    {
        bool arr[n][n + 1];
        // int arr[n][n+1];
        // return (sizeof(arr)/4)/2;
        return sizeof(arr) / 2;
    }
};