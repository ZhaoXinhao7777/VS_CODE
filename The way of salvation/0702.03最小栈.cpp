// class MinStack {
// public:
// //双栈，一个记录最小栈，一个是原栈
//     stack<int>s;
//     stack<int>min;
//     MinStack() {

//     }

//     void push(int val) {
//         s.push(val);
//         if(min.empty()||val<min.top())
//             min.push(val);
//         else
//             min.push(min.top());

//     }

//     void pop() {
//         s.pop();
//         min.pop();
//     }

//     int top() {
//         return s.top();
//     }

//     int getMin() {
//         return min.top();
//     }
// };

class MinStack
{
public:
    // 单栈
    stack<int> s;
    // 即哦那个一个栈实现
    // 每次push入两个元素，
    // 第一个先push val,第二个push min值
    MinStack()
    {
    }

    void push(int val)
    {
        if (s.empty())
        {
            s.push(val);
            s.push(val);
            return;
        }

        int temp = s.top();
        s.push(val);

        if (val < temp)
        {
            s.push(val);
        }
        else
        {
            s.push(temp);
        }
    }

    void pop()
    {
        s.pop();
        s.pop();
    }

    // 没有考虑周全
    int top()
    {
        // 因为要获取栈顶元素，而栈顶元素是min栈的元素，
        // 先记录min栈顶元素，然后讲min栈顶元素出栈，、
        // 此时，栈顶元素即所求元素，
        // 但要将min栈的元素放入原栈中，不能破坏之前的栈结构
        int temp = s.top();
        s.pop();
        int num = s.top();
        s.push(temp);
        return num;
    }

    int getMin()
    {
        return s.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */