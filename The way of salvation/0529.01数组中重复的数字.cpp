#include <iostream>
#include <unordered_map>
using namespace std;

// bool duplicate(int numbers[], int length, int* duplication)
//{
//     unordered_map<int, int> mp;
//     for (int i = 0; i < length; i++)
//     {
//         mp[numbers[i]]++;
//     }
//     for (int i = 0; i < mp.size(); i++)
//     {
//         if (mp[i] > 1)
//         {
//             *duplication = mp[i];
//             return true;
//         }
//     }
//     return false;
// }
bool duplicate(int numbers[], int length, int *duplication)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < length; i++)
    {
        if (mp.find(numbers[i]) == mp.end())
        {
            mp.insert({numbers[i], 0});
        }
        else
        {
            *duplication = numbers[i];
            return true;
        }
    }

    return false;
}
int main()
{
    int arr[] = {6, 3, 2, 0, 2, 5, 0, 2};
    int temp[] = {0};
    int *duplication = temp;
    duplicate(arr, sizeof(arr) / sizeof(arr[0]), duplication);

    system("pause");
    return 0;
}