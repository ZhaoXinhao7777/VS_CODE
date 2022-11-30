#include"BT_tree.h"
#include<stdlib.h>

//创建节点
BTNode* BuyBTNode(DataType data)
{
    BTNode* NewNode=(BTNode*)malloc(sizeof(BTNode));
    NewNode->data=data;
    NewNode->left=NULL;
    NewNode->right=NULL;
    return NewNode;
}

//二叉树的创建
BTNode* BTCreate()
{
    BTNode* Node1=BuyBTNode(1);
    BTNode* Node2=BuyBTNode(2);
    BTNode* Node3=BuyBTNode(3);
    BTNode* Node4=BuyBTNode(4);
    BTNode* Node5=BuyBTNode(5);
    BTNode* Node6=BuyBTNode(6);

    Node1->left=Node2;
    Node1->right=Node4;
    Node2->left=Node3;
    Node4->left=Node5;
    Node4->right=Node6;

    return Node1;
}
// 非-递归实现先序遍历二叉树
void _PreOrder(BTNode *root){
	BTNode* stack[32], node;
	int k = -1;
 
	if (root == NULL){
		printf("tree is empty-- \n");
		return;
	}
	else{
		k++;
		// 仿照一个栈
		stack[k] = root; // 将根节点入栈
		while (k > -1){
			//出栈
			root = stack[k--];
			printf("%d-", root->data);
 
			// 先把右子树放进去，栈是先进去后出，所以下面的左子树先出
			if (root->right != NULL){
				stack[++k] = root->right;
			}
			if (root->left != NULL){
				stack[++k] = root->left;
			}
 
		}
 
	}
}
//二叉树的遍历    1.根左右 2.左根右 3.左右根
void PreOrder(BTNode* root)
{    //先序遍历 递归调用

    if(NULL==root)
    {
        return;
    }
    printf("%d",root->data);
    //打印每一个节点的平衡因子
    //printf("is the equilibrium factor of:%d ",bf(root));
    PreOrder(root->left);
    PreOrder(root->right);
}
// 非-递归实现中序遍历二叉树
void _InOrder(BTNode* root){
	BTNode* stack[32], *node;
	int top = 0;
	// 判断树是否为空
	if (root == NULL){
		printf("tree is empty-- \n");
		return;
	}
	node = root;
 
	while (node != NULL || top > 0){
 
		// 将所有的左子树节点入栈
		while (node != NULL){
			stack[++top] = node;
			node = node->left;
		}
		//  如果右节点为空的话，执行下列语句
		node = stack[top--];
 		printf("%d-", node->data);
 
		// 扫描右节点
		node = node->right;
	}
}
//中序遍历
void InOrder(BTNode* root)
{    

    if(NULL==root)
    {
        return;
    }

    InOrder(root->left);
    printf("%d-",root->data);
    InOrder(root->right);

} 
// 非-递归实现后序遍历二叉树
void _PostOrder(BTNode* root){
 
	BTNode *p = root;
	BTNode *stack[32];
	int num = 0;
	BTNode *have_visited = NULL;
 
	while (NULL != p || num>0)
	{
		while (NULL != p)
		{
			stack[num++] = p;
			p = p->left;
		}
		p = stack[num - 1];
		if (NULL == p->right || have_visited == p->right)
		{
			printf("%d-", p->data);
			num--;
			have_visited = p;
			p = NULL;
		}
		else
		{
			p = p->right;
		}
	}
	
}
//后序遍历 
void PostOrder(BTNode* root)
{   

    if(NULL==root)
    {
        return;
    }

    PostOrder(root->left);
    PostOrder(root->right);
    printf("%d-",root->data);
}

//获取二叉树节点个数
int GetBTTreeNodeSum(BTNode* root)
{
    if(NULL==root)
    {
        return 0;
    }
    return 1+GetBTTreeNodeSum(root->left)+GetBTTreeNodeSum(root->right);

}

//求树的叶子节点个数
int GetBTTreeLeafSize(BTNode* root)
{
    //度为0的节点为叶子节点
    if(NULL==root)
    {
        return 0;
    }
    if(NULL==root->left&&NULL==root->right)
    {
        return 1;
    }
    return GetBTTreeLeafSize(root->left)+GetBTTreeLeafSize(root->right);
}

//求树高度
int BTTreeHeight(BTNode* root)
{
    if(NULL==root)
    {
        return 0;
    }
//递归求子树高度
    int leftHeight=BTTreeHeight(root->left);
    int rightHeight=BTTreeHeight(root->right);
//子树高度+1（根节点)=树的高度
    return (leftHeight>rightHeight?leftHeight:rightHeight)+1;
}

//求二叉树第k层节点的个数
int BTTreeLevelKSize(BTNode* root,int k)
{
    //子树为空树
    if(NULL == root || k <= 0)
    {
        return 0;
    }

    if(1 == k)
    return 1;
    
    return BTTreeLevelKSize(root->left,k-1)+BTTreeLevelKSize(root->right,k-1);
}

//二叉树查找值为X的节点
BTNode* BTTreeFind(BTNode* root,DataType x)
{
    if(NULL==root)
    {
        return 0;
    } 
    
    BTNode* ret=NULL;
    ret=BTTreeFind(root->left,x);
    if(ret!=NULL)
    {
        return ret;
    }

    return BTTreeFind(root->right,x);
}
//计算每个结点的深度及平衡因子。
int bf(BTNode* root)
{
    if(NULL==root)
    return NULL;
    
    return BTTreeHeight(root->left)-BTTreeHeight(root->right);
}

//二叉树的销毁
void BTTreeDestory(BTNode **root)
{
    //形参root储存的是实参的地址，这个地址永不会为空
    //*root才是指向根节点
    if(NULL==*root)
    {
        return;
    }
    free(*root);
    BTTreeDestory(&(*root)->left);
    BTTreeDestory(&(*root)->right);
    *root=NULL;
}

void TestBTNode()
{
    BTNode* Node=BTCreate();
    printf("PreOrder:");
    PreOrder(Node);
    printf("\n");

    printf("_PreOrder:");
    _PreOrder(Node);
    printf("\n");

    printf("-------------\n");

    printf("InOrder:");
    InOrder(Node);
    printf("\n");
    printf("_InOrder:");
    _InOrder(Node);
    printf("\n");

    printf("-------------\n");

    printf("PostOrder:");
    PostOrder(Node);
    printf("\n");

    printf("_PostOrder:");
    _PostOrder(Node);
    printf("\n");

    printf("-------------\n");

    printf("Node sum=%d\n",GetBTTreeNodeSum(Node));

    printf("BT_tree Leaf size=%d\n",GetBTTreeLeafSize(Node));

    printf("BT_tree hright=%d\n",BTTreeHeight(Node));

    printf("BT_tree Level K Size=%d\n",BTTreeLevelKSize(Node,3));

    printf("----------------------------------------------\n");



//销毁，防止内存泄漏  二级指针，通过形参修改实参
   // BTTreeDestory(&Node);    
}
int main()
{
    TestBTNode();

    system("pause");
    return 0;
}