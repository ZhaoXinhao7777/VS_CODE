// 判断修改那个数字其实跟再前面一个数的大小有关系
// 例子 4，2，3 修改的是[i-1]=[i];
//     3，3，2，4，修改的是[i]=[i-1]
// 即判断i的前两位是否存在，若存在[i]=[i-1]
// 否则[i-1]=[i]
class Solution
{
public:
    bool checkPossibility(vector<int> &arr)
    {
        // 用于计数，count为修改次数
        int count = 0;
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] >= arr[i - 1])
                continue;
            count++;
            if (i >= 2 && arr[i - 2] > arr[i])
                arr[i] = arr[i - 1];
            else
                arr[i - 1] = arr[i];
        }
        return count <= 1;
    }
};