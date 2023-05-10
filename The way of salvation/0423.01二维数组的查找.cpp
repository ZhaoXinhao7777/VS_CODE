// https://www.nowcoder.com/practice/abc3fe2ce8e146608e868a70efebf62e?tpId=13&&tqId=11154&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
#include <iostream>
#include <vector>
using namespace std;
// 从右上到左下 遍历
bool Find0(int target, vector<vector<int>> array)
{
    if (array.empty() || array[0].empty())
        return false;
    //     行数                    列数
    int row = array[0].size(), col = array.size();
    // cout << row << " " << col << endl;
    int i = col - 1, j = 0;
    while (i >= 0 && j < row)
    {
        if (array[i][j] > target)
            i--;
        else if (array[i][j] < target)
            j++;
        else
            return true;
    }
    return false;
}
// 每层用二分查找
bool Find1(int target, vector<int> &array)
{
    int start = 0, end = array.size() - 1;
    while (start + 1 < end)
    {
        int mid = start + (end - start) >> 1;
        if (array[mid] == target)
            return true;
        else if (array[mid] > target)
            end = mid;
        else
            start = mid;
    }
    if (array[end] == target || array[start] == target)
        return true;

    return false;
}
bool findNumberIn2DArray(int target, vector<vector<int>> array)
{
    if (array.empty() || array[0].empty())
        return false;
    for (int i = 0; i < array.size(); i++)
    {
        if (Find1(target, array[i]))
            return true;
    }
    return false;
}
int main()
{
    vector<vector<int>> arr;
    arr = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    bool ret = Find0(7, arr);
    ret = findNumberIn2DArray(7, arr);
    cout << ret << endl;
    system("pause");
    return 0;
}