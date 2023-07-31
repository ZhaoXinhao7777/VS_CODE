// // https://leetcode.cn/problems/happy-number/
// // 对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
// // 然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
// // 如果这个过程 结果为 1，那么这个数就是快乐数。
// //
// //
// class Solution
// {
// public:
//     // 借助unordered_set进行查重
//     bool isHappy(int n)
//     {
//         if (n <= 0)
//             return false;
//         unordered_set<int> s;
//         int sum;
//         while (n != 1)
//         {
//             sum = 0;
//             while (n > 9)
//             {
//                 sum += (n % 10) * (n % 10);
//                 n /= 10;
//             }
//             sum += n * n;
//             if (s.find(sum) != s.end()) // 查重，防止出现重复的，即不符合条件
//                 return false;
//             else
//                 s.insert(sum);
//             n = sum;
//         }
//         return true;
//     }
// };
// 利用哈希表进行将每一个值存储，如果存在已出现的数字，则直接返回false.
// 否则先判断这个数每一位的平方和是否为一
class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_map<int, int> mp(0);

        while (1)
        {
            int temp = 0;
            int count;
            while (n >= 10) // 计算每一位的平凡数
            {
                count = n % 10;
                n /= 10;
                temp += count * count;
            }
            temp += n * n;
            mp[temp]++;
            if (temp == 1)
            {
                if (mp[temp] == 1)
                    // cout << "hello" << endl;
                    return true;
                else
                    break;
            }
            if (mp[temp] != 1)
                break;
            n = temp;
        }
        return false;
    }
};