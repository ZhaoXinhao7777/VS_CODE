#pragma once
#include <iostream>
using namespace std;

using namespace std;

#include <deque>
namespace Zzxh
{
    // 实现栈的时候，默认是对vector进行了封装
    // 而STL底层使用的是deque
    // 为社么？
    template <class T, class Container = std::deque<T>>
    class stack
    {
    public:
        stack() {}
        void push(const T &val)
        {
            c.push_back(val);
        }
        void pop()
        {
            if (empty())
            {
                return;
            }
            c.pop_back();
        }

        T &top()
        {
            return c.back();
        }
        const T &top() const
        {
            return c.back();
        }
        size_t size() const
        {
            return c.size();
        }
        bool empty()
        {
            return c.empty();
        }

    private:
        Container c;
    };
}

void TestMyStack()
{
    Zzxh::stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    cout << s.size() << endl;
    cout << s.top() << endl;

    s.pop();
    s.pop();

    cout << s.size() << endl;
    cout << s.top() << endl;
}
