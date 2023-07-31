class Solution
{
public:
#include <vector>
    int calPoints(vector<string> &operations)
    {
        stack<int> res;
        int score, temp;
        for (auto it = operations.begin(); it != operations.end(); it++)
        {

            if (*it == "+")
            { // 表示本回合新获得的得分是前两次得分的总和
                score = res.top();
                res.pop();
                temp = res.top();
                res.push(score);
                res.push(score + temp);
            }
            else if (*it == "C") // 删除上一次成绩
            {
                res.pop();
            }
            else if (*it == "D") // 上次成绩加倍
            {
                res.push(res.top() * 2);
            }
            else
            {              // 将成绩插入res结果集中
                temp = 1;  // 记录符号 +/-
                score = 0; // 统计成绩
                for (auto a : *it)
                {
                    if (a == '-')
                        temp = -1;
                    else
                        score = score * 10 + a - '0';
                }
                res.push(score * temp);
            }
        }
        score = 0;
        while (!res.empty())
        {
            score += res.top();
            res.pop();
        }
        return score;
    }
};