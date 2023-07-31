#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<vector<int>> arr{{1, 1, 1}, {1, 1, 1}, {1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
    int row = arr.size();
    int col = arr[0].size();
    cout << row << " " << col << endl;

    system("pause");
    return 0;
}