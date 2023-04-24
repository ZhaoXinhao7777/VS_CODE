#include <iostream>
#include <vector>
using namespace std;
int Fibonacci(int n)
{
    if (n == 1 || n == 2)
        return 1;
    if (n == 3)
        return 2;
    vector<int> f(3);
    f[0] = 1;
    f[1] = 1;
    f[2] = 2;
    for (int i = 3; i < n; ++i)
    {
        f[i % 3] = f[(i - 1) % 3] + f[(i - 2) % 3];
    }
    return f[(n - 1) % 3];
}

int Fibonacci(int n)
{
    int f1 = 1, f2 = 1;
    int f3 = 0;
    if (n == 1 | n == 2)
    {
        return 1;
    }
    while (n - 2)
    {
        f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
    }
    return f3;
}
int main()
{
    cout << Fibonacci(3) << endl;
    system("pause");
    return 0;
}