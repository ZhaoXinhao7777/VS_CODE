#pragma once
// AVL树：
// 1.是二叉搜索树
// 2.条件：每个节点的左右子树高度差的绝对值不大于1 即高度为-1 0 1
//
// 高度差：平衡因子
#include <iostream>
#include <vector>
using namespace std;

template <class T>
struct AVLTreeNode
{
    typedef AVLTreeNode<T> Node;
    Node *_left;
    Node *_right;
    Node *_parent; // 双亲
    int _bf;       // 平衡因子
    int _data;

    AVLTreeNode(const T &data = T())
        : _left(nullptr), _right(nullptr), _parent(nullptr), _bf(0), _data(data)
    {
    }
};

template <class T>
class AVLTree
{
    typedef AVLTreeNode<T> Node;

public:
    AVLTree()
        : _root(nullptr)
    {
    }
    ~AVLTree()
    {
        _Destory(_root);
    }

    bool Insert(const T &data)
    {
        if (_root == nullptr)
        {
            _root = new Node(data);
            return true;
        }

        // 1.按照BST的性质找待插元素data是否在AVL树中存在
        Node *cur = _root;
        Node *parent = nullptr;
        while (cur)
        {
            // 更新parent节点
            parent = cur;

            if (data < cur->_data)
            {
                cur = cur->_left;
            }
            else if (data > cur->_data)
            {
                cur = cur->_right;
            }
            else
                return false;
        }

        // 插入新节点
        cur = new Node(data);
        if (data < parent->_data)
            parent->_left = cur;
        else
            parent->_right = cur;

        cur->_parent = parent;
        // 此上满足二叉搜索树
        // 在此基础上满足AVL树的特性
        // cur新节点插入后，parent的子树的高度就发生了变换
        // 因此需要更新parent的平衡因子
        // 平衡因子计算：此处规定为右子树高度减去左子树高度
        while (1)
        {
            if (parent->_left == cur)
                parent->_bf--;
            else
                parent->_bf++;

            if (0 == parent->_bf)
            {
                break;
            }
            else if (parent->_bf == 1 || parent->_bf == -1)
            {
                // 说明以parent为根的二叉树的高度增加了一层，此时就需要继续往上更新
                cur = parent;
                parent = cur->_parent;
            }
            else
            {
                //  parent节点已经违反平衡性
                //  parent的平衡因子为2或者-2

                // AVL树旋转 时间复杂度：O(1)
                // 单旋
                //   左单旋：新节点插入较高 右子树 的 右侧
                //   右单旋：新节点插入较高 左子树 的 左侧
                // 双旋
                //   先左单旋后右单旋
                //   右单旋后左单旋

                if (parent->_bf == 2)
                {
                    // parent的右子树高度高-- 旋转处理
                    // 左单旋
                    RotateLeft(cur);
                }
                else
                {
                    // parent的左子树高度高-- 旋转处理
                    // 右单旋
                    RotateRight(cur);
                }
            }
        }

        return true;
    }
    // 中序遍历
    void InOrder()
    {
        cout << "InOrder";
        _InOrder(_root);
        cout << endl;
    }

private:
    void _InOrder(Node *root)
    {
        if (root)
        {
            _InOrder(root->_left);
            cout << root->_data << "->";
            _InOrder(root->_right);
        }
    }

    void _Destory(Node *&root)
    {
        if (root)
        {
            _Destory(root->_left);
            _Destory(root->_right);
            delete (root);
            root = nullptr;
        }
    }
    // 左单旋
    void RotateLeft(Node *parent)
    {
        Node *subR = parent->_right;
        Node *subRL = subR->_left;

        parent->_right = subRL;

        // 注意右单只，即subRL可能为空
        if (subRL)
            subRL->_parent = parent;

        subR->_left = parent;

        Node *pParent = parent->_parent;
        parent->_parent = subR;
        subR->_parent = pParent;

        if (pParent == nullptr)
            _root = subR;
        else
        {
            if (parent == pParent->_left)
            {
                pParent->_left = subR;
            }
            else
                pParent->_right = subR;
        }

        subR->_bf = parent->_bf = 0;
    }

    // 右单旋
    void RotateRight(Node *parent)
    {
        Node *subL = parent->_left;
        Node *subLR = subL->_right;

        parent->_left = subLR;

        // 注意左单只，即subLR可能为空
        if (subLR)
            subLR->_parent = parent;

        subL->_right = parent;

        Node *pParent = parent->_parent;
        parent->_parent = subL;
        subL->_parent = pParent;

        // 判断subL是否为根节点
        if (pParent == nullptr)
            _root = subL;
        else
        {
            if (parent == pParent->_left)
            {
                pParent->_left = subL;
            }
            else
                pParent->_right = subL;
        }

        // 更新subL和parent的平衡因子
        subL->_bf = parent->_bf = 0;
    }

private:
    Node *_root;
};
void TestAVLTree()
{
    int arr[] = {5, 3, 7, 1, 4, 6, 8, 0, 2, 9};
    AVLTree<int> t;
    for (auto e : arr)
    {
        t.Insert(e);
    }
    t.InOrder();
}
