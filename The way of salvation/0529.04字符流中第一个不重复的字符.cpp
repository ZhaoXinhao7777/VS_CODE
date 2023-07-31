#include <unordered_map>
class Solution
{
public:
    // Insert one char from stringstream
    void Insert(char ch)
    {
        v.push_back(ch);
        mp[ch]++;
    }
    // return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        for (auto it : v)
        {
            if (mp[it] == 1)
                return it;
        }
        return '#';
    }
    unordered_map<char, int> mp;
    vector<char> v;
};
