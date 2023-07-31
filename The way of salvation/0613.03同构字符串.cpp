class Solution
{
public:
    // 判断字符第一次出现的位置
    bool isIsomorphic(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        for (int i = 0; i < s.size(); i++)
        {
            if (s.find(s[i]) != t.find(t[i]))
                return false;
        }
        return true;
    }

    // //利用哈希表进行判断
    //     bool isIsomorphic(string s, string t) {
    //         if(s.size()!=t.size())
    //             return false;
    //         unordered_map<char,char> mp1(s.size()),mp2(s.size());
    //         for(int i=0;i<s.size();i++)
    //         {
    //             mp1[s[i]]=t[i];
    //             mp2[t[i]]=s[i];
    //         }
    //         for(int i=0;i<s.size();i++)
    //         {
    //             if(mp1[s[i]]!=t[i]||mp2[t[i]]!=s[i])
    //                 return false;
    //         }
    //         return true;
    //   }
};