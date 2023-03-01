#include <iostream>
using namespace std;
#include <stack>

void TestStack()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    cout << s.size() << endl;
    cout << s.top() << endl;

    s.top() = 60;
    cout << s.top() << endl;

    s.pop();
    s.pop();
    s.pop();

    cout << s.size() << endl;
    cout << s.top() << endl;
}
int main()
{
    TestStack();
    system("pause");
    return 0;
}