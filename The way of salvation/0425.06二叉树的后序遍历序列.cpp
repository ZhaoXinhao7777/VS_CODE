// class Solution
// {
// public:
//     bool VerifySquenceOfBST(vector<int> sequence)
//     {
//         if (sequence.size() == 0)
//             return false;
//         if (sequence.size() == 1)
//             return true;
//         return VerifySquenceOfBSTCore(sequence, 0, sequence.size() - 1);
//     }
//     bool VerifySquenceOfBSTCore(vector<int> sequence, int begin, int end)
//     {
//         // 遍历完毕
//         if (begin >= end)
//             return true;
//         int low = begin;
//         // 找新的分界线，即左子树与右子树的分解点，然后判断，进行递归
//         while (low < end && sequence[low] < sequence[end])
//             low++;
// seq[end]是根节点的位置，当然seq[i]<seq[end];
//         for (int i = low; i < end; i++)
//         {
//             if (sequence[i] <= sequence[end])
//                 return false;
//         }

//         return VerifySquenceOfBSTCore(sequence, begin, low - 1) &&
//                VerifySquenceOfBSTCore(sequence, low, end - 1);
//     }
// };

class Solution
{
public:
    bool VerifySquenceOfBST(vector<int> sequence)
    {
        if (sequence.size() == 0)
            return false;
        if (sequence.size() == 1)
            return true;
        return BST(sequence, 0, sequence.size() - 1);
    }
    bool BST(vector<int> arr, int begin, int end)
    {
        if (begin >= end)
            return true;
        int low = begin;
        // 划分区间 begin~low-1为左子树，low~end-1为右子树，end为根节点
        while (low < end && arr[low] < arr[end])
            low++;

        // 根据BSTree的性质，左子树小于右子树及根的值
        for (int i = low; i < end; i++)
        {
            if (arr[i] <= arr[end])
                return false;
        }
        return BST(arr, begin, low - 1) && BST(arr, low, end - 1);
    }
};