
class Solution
{
public:
    // 常规做法
    //  int minNumberInRotateArray(vector<int> arr) {
    //      int min=arr[0];
    //      int length=arr.size();
    //      for(int i=1;i<length;i++)
    //      {
    //          if(arr[i]<min)
    //              min=arr[i];
    //      }
    //      return min;
    //  }
    //  二分法
    int minNumberInRotateArray(vector<int> arr)
    {
        if (arr.size() == 0)
            return 0;
        int left = 0, right = arr.size() - 1;
        // left+1是因为如果只有两个元素...
        while (left + 1 < right)
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] < arr[right])
                right = mid;
            // 此处是 元素为 8，8，8，8...
            else if (arr[mid] == arr[right])
                right -= 1;
            else
                left = mid;
        }
        return min(arr[left], arr[right]);
    }
};
