#pragma once
// 红黑树的性质：
// 1.每个节点不是红色就是黑色
// 2.根节点是黑色的
// 3.如果一个节点是红色，则它两个孩子是黑色
// 4.对于每个节点，从该节点到其后代所有叶子节点的简单路径，均包含相同数目的黑色节点
// 5.每个叶子节点都是黑色（此处叶子节点指空节点）
//
//
//
// 节点的默认颜色为红色
#include <iostream>
using namespace std;

enum Color
{
    RED,
    BLACK
};

template <class T>
struct RBTreeNode
{
    RBTreeNode<T> *_left;
    RBTreeNode<T> *_right;
    RBTreeNode<T> *_parent;
    T _data;
    Color _color;
    // 设定新节点都为红色
    RBTreeNode(const T &data = T(), Color color = RED)
        : _left(nullptr), _right(nullptr), _parent(nullptr), _data(data), _color(color)
    {
    }
};

// 假设data唯一
template <class T>
class RBTree
{
    typedef RBTreeNode<T> Node;
    // 红黑树相比AVLTree而言，少了_bf,但多了color,而且多了头节点(_head)

public:
    RBTree()
    {
        _head = new Node();
        _head->_parent = nullptr;
        _head->_left = _head;
        _head->_right = _head;
    }
    ~RBTree()
    {
        Destory(_head->_parent);
    }
    bool Insert(const T &data)
    {
        Node *&root = _head->_parent;
        // 1.红黑树首先是平衡二叉树，按照平衡二叉树的性质插入节点
        if (nullptr == root)
        {
            root = new Node(data, BLACK);
            root->_parent = _head;
        }
        else
        {
            // 不为空，按照平衡二叉树的性质进行插入
            // 找位置
            Node *cur = root;
            Node *parent = _head;
            while (cur)
            {
                parent = cur;
                if (data < cur->_data)
                    cur = cur->_left;
                else if (data > cur->_data)
                    cur = cur->_right;
                else
                    // data在二叉树中存在
                    return false;
            }

            // 插入新节点
            cur = new Node(data);
            if (data < parent->_data)
                parent->_left = cur;
            else
                parent->_right = cur;
            // 更新cur的父节点
            cur->_parent = parent;

            // 可能存在的问题：新节点插入后可能会违反性质3
            // 新节点的颜色为红色，如果parent的颜色也为红色
            // 则违反性质3 不能有在一起的红色节点
            while (RED == parent->_color && parent != _head)
            {
                Node *grandFather = parent->_parent;

                // 分情况：parent是grandFather的左孩子还是右孩子
                if (parent == grandFather->_left)
                {
                    Node *unclue = grandFather->_right;
                    if (unclue != nullptr && RED == unclue->_color)
                    {
                        // 情况一：叔叔节点存在且为红色
                        parent->_color = BLACK;
                        unclue->_color = BLACK;
                        grandFather->_color = RED;
                        cur = grandFather;
                        parent = cur->_parent;
                    }
                    else
                    {
                        // 要么叔叔节点不存在，如果存在一定为黑
                        // 情况二和情况三
                        if (cur == parent->_right)
                        {
                            // 情况三
                            RotateLeft(parent);
                            swap(parent, cur);
                        }

                        // 情况二
                        parent->_color = BLACK;
                        grandFather->_color = RED;
                        RotateRight(grandFather);
                    }
                }
                else
                {
                    Node *unclue = grandFather->_left;
                    if (unclue != nullptr && RED == unclue->_color)
                    {
                        // 情况一的反情况
                        parent->_color = BLACK;
                        unclue->_color = BLACK;
                        grandFather->_color = RED;
                        cur = grandFather;
                        parent = cur->_parent;
                    }
                    else
                    {

                        // 情况二和情况三的反情况
                        if (cur == parent->_left)
                        {
                            // 情况三
                            RotateRight(parent);
                            swap(parent, cur);
                        }

                        // 情况二
                        parent->_color = BLACK;
                        grandFather->_color = RED;
                        RotateLeft(grandFather);
                    }
                }
            }
        }
        _head->_left = LeftMost();
        _head->_right = RightMost();

        // 性质二：根节点必须为黑
        _head->_parent->_color = BLACK;
        return true;
    }
    void InOrder()
    {
        cout << "InOrder:";
        InOrder(_head->_parent);
        cout << endl;
    }

private:
    // 递归销毁（后序遍历）每一个节点
    void Destory(Node *&_head)
    {
        if (_head)
        {
            Destory(_head->_left);
            Destory(_head->_right);
            delete _head;
        }
    }
    void InOrder(Node *root)
    {
        InOrder(root->_left);
        cout << root->_data << " ";
        InOrder(root->_right);
    }

    Node *LeftMost()
    {
        Node *root = _head->_parent;
        if (nullptr == root)
            return _head;
        Node *cur = root;
        while (cur->_left != nullptr)
        {
            cur = cur->_left;
        }
        return cur;
    }

    Node *RightMost()
    {
        Node *root = _head->_parent;
        if (nullptr == root)
            return _head;
        Node *cur = root;
        while (cur->_right != nullptr)
        {
            cur = cur->_right;
        }
        return cur;
    }
    void RotateLeft(Node *parent)
    {
        Node *subR = parent->_right;
        Node *subRL = subR->_left;
        parent->_right = subRL;
        if (subR)
        {
            subRL->_parent = parent;
        }
        subR->_left = parent;
        Node *pparent = parent->_parent;
        parent->_parent = subR;
        subR->_parent = pparent;
        if (pparent == _head)
        {
            _head->_parent = subR;
        }
        else
        {
            if (parent == parent->_left)
            {
                pparent->_left = subR;
            }
            else
            {
                pparent->_right = subR;
            }
        }
    }

    void RotateRight(Node *parent)
    {
        Node *subL = parent->_left;
        Node *subLR = subL->_right;

        parent->_left = subLR;
        if (subLR)
        {
            subLR->_parent = parent;
        }

        subL->_right = parent;
        Node *pparent = parent->_parent;
        parent->_parent = subL;
        subL->_parent = pparent;

        if (pparent == _head)
        {
            _head->_parent = subL;
        }
        else
        {
            if (parent == pparent->_left)
                pparent->_left = subL;
            else
                pparent->_right = subL;
        }
    }
    Node *_head;
};
void TestRBTree()
{
    RBTree<int> t;
    int array[] = {16, 3, 7, 11, 9, 26, 18, 14, 15};
    for (auto e : array)
    {
        t.Insert(e);
    }

    t.InOrder();
}