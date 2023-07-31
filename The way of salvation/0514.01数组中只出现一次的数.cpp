#include <unordered_map>
class Solution
{
public:
    // void FindNumsAppearOnce(vector<int> data, int *num1, int *num2)
    // {
    //     unordered_map<int, int> mp;
    //     // 标记，便于找出第二个在数组中出现一次的数
    //     int fir = 0;
    //     for (int i = 0; i < (int)data.size(); ++i)
    //         mp[data[i]]++;

    //     for (int i = 0; i < (int)data.size(); ++i)
    //         if (mp[data[i]] == 1)
    //         {
    //             if (fir == 0)
    //                 *num1 = data[i];
    //             fir++;
    //             else
    //                 *num2 = data[i];
    //         }
    // }
    // 利用栈，先进行排序，入栈元素与栈中元素相同，则出栈，否则入栈
    void FindNumsAppearOnce(vector<int> data, int *num1, int *num2)
    {
        sort(data.begin(), data.end());
        stack<int> s;
        for (int i = 0; i < data.size(); i++)
        {
            if (s.empty())
                s.push(data[i]);
            else if (s.top() != data[i])
                s.push(data[i]);
            if (s.top() == data[i + 1])
            {
                s.pop();
                i++;
            }
        }
        *num1 = s.top();
        s.pop();
        *num2 = s.top();
        cout << *num1 << " " << *num2 << endl;
    }
};