#include <iostream>
#include <stack>
using namespace std;
bool backspaceCompare(string s, string t)
{
    stack<char> s1;
    stack<char> s2;
    for (int i = 0; i < s.size(); i++)
    {
        // 注意else匹配的if是哪一个，第一次犯错了
        if (s[i] == '#')
        {
            if (!s1.empty())
                s1.pop();
        }

        else
            s1.push(s[i]);
    }
    for (int i = 0; i < t.size(); i++)
    {
        if (t[i] == '#')
        {
            if (!s2.empty())
                s2.pop();
        }

        else
            s2.push(t[i]);
    }

    while (!s1.empty() && !s2.empty())
    {
        if (s1.top() != s2.top())
            return false;
        s1.pop();
        s2.pop();
    }
    if (!s1.empty() || !s2.empty())
        return false;
    return true;
}
int main()
{
    string s = "ab#c", t = "ad#c";
    bool ret = backspaceCompare(s, t);
    cout << ret << endl;
    system("pause");
    return 0;
}