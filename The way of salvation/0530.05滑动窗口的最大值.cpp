#include <queue>
class Solution
{
public:
    // 借助优先级队列求每一个滑动窗口中最大值
    vector<int> maxInWindows(const vector<int> &num, unsigned int size)
    {
        vector<int> res;
        if (size == 0 || num.size() < size || num.size() == 0)
            return res;
        priority_queue<int> q;
        int count = 0;
        for (int i = 0; i < num.size() - size + 1; i++)
        {
            while (count < size)
            {
                q.push(num[count + i]);
                count++;
            }
            res.push_back(q.top());
            count = 0;
            while (!q.empty())
            {
                q.pop();
            }
        }
        return res;
    }
    //   //将所有滑动窗口中最大的值保存在res中，最后返回
    //   //时间复杂度：O（N^2）
    //     vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
    //         vector<int> res;
    //         if(size>num.size()||size==0)return res;

    //         for(int i=0;i<=num.size()-size;i++)
    //         {
    //             int maxNum=num[i];
    //             for(int j=i+1;j<i+size;j++)
    //             {
    //                 if(maxNum<num[j])
    //                     maxNum=num[j];
    //             }
    //             res.push_back(maxNum);
    //         }

    //         return res;
    //     }
};