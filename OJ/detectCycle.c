//环形链表 II
//给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
//https://leetcode.cn/problems/linked-list-cycle-ii/description/?languageTags=c%2Ccpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/*
typedef struct ListNode ListNode;
struct ListNode *detectCycle(struct ListNode *head) {
    ListNode* fast=head;
    ListNode* slow=head;
    //单节点和空链表
    if(fast==NULL||fast->next==NULL)
    {
        return NULL;
    }
    while(fast&&fast->next)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow)
        {
            break;
        }
    }
    //判断单链表
    if(fast==NULL||fast->next==NULL)
    {
        return NULL;
    }
    
    ListNode* ptr=head;
    while(slow!=ptr)
    {
        slow=slow->next;
        ptr=ptr->next;
    }
    return ptr;
}
*/

