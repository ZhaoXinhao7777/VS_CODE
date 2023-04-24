// https://www.nowcoder.com/practice/72a5a919508a4251859fb2cfb987a0e6?tpId=13&&tqId=11163&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
// 矩阵覆盖，还是变种的斐波那契数列
// 如果第n个方块竖着放，则剩余大长方形的长度为n-1,
// 如果第n个方块横着放，则剩余大长方形的长度为n -2,
// f(n)=f(n-1)+f(n-2)
class Solution
{
public:
    int rectCover(int num)
    {
        if (num <= 3)
            return num;
        vector<int> f(3);
        f[0] = 1;
        f[1] = 2;
        f[2] = 3;
        for (int i = 3; i <= num; ++i)
        {
            f[2] = f[1] + f[0];
            f[0] = f[1];
            f[1] = f[2];
        }
        return f[2];
    }
};