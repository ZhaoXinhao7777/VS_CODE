//反转一个单链表
//给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* cur=head;
    struct ListNode* prev=NULL;
        while(cur)
        {
            struct ListNode* Next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=Next;
        }
        return prev;
}
*/