/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;//父节点
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};
*/
class Solution
{
public:
    //不能存值域，只能存指针域，这是个二叉树啊，node->next是父节点，不单链表
        vector<int> v;
        TreeLinkNode* GetNext(TreeLinkNode* pNode){
            if(pNode==nullptr) return nullptr;
            TreeLinkNode* node=pNode;
            while(node->next)
                node=node->next;
            Inorder(node);
            int n=v.size();
            for(int i=0;i<n;i++)
            {
                if(v[i]==node->val)
                    return node->next;
                node=node->next;
            }
            return nullptr;

    }
        void Inorder(TreeLinkNode* node)
        {
            if(node==nullptr) return;
            Inorder(node->left);
            v.push_back(node->val);
            Inorder(node->right);
        }
    中序遍历递归处理
    vector<TreeLinkNode*> res;
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        //思路：
        //1.先将这个二叉树进行中序遍历，将结果保存到数组中
        //2.拿着节点的值与数组进行比较

        TreeLinkNode* node=pNode;
        //找根节点
        while(node->next) node=node->next;
        //中序遍历
        Inorder(node);

        int n=res.size();
        //遍历，存在则返回res[i+1],否则返回nullptr
        for(int i=0;i<n;i++)
        {
            TreeLinkNode* cur=res[i];
            if(pNode==cur)
                return res[i+1];
        }
        return nullptr;

    }
    //中序遍历，将每一个节点放入res中
    void Inorder(TreeLinkNode* node)
    {
        if(node==nullptr)
            return;
        Inorder(node->left);
        res.push_back(node);
        Inorder(node->right);
    }
    //分类直接寻找
        TreeLinkNode* GetNext(TreeLinkNode* pNode) {
            //思路：1.如果右子树存在：即找右子树中最左侧
            //     右子树不存在
            //      2.该节点为其父节点的左子树，直接返回其父节点
            //      3.为其父节点的右子树，往上找。转化为2或者4
            //      4.若为最后一个节点，则前三条都没有进去，直接返回根节点的父节点，即为nullptr
            if(pNode==nullptr) return nullptr;
            TreeLinkNode* node=nullptr;
            //1.右子树存在
            if(pNode->right)
            {
                node=pNode->right;
                while(node->left)
                {
                    node=node->left;
                }
                return node;
            }
            node=pNode;
            //2.该节点为其父节点的右子树
            while(node->next&&node==node->next->right)
            {
                node=node->next;
            }
            //3.为其父节点的左子树或者4.最后一个节点（直接返回nullptr）
            return node->next;
        }
};
