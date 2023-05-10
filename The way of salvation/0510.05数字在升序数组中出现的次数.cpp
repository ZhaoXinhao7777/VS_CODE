#include <unordered_map>
class Solution
{
public:
    // 哈希
    int GetNumberOfK(vector<int> data, int k)
    {
        unordered_map<int, int> mp(0);
        // for(int i=0;i<data.size();i++)
        // {
        //     mp[data[i]]++;
        // }

        for (int val : data)
        {
            if (val == k)
                mp[val]++;
        }

        return mp[k];
    }
};