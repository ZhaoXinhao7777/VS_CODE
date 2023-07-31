class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        // 借助set有序，不重复的特性
        set<int> s;
        for (int num : nums)
        {
            s.insert(num);
            if (s.size() > 3)
                s.erase(s.begin());
        }
        return s.size() == 3 ? *s.begin() : *s.rbegin();
    }
};