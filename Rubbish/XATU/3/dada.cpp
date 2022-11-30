#include <iostream>
using namespace std;
 
int n, a[405], dp[405][405], ans; 
 
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        a[i+n] = a[i];
    }
    for (int len = 2; len <= n; ++len)
        for (int i = 1; i + len - 1 <= 2*n; ++i)
        {
            int j = i + len - 1;
            for (int k = i; k < j; ++k)
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k+1][j] + a[i] * a[k+1] * a[j+1]);
        }
    for (int i = 1; i <= n; ++i)
        ans = max(ans, dp[i][i+n-1]);
    cout << ans << endl;
    system("pause");
    return 0;
}

//5
//78 234 9280 0247 9025 2425
//1788880210