// 不分行从上往下打印出二叉树的每个节点，
// 同层节点从左至右打印。
// 例如输入{8,6,10,#,#,2,1}，
// 如以下图中的示例二叉树，
// 则依次打印8,6,10,2,1(空节点不打印，跳过)，
// 请你将打印的结果存放到一个数组里面，返回
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
#include <vector>
class Solution
{
public:
    // 借助队列实现层序遍历
    vector<int> PrintFromTopToBottom(TreeNode *root)
    {
        if (root == nullptr)
            return vector<int>();
        queue<TreeNode *> q;
        TreeNode *node = nullptr;
        vector<int> arr;
        q.push(root);

        while (!q.empty())
        {
            node = q.front();
            q.pop();
            arr.push_back(node->val);

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        return arr;
    }
};