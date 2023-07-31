
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
    // 利用队列实现对二叉树的层序遍历
    vector<vector<int>> Print(TreeNode *pRoot)
    {
        vector<vector<int>> res;
        if (pRoot == nullptr)
            return res;
        queue<TreeNode *> q;
        q.push(pRoot);
        while (!q.empty())
        {
            int len = q.size();
            vector<int> temp;
            while (len--)
            {
                TreeNode *node = q.front();
                q.pop();
                temp.push_back(node->val);

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            res.push_back(temp);
        }
        return res;
    }
};