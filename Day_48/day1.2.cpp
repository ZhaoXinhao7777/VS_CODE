#include <iostream>
#include <string>
using namespace std;
 
int main()
{
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    for (int i = 0; i < str2.size(); i++)
    {
        int index;
        while((index=str1.find(str2[i]))!=-1)
        {
            str1.erase(index, 1);
        }
    }
    cout << str1 << endl;
    system("pause");
    return 0;
}
