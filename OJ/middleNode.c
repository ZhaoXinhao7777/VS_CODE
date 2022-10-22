// 链表的中间结点
//给定一个头结点为 head 的非空单链表，返回链表的中间结点。

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
struct ListNode* middleNode(struct ListNode* head){
    struct ListNode* fast=head;
    struct ListNode* slow=head;
    while(fast!=NULL&&fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
*/