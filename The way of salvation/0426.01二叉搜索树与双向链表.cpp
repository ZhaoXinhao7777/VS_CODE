/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
#include <type_traits>
class Solution
{
public:
    // 返回的第一个指针，即为初值
    TreeNode *head = NULL;
    // 中序遍历当前值的上一位
    TreeNode *prev = NULL;

    TreeNode *Convert(TreeNode *pRootOfTree)
    {
        if (pRootOfTree == nullptr)
            return nullptr;
        vector<TreeNode *> result;
        stack<TreeNode *> s;

        // 形成一个中序遍历的结果，并添加指针。
        // 理解中序遍历
        while (!s.empty() || pRootOfTree != nullptr)
        {
            if (pRootOfTree != nullptr)
            {
                s.push(pRootOfTree);
                pRootOfTree = pRootOfTree->left;
            }
            else
            {
                pRootOfTree = s.top();
                s.pop();
                result.push_back(pRootOfTree);
                pRootOfTree = pRootOfTree->right;
            }
        }
        // 修改链表指针指向。
        // 很巧妙  将vector和list联系起来，通过添加左右指针，使得数组称为一个双向链表
        for (int i = 0; i < result.size() - 1; ++i)
        {
            result[i + 1]->left = result[i];
            result[i]->right = result[i + 1];
        }
        return result[0];
    }
};