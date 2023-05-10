#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin)
{
    if (pre.size() == 0 || vin.size() == 0)
        return nullptr;
    // 获取首元素
    TreeNode *node = new TreeNode(pre[0]);

    int mid = distance(begin(vin), find(vin.begin(), vin.end(), pre[0]));

    vector<int> left_pre(pre.begin() + 1, pre.begin() + mid + 1);
    vector<int> right_pre(pre.begin() + mid + 1, pre.end());
    vector<int> left_in(vin.begin(), vin.begin() + mid);
    vector<int> right_in(vin.begin() + mid + 1, vin.end());

    node->left = reConstructBinaryTree(left_pre, left_in);
    node->right = reConstructBinaryTree(right_pre, right_in);
    return node;
}

int main()
{
    vector<int> pre = {1, 2, 4, 7, 3, 5, 6, 8};
    vector<int> vin = {4, 7, 2, 1, 5, 3, 8, 6};
    reConstructBinaryTree(pre, vin);

    system("pause");
    return 0;
}