#include <iterator>
class Solution
{
public:
    vector<int> res;
    void Insert(int num)
    {
        res.push_back(num);
    }

    double GetMedian()
    {
        sort(res.begin(), res.end());
        int len = res.size();
        if (len % 2 == 1)
        {
            return 1.0 * res[len >> 1];
        }
        else
        {
            return 1.0 * (res[len >> 1] + res[(len >> 1) - 1]) / 2;
        }
    }
};