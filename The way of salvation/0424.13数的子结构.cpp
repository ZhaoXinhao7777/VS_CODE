/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
class Solution
{
public:
    bool HasSubtreeCore(TreeNode *pRoot1, TreeNode *pRoot2)
    {
        // p2位空，则递归走到这步时，之前的子树都已经和p1相等了
        if (pRoot2 == nullptr)
            return true;
        // 如果p2不为空，p1为空,则p2不是p1的子树，则返回false
        if (pRoot1 == nullptr)
            return false;

        if (pRoot1->val == pRoot2->val)
            return HasSubtreeCore(pRoot1->left, pRoot2->left) &&
                   HasSubtreeCore(pRoot1->right, pRoot2->right);
        else
            return false;
    }
    bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2)
    {
        if (pRoot2 == nullptr || pRoot1 == nullptr)
            return false;

        return HasSubtree(pRoot1->left, pRoot2) ||
               HasSubtree(pRoot1->right, pRoot2) ||
               // 或者当前节点
               HasSubtreeCore(pRoot1, pRoot2);
    }
};