class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int size = nums.size() - 1;
        return max(nums[size] * nums[size - 1] * nums[size - 2], nums[0] * nums[1] * nums[size]);
    }
};
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main()
// {
//     vector<int> nums;
//     nums.push_back(-100);
//     nums.push_back(-90);
//     nums.push_back(-1);
//     nums.push_back(2);
//     nums.push_back(3);
//     nums.push_back(4);

//     // 没有考虑最小的两个负数与最大的正数
//     //  //  = {-100, -90, -1, 2, 3, 4};
//     //  sort(nums.begin(), nums.end());
//     //  for (auto it : nums)
//     //  {
//     //      cout << it << " " << endl;
//     //  }
//     //  int size = nums.size() - 1;

//     // cout << nums[size] * nums[size - 1] * nums[size - 2] << endl;
//     // system("pause");

//     // if (nums.size() == 3)
//     //     return nums[0] * nums[1] * nums[2];
//     // sort(nums.begin(), nums.end());
//     // int result = 0, max = nums[nums.size() - 1], lastMax = nums[nums.size() - 2];
//     // int secondMin = nums[1];

//     // if (secondMin < 0)
//     // {

//     //     int temp = nums[0] * secondMin * max;
//     //     result = max * lastMax * nums[nums.size() - 3];
//     //     result = result > temp ? result : temp;
//     // }
//     // else
//     // {
//     //     result = max * lastMax * nums[nums.size() - 3];
//     // }
//     // cout << result << endl;
//     system("pause");

//     return 0;
// }