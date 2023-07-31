// #include <iostream>
// using namespace std;
// #include <string>
// #include <vector>
vector<vector<int>> largeGroupPositions(string s)
{
    vector<vector<int>> res; // 返回结果集
    for (int i = 0; i < s.size();)
    {
        // 注意边界处理
        int count = 1;

        while (s[i] == s[i + 1])
        {
            count++;
            i++;
        }
        if (count >= 3)
        {
            cout << s[i] << endl;
            res.push_back({i - count + 1, i});
        }
        i++;
    }
    return res;
}
// int main()
// {
//     string s("abcdddeeeeaabbbcd");
//     largeGroupPositions(s);

//     system("pause");
//     return 0;
// }