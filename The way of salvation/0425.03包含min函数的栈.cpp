class Solution
{
public:
    void push(int value)
    {
        if (min_s.size() == 0 && s.size() == 0)
        {
            s.push(value);
            min_s.push(value);
        }
        else
        {
            s.push(value);
            if (value <= min_s.top())
            {
                min_s.push(value);
            }
            else
            {
                min_s.push(min_s.top());
            }
        }
    }
    void pop()
    {
        s.pop();
        min_s.pop();
    }
    int top()
    {
        return s.top();
    }
    int min()
    {

        return min_s.top();
    }
    stack<int> s;
    stack<int> min_s;
};