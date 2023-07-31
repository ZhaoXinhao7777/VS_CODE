#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool hasGroupsSizeX(vector<int> &deck)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < deck.size(); i++)
    {
        mp[deck[i]]++;
    }
    cout << mp.size() << endl;
    for (int i = 0; i < mp.size(); i++)
    {
        cout << mp[i] << endl;
    }
    // for (int i = 1; i < mp.size(); i++)
    // {
    //     cout << mp[i] << " " << mp[i - 1] << endl;
    //     if (mp[i] != mp[i - 1])
    //         return false;
    // }
    return true;
}

int main()
{
    vector<int> desk{1, 47};
    if (hasGroupsSizeX(desk))
    {
        cout << "true" << endl;
    }

    system("pause");
    return 0;
}