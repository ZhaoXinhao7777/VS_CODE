//合并两个有序链表
//将两个升序链表合并为一个新的 升序 链表并返回。
//新链表是通过拼接给定的两个链表的所有节点组成的。 
//
/**
 * Definition for singly-linked list.
 * typedef struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * }ListNode;
 */

/*
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
   struct ListNode*head=(struct ListNode*)malloc(sizeof(struct ListNode));
   struct ListNode*prev=head;//带头结点单链表 辅助
    while(list1!=NULL&&list2!=NULL)
    {
        if(list1->val<list2->val)
        {
            prev->next=list1;
            list1=list1->next;
        }
        else
        {
            prev->next=list2;
            list2=list2->next;
        }
        prev=prev->next;
    }
      // 合并后 l1 和 l2 最多只有一个还未被合并完，我们直接将链表末尾指向未合并完的链表即可
        prev->next = list1 == NULL ? list2 : list1;

        return head->next;


}
*/