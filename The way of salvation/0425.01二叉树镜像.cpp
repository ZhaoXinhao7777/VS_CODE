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
     * @param pRoot TreeNode类
     * @return TreeNode类
     */
    TreeNode *Mirror(TreeNode *pRoot)
    {
        // 递归版本
        if (pRoot == nullptr)
            return pRoot;
        TreeNode *newNode = pRoot;
        swap(pRoot->left, pRoot->right);
        Mirror(pRoot->left);
        Mirror(pRoot->right);
        return newNode;
    }
    // TreeNode *Mirror(TreeNode *pRoot)
    // {
    //     // 迭代版本
    //     if (pRoot == nullptr)
    //         return pRoot;
    //     // 借助队列来实现
    //     queue<TreeNode *> q;
    //     TreeNode *newNode = pRoot;
    //     q.push(pRoot);
    //     while (!q.empty())
    //     {
    //         // 每次获取队头元素
    //         TreeNode *node = q.front();
    //         // 队头元素出队
    //         q.pop();
    //         if (node)
    //         {
    //             q.push(node->left);
    //             q.push(node->right);
    //             swap(node->left, node->right);
    //         }
    //     }
    //     return newNode;
    // }
};