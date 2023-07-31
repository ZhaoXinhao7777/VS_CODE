class Solution
{
public:
    string removeDuplicates(string s)
    {
        stack<char> st;
        string res;
        for (auto it = s.begin(); it != s.end(); it++)
        {
            if (st.empty())
            {
                st.push(*it);
            }
            else
            {
                if (*it == st.top())
                {
                    st.pop();
                }
                else
                {
                    st.push(*it);
                }
            }
        }
        while (!st.empty())
        {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// 栈 71