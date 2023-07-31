class Solution
{
public:
    string decodeString(string s)
    {
        string res, temp, countStr;
        int count;
        for (auto i : s)
        {
            count = 0;
            temp = "";
            countStr = "";
            if (i != ']')
                res.push_back(i);
            else
            {
                while (res.back() != '[')
                {
                    temp += res.back();
                    res.pop_back();
                }
                // 将'['推出去
                res.pop_back();

                while (!res.empty() && res.back() >= '0' && res.back() <= '9')
                {
                    countStr += res.back();
                    res.pop_back();
                }

                reverse(countStr.begin(), countStr.end());
                count = stod(countStr, 0);
                reverse(temp.begin(), temp.end());

                for (int j = 0; j < count; ++j)
                    res += temp;
            }
        }

        return res;
    }
};