class Solution
{
public:
    int StrToInt(string str)
    {
        auto it = str.begin();
        long long sum = 0;
        while (it != str.end())
        {
            if (*it == '+' || *it == '-')
                it++;
            if (*it < '0' || *it > '9')
                return false;
            sum += *it;
            sum -= 48;
            sum *= 10;
            it++;
        }
        sum /= 10;
        if (*str.begin() == '-')
            sum = -1 * sum;
        return sum;
    }
};