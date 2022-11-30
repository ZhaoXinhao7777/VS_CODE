#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

typedef int DataType;

typedef struct BTNode
{
    struct BTNode* left;
    struct BTNode* right;
    DataType data;
}BTNode;

//节点的创建
BTNode* BuyBTNode(DataType data);

//二叉树的创建
BTNode* BTCreate();

//二叉树的遍历 1.根左右 2.左根右 3.左右根
void BTPrint(BTNode* BTNode);

//获取二叉树节点个数
int GetBTTreeNodeSum(BTNode* root);

//获取二叉树叶子节点个数
int GetBTTreeLeafSize(BTNode* root);

//求二叉树第k层节点的个数
int BTTreeLevelKSize(BTNode* root,int k);

//二叉树查找值为X的节点
BTNode* BTTreeFind(BTNode* root,DataType x);

//二叉树的销毁
void BTTreeDestory(BTNode **Node);

//计算每个结点的深度及平衡因子。
int bf(BTNode* root);