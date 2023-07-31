class Solution
{
public:
    // 避免代码冗余
    bool equal(string &s, int left, int right)
    {
        while (left < right && s[left] == s[right])
        {
            left++;
            right--;
        }
        return left >= right;
    }
    bool validPalindrome(string s)
    {
        if (s.size() < 3)
            return true;
        int left = 0, right = s.size() - 1;
        // 需要记录第一个不相等的位置，所以不能用函数代替
        while (left < right && s[left] == s[right])
        {
            left++;
            right--;
        }
        if (left == right || right - left == 1)
            return true;
        else if (equal(s, left + 1, right) || equal(s, left, right - 1))
            return true;
        else
            return false;
    }
};