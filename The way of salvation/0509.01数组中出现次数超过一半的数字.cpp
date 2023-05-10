// #include <unordered_map>
// class Solution
// {
// public:
//     // 哈希表
//     int MoreThanHalfNum_Solution(vector<int> numbers)
//     {
//         unordered_map<int, int> mp;
//         int len = numbers.size();
//         for (int i = 0; i < len; i++)
//         {
//             mp[numbers[i]]++;
//             if (mp[numbers[i]] > len / 2)
//                 return numbers[i];
//         }
//         return 0;
//     }
// };

class Solution
{
public:
    // 借助sort排序进行计算
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        sort(numbers.begin(), numbers.end());
        int count = 0;
        int key = numbers[(numbers.size() - 1) / 2];
        for (int i = 0; i < numbers.size(); i++)
        {
            if (key == numbers[i])
                count++;
        }
        if (count > numbers.size() / 2)
            return key;
        return 0;
    }
};