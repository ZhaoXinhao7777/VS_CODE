// #include <vector>
// class Solution
// {
// public:
//     vector<int> printMatrix(vector<vector<int>> matrix)
//     {
//         if (matrix.size() == 0)
//             return vector<int>();
//         if (matrix.size() == 1)
//             return matrix[0];

//         //  行                 列
//         int row = matrix.size(), col = matrix[0].size();

//         int left = 0, right = 0, top = 0, bottom = 0;

//         vector<int> new_arr;
//         while (left + right < col && top + bottom < row)
//         {
//             // 从左往右
//             for (int i = left; i < col - right; i++)
//             {
//                 new_arr.push_back(matrix[top][i]);
//             }
//             top++;
//             if (top + bottom == row)
//                 break;
//             // 右上到右下
//             for (int i = top; i < row - bottom; i++)
//             {
//                 new_arr.push_back(matrix[i][col - right - 1]);
//             }
//             right++;
//             if (left + right == col)
//                 break;
//             // 右下到左下
//             for (int i = col - right - 1; i >= left; i--)
//             {
//                 new_arr.push_back(matrix[row - bottom - 1][i]);
//             }
//             bottom++;
//             if (top + bottom == row)
//                 break;
//             // 左下到左上
//             for (int i = row - 1 - bottom; i >= top; i--)
//             {
//                 new_arr.push_back(matrix[i][left]);
//             }
//             left++;
//         }
//         return new_arr;
//     }
// };

#include <vector>
class Solution
{
public:
    vector<int> printMatrix(vector<vector<int>> matrix)
    {
        if (matrix.size() == 0)
            return vector<int>();
        if (matrix.size() == 1)
            return matrix[0];

        //  行                 列
        int row = matrix.size(), col = matrix[0].size();

        int left = 0, right = col - 1, top = 0, bottom = row - 1;

        vector<int> new_arr;
        while (left <= right && top <= bottom)
        {
            // 从左往右
            for (int i = left; i <= right; i++)
            {
                new_arr.push_back(matrix[top][i]);
            }
            top++;
            if (top > bottom)
                break;
            // 右上到右下
            for (int i = top; i <= bottom; i++)
            {
                new_arr.push_back(matrix[i][right]);
            }
            right--;
            if (left > right)
                break;
            // 右下到左下
            for (int i = right; i >= left; i--)
            {
                new_arr.push_back(matrix[bottom][i]);
            }
            bottom--;
            if (top > bottom)
                break;
            // 左下到左上
            for (int i = bottom; i >= top; i--)
            {
                new_arr.push_back(matrix[i][left]);
            }
            left++;
            if (left > right)
                break;
        }
        return new_arr;
    }
};