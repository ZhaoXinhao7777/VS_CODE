//如果一棵二叉树满足下述几个条件，则可以称为 奇偶树 ：
//
//二叉树根节点所在层下标为 0 ，根的子节点所在层下标为 1 ，根的孙节点所在层下标为 2 ，依此类推。
//偶数下标 层上的所有节点的值都是 奇 整数，从左到右按顺序 严格递增
//奇数下标 层上的所有节点的值都是 偶 整数，从左到右按顺序 严格递减
//给你二叉树的根节点，如果二叉树为 奇偶树 ，则返回 true ，否则返回 false 。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode.cn/problems/even-odd-tree

//层序遍历+队列

#include<queue>

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while (!q.empty())
        {
            int size = q.size();
            int prev = level % 2 == 0 ? INT_MIN : INT_MAX;
            //判断此层是否满足条件
            //奇数层所有节点为偶数，从左往右依次递减
            //偶数层所有节点为奇数，从左往右依次递增

            for (int i = 0; i < size; i++)
            {
                //获取队列首元素，将其出队操作，
                TreeNode* node = q.front();
                q.pop();
                int value = node->val;

                if (level % 2 == value % 2)
                    return false;
                //每一行首元素无法进行比较，所以设置INT_MIN和INT_MAX，后面再更新prev的值
                if ((level % 2 == 0 && value <= prev) || (level % 2 == 1 && value >= prev))
                    return false;
                prev = value;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            level++;
        }
        return true;
    }
};