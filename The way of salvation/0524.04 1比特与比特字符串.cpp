class Solution
{
public:
    // 没病走两步
    bool isOneBitCharacter(vector<int> &bits)
    {
        // 利用bits[i]=0||bits[i]==1进行判断
        // 若bits[i]==1,则往后走两步，否则走一步
        // 判断最后i的落点实在n-1还是在n
        int i = 0;
        while (i < bits.size() - 1)
        {
            i += bits[i] + 1;
        }
        return i == bits.size() - 1;
    }
};


