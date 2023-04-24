class Solution
{
public:
    void push(int node)
    {
        s1.push(node);
    }

    int pop()
    {
        while (s1.size() != 1)
        {
            s2.push(s1.top());
            s1.pop();
        }
        int val = s1.top();
        s1.pop();
        // 每次只出一个元素，所以得把s2中的数字重新放到s1中
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return val;
    }

private:
    stack<int> s1; // 保存元素
    stack<int> s2; // 辅助栈
};