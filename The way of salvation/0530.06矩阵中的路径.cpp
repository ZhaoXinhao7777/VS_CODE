#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cstring>
using namespace std;

bool dfs(vector<vector<char>> &board, char *str, int index, int x, int y,
         vector<vector<bool>> &visited)
{
    if (index == strlen(str))
        return true;
    // 搜寻超过路径长度，符合条件，返回true，
    // 此时已经超过最大程度了 strlen返回不带 ‘\0’的长度，
    //  此时str[k]已经越界了，
    //  所以这个判断一定要放在函数开头，
    //  如果放在if之后，str[k]会越界
    if ((x < 0) || (y < 0) || (x >= board.size()) || (y >= board[0].size()))
        return false; // 访问越界，终止，返回false
    if (visited[x][y])
        return false; // 之前访问过，剪枝
    if (board[x][y] != str[index])
        return false; // 不相等，剪枝
    visited[x][y] = true;
    if (dfs(board, str, index + 1, x, y - 1, visited) || // 上
        dfs(board, str, index + 1, x, y + 1, visited) || // 下
        dfs(board, str, index + 1, x - 1, y, visited) || // 左
        dfs(board, str, index + 1, x + 1, y, visited))   // 右
        return true;                                     // 有符合要求的

    visited[x][y] = false; // 记得此处改回false，以方便下一次遍历搜索。
    return false;
}

bool hasPath(char *matrix, int rows, int cols, char *str)
{
    if (str == NULL || rows <= 0 || cols <= 0)
        return false;
    vector<vector<char>> board(rows, vector<char>(cols));
    for (int i = 0; i < rows; ++i)
    { // 将matrix装入二维数组board中
        for (int j = 0; j < cols; ++j)
        {
            board[i][j] = matrix[i * cols + j];
        }
    }
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (dfs(board, str, 0, i, j, visited) == true)
                return true; // 以矩阵board中的每个字符为起点进行广度优先搜索
            // 找到一个符合条件的即返回true.
        }
    }
    return false; // 遍历完都没找到匹配的路径，返回false
}

int main()
{
    // hasPath(char *matrix, int rows, int cols, char *str)
    //
    char str1[] = "ABCESFCSADEE";
    char str2[] = "ABCCED";
    bool ret = hasPath(str1, 3, 4, str2);
    if (ret)
        cout << "true" << endl;
    else
        cout << "false" << endl;
    system("pause");
    return 0;
}
