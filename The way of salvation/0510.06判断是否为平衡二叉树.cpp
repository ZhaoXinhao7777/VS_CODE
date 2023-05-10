class Solution
{
public:
    // 自顶向下
    int maxDepth(TreeNode *Node)
    {
        if (Node == nullptr)
            return 0;
        return 1 + max(maxDepth(Node->left), maxDepth(Node->right));
    }
    bool IsBalanced_Solution(TreeNode *pRoot)
    {
        if (pRoot == nullptr)
            return true;
        return + &&
               IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
    }

    // // 自底向上
    // bool IsBalanced_Solution(TreeNode *pRoot)
    // {
    // }
};