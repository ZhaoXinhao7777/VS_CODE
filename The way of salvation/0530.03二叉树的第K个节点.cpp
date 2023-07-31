/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param proot TreeNode类
     * @param k int整型
     * @return int整型
     */
    // 循环
    int KthNode(TreeNode *pRoot, int k)
    {
        if (pRoot == nullptr || k == 0)
            return -1;

        stack<TreeNode *> s;
        TreeNode *node = pRoot;
        while (!s.empty() || node != nullptr)
        {
            // 将二叉树中的左侧节点全部入栈
            while (node != nullptr)
            {
                s.push(node);
                node = node->left;
            }
            // 栈顶元素出栈
            node = s.top();
            s.pop();
            if (--k == 0)
                return node->val;
            node = node->right;
        }
        return -1;
    }

    //  //中序遍历 递归
    // vector<int> res;
    // int KthNode(TreeNode* pRoot, int k) {
    //     // write code here
    //     if(pRoot==nullptr||k==0) return -1;
    //     Inorder(pRoot);
    //     if(k>res.size()) return -1;
    //     return res[k-1];
    // }
    // void Inorder(TreeNode* node)
    // {
    //     if(node==nullptr)
    //         return ;
    //     Inorder(node->left);
    //     res.push_back(node->val);
    //     Inorder(node->right);
    // }
};