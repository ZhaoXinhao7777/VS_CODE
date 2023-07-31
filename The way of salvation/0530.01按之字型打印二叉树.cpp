
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
    #include <iterator>
    class Solution
    {
    public:
        // 利用两个栈循环实现
        vector<vector<int>> Print(TreeNode *pRoot)
        {
            vector<vector<int>> res;
            if (pRoot == nullptr)
                return res;
            stack<TreeNode *> s1; // 从左往右
            stack<TreeNode *> s2; // 从右往左
            s1.push(pRoot);
            while (!s1.empty() || !s2.empty())
            {
                if (!s1.empty())
                {
                    vector<int> temp;
                    while (!s1.empty())
                    {
                        // 从左往右
                        if (s1.top()->left)
                        {
                            s2.push(s1.top()->left);
                        }
                        if (s1.top()->right)
                        {
                            s2.push(s1.top()->right);
                        }
                        // 将栈顶元素插入temp中
                        temp.push_back(s1.top()->val);
                        s1.pop();
                    }
                    // 将单次返回的结果插入res结果集中
                    res.push_back(temp);
                }
                else
                {
                    vector<int> temp;
                    while (!s2.empty())
                    {
                        // 从右往左
                        if (s2.top()->right)
                        {
                            s1.push(s2.top()->right);
                        }
                        if (s2.top()->left)
                        {
                            s1.push(s2.top()->left);
                        }
                        temp.push_back(s2.top()->val);
                        s2.pop();
                    }
                    res.push_back(temp);
                }
            }
            return res;
        }
    };