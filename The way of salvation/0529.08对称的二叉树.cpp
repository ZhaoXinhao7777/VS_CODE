
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution
{
public:
    // 递归
    bool isEqual(TreeNode *L, TreeNode *R)
    {
        if (L == nullptr && R == nullptr)
            return true;
        if (L == nullptr || R == nullptr)
            return false;
        if (L->val != R->val)
            return false;

        return isEqual(L->left, R->right) && isEqual(L->right, R->left);
    }
    bool isSymmetrical(TreeNode *pRoot)
    {
        if (pRoot == nullptr)
            return true;
        return isEqual(pRoot->left, pRoot->right);
    }
};