class Solution
{
public:
    // 哈希表
    vector<int> FindNumbersWithSum(vector<int> arr, int sum)
    {
        vector<int> tmp;
        unordered_map<int, int> mp;

        // 在哈希表中查找sum-arr[i]
        for (int i = 0; i < arr.size(); i++)
        {
            int temp = sum - arr[i];
            if (mp.find(temp) == mp.end())
            {
                // 在容器中寻找值为k的元素，返回该元素的迭代器。否则，返回map.end()

                mp[arr[i]] = i;
            }
            else
            {
                tmp.push_back(temp);
                tmp.push_back(arr[i]);
                break;
            }
        }
        return tmp;
    }
    //   //双指针法
    //     vector<int> FindNumbersWithSum(vector<int> arr, int sum) {
    //         vector<int> tmp;
    //         int l = 0, r = arr.size() - 1;
    //         while (l < r) {
    //             if (arr[l] + arr[r] > sum) {
    //                 r--;
    //             } else if (arr[l] + arr[r] < sum) {
    //                 l++;
    //             } else {
    //                 tmp.push_back(arr[l]);
    //                 tmp.push_back(arr[r]);
    //                 break;
    //             }
    //             //cout<<arr[l]<<" "<<arr[r]<<endl;
    //         }
    //         return tmp;

    //     }
};