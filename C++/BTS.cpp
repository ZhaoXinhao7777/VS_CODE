#pragma once
#include <iostream>
using namespace std;

template <class T>
struct BSTNode
{
    BSTNode<T> *_left;
    BSTNode<T> *_right;
    T _data;

    //                      匿名对象
    BSTNode(const T &data = T())
        : _left(nullptr), _right(nullptr), _data(data)
    {
    }
};

template <class T>
class BSTree
{
    typedef BSTNode<T> Node;

public:
    BSTree()
        : _root(nullptr)
    {
    }
    ~BSTree()
    {
        _DestoryBSTree(_root);
    }

    // 插入
    bool Insert(const T &data)
    {
        // 判空，为空树直接插入
        if (nullptr == _root)
        {
            _root = new Node(data);
            return true;
        }

        // 非空
        // 1.借助cur在BSTree中查找是否存在值为data的元素
        // 注意：需要保存cur的parent
        Node *cur = _root;
        Node *parent = nullptr;

        while (cur)
        {
            // 出循环的调节是cur为空，即已经找到parent的位置
            parent = cur;
            if (data == cur->_data)
            {
                return false;
            }
            else if (data > cur->_data) // 值域比根节点大的都在右子树
            {
                cur = cur->_right;
            }
            else // 值域比根节点小的都在左子树
            {
                cur = cur->_left;
            }
        }

        // 2.插入新节点
        cur = new Node(data);
        if (data > parent->_data)
        {
            parent->_left = cur;
        }
        else
        {
            parent->_right = cur;
        }

        return true;
    }

    // 寻找
    Node *Find(const T &data)
    {
        Node *cur = _root;
        while (cur)
        {
            if (cur->_data > data)
            {
                cur = cur->_left;
            }
            else if (cur->_data < data)
            {
                cur = cur->_right;
            }
            else
            {
                // data的值可能不在BSTree中，所以不能在外部返回。
                //    break;
                return cur;
            }
        }

        return nullptr;
    }

    // 中序遍历
    void Inorder()
    {
        cout << "Inorder:";
        _Inorder(_root);
        cout << endl;
    }

    //*****删除节点******
    bool Erase(const T &data)
    {
        // 1.判断是否为空树
        if (_root == nullptr)
            return false;

        Node *cur = _root;
        Node *parent = nullptr;
        // 找的值为data的节点，令cur指向这个节点
        while (cur)
        {

            if (cur->_data < data)
            {
                parent = cur;
                cur = cur->_right;
            }
            else if (cur->_data > data)
            {
                parent = cur;
                cur = cur->_left;
            }
            else
            {
                break;
            }
        }

        // 判断data是否存在于BSTree
        if (cur == nullptr)
            return false;

        // 2.删除节点
        //  四种情况
        //  1和2，3任意一个可以合并
        //  2.节点右子树为空&&1.节点为叶子节点
        //  3.节点左子树为空
        //  4.都不为空

        Node *del = cur;
        if (nullptr == cur->_left) // cur的左子树不存在
        {
            if (parent == nullptr) // 即cur为根节点
            {
                _root = cur->_right;
            }
            else
            {
                // cur一定不是根节点，说明cur的双亲一定存在
                // parent一定不为空
                if (cur == parent->_left)
                {
                    parent->_left = cur->_right;
                }
                else
                {
                    parent->_right = cur->_right;
                }
            }
        }
        else if (nullptr == cur->_right) // cur的右子树不存在
        {

            if (cur == parent->_right)
            {
                parent->_left = cur->_left;
            }
            else
            {
                parent->_right = cur->_left;
            }
        }
        else
        {
            // 情况三：左右子树均存在
            // cur不能直接删除，需要在其字数中找一个代替节点
            // 将情况三变为情况一或者情况二

            // 选则在右子树中寻找代替节点
            // 理解：寻找替死鬼，其实删除的并不是原本要删除的节点，替死鬼必然是一个叶子节点，所以可以随便删除
            del = cur->_right;
            parent = cur;

            // 1.找cue右子树中最小(最左)的节点
            while (del->_left)
            {
                parent = del;
                del = del->_left;
            }
            // 2.使用del中的值域替换cur中的值域
            cur->_data = del->_data;

            // 3.删除del，注意：del可能是其双亲的左||右孩子
            if (del == parent->_left)
            {
                parent->_left = del->_right;
            }
            else
            {
                parent->_right = del->_right;
            }
        }
        delete del;
        return true;
    }

private:
    //  中序遍历入口函数
    void _Inorder(Node *root)
    {
        // 递归方法
        if (root)
        {
            _Inorder(root->_left);
            cout << root->_data << "->";
            _Inorder(root->_right);
        }
    }

    void _DestoryBSTree(Node *&root)
    {
        // 递归删除每一个节点
        if (root)
        {
            _DestoryBSTree(root->_left);
            _DestoryBSTree(root->_right);
            delete root;
            root = nullptr;
        }
    }

private:
    // 根节点
    BSTNode<T> *_root;
};

void TestBSTree()
{
    BSTree<int> t;
    int a[] = {8, 3, 1, 10, 6, 4, 7, 14, 13};
    for (auto e : a)
    {
        t.Insert(e);
    }
    t.Inorder();

    if (!t.Find(9))
    {
        t.Insert(9);
    }
    t.Inorder();

    t.Erase(3);
    t.Inorder();

    t.Erase(8);
    t.Inorder();
}

int main()
{
    TestBSTree();
    system("pause");
    return 0;
}