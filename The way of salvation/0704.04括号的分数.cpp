class Solution
{
public:
    int scoreOfParentheses(string s)
    {
        // 求括号深度
        int deep = 0, ans = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
                deep++;
            else
                deep--;
            if (s[i] == ')' && s[i - 1] == '(')
            {
                ans += 1 << deep;
            }
        }
        return ans;
    }
};