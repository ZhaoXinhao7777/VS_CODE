#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int FirstNotRepeatingChar(string str)
{
    unordered_map<char, int> mp;
    for (int i = 0; i < str.size(); ++i)
    {
        mp[str[i]] += 1;
    }

    for (int i = 0; i < str.size(); ++i)
    {
        if (mp[str[i]] == 1)
            return i;
    }
    return -1;
}

int main()
{
    string str = "cba";
    cout << FirstNotRepeatingChar(str) << endl;

    system("pause");
    return 0;
}