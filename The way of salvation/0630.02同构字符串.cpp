class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {

        if (s.size() != t.size())
            return false;
        // 借助哈希表实现
        // 使用两个哈希表，记录每一个字符所对应的另一个字符
        // 若两个哈希表相同位置对应的字符位置不一样，则返回false
        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;
        for (int i = 0; i < s.size(); i++)
        {
            mp1[s[i]] = t[i];
            mp2[t[i]] = s[i];
        }
        for (int i = 0; i < mp1.size(); i++)
        {
            if (mp1[s[i]] != t[i] || mp2[t[i]] != s[i])
                return false;
        }
        return true;
    }
};