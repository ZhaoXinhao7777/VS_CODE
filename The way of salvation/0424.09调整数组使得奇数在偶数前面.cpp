class Solution
{
public:
    //   //暴力解法：创建一个新数组 空间复杂度：O(N),时间复杂度：O(N)
    //     void reOrderArray(vector<int>& array) {
    //         vector<int>new_arr;
    //         //找原数组中的奇数，并将其插入新数组中
    //         for (int i = 0; i < array.size(); i++) {
    //             if (array[i] % 2 != 0) {
    //                 new_arr.push_back(array[i]);
    //             }
    //         }
    //         //找原数组中的偶数，并将其插入新数组中
    //         for (int i = 0; i < array.size(); i++) {
    //             if (array[i] % 2 == 0) {
    //                 new_arr.push_back(array[i]);
    //             }
    //         }
    //         array.assign(new_arr.begin(),new_arr.end());
    //     }
    // 类冒泡解法，只不过是往前遍历  空间复杂度：O(1),时间复杂度：O(N^2)
    void reOrderArray(vector<int> &array)
    {
        for (int i = 0; i < array.size(); i++)
        {
            for (int j = array.size() - 1; j > i; j--)
            {
                if (array[j] % 2 == 1 && array[j - 1] % 2 == 0)
                {
                    swap(array[j - 1], array[j]);
                }
            }
        }
    }
};