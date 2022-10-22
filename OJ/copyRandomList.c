//复制带随机指针的链表
//
// 给你一个长度为 n 的链表，
// 每个节点包含一个额外增加的随机指针 random 
// 该指针可以指向链表中的任何节点或空节点。
// 构造这个链表的 深拷贝。 
// 深拷贝应该正好由 n 个 全新 节点组成，
// 其中每个新节点的值都设为其对应的原节点的值。
// 新节点的 next 指针和 random 指针也都应指向复制链表中的新节点，
// 并使原链表和复制链表中的这些指针能够表示相同的链表状态。
// 复制链表中的指针都不应指向原链表中的节点 。
//
//https://leetcode.cn/problems/copy-list-with-random-pointer/description/
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */
/*
typedef struct Node Node;
struct Node* copyRandomList(Node* head) {
    if(head==NULL)
    {
        return NULL;
    }
    //1.在原链表每个节点之后插入值相等的新节点
    for(Node* node=head;node!=NULL;node=node->next->next)
    {
        Node*newNode=(Node*)malloc(sizeof(Node));
        newNode->val=node->val;
        newNode->next=node->next;
        node->next=newNode;
    }
    //2.给新插入的新节点的随机指针域赋值
    for(Node* node=head;node!=NULL;node=node->next->next)
    {
        Node* nodeNew=node->next;

        //nodeNew->random=(node->random!=NULL)?node->random->next:NULL;
        if(node->random==NULL)
        {
            newNode->random=NULL;
        }else
        {
            newNode->random=node->random->next;
        }
       
    }
    Node* headNew=head->next;
    //3.挑出新链表的每个节点，并链接
    for(Node* node=head;node!=NULL;node=node->next)
    {
        Node* NodeNew=node->next;
        node->next=node->next->next;
        NodeNew->next=(NodeNew->next!=NULL)?NodeNew->next->next:NULL;
    }
    return headNew;
}
*/