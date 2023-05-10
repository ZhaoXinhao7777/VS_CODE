/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
#include <new>
class Solution
{
public:
    // ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
    //  if(pHead1==nullptr)
    //      return pHead2;
    //  if(pHead2==nullptr)
    //      return pHead1;
    //  //将两个链表先连接起来，遍历整个链表，通过sort()，将其val进行排序，之后直接给新链表赋值即可
    //     vector<int>arr;
    //  ListNode*temp=pHead1;
    //  ListNode*newHead=temp;
    //  while(temp->next)
    //  {
    //      arr.push_back(temp->val);
    //      temp=temp->next;
    //  }
    //  //
    //  temp->next=pHead2;
    //  while(temp)
    //  {
    //      arr.push_back(temp->val);
    //      temp=temp->next;
    //  }
    //  sort(arr.begin(),arr.end());
    //  temp=newHead;
    //  int i=0;
    //  while(temp)
    //  {
    //      temp->val=arr[i];
    //      temp=temp->next;
    //      i++;
    //  }
    //  return newHead;
    // }

    ListNode *Merge(ListNode *pHead1, ListNode *pHead2)
    {
        if (pHead1 == nullptr)
            return pHead2;
        if (pHead2 == nullptr)
            return pHead1;

        ListNode *newHead = new ListNode(-1);
        ListNode *node = newHead;
        while (pHead1 && pHead2)
        {
            // 确保每次phead1的首元素比phead2的首元素小
            if (pHead1->val > pHead2->val)
            {
                swap(pHead1, pHead2);
            }
            node->next = pHead1;
            pHead1 = pHead1->next;
            node = node->next;
        }
        node->next = (pHead1 ? pHead1 : pHead2);
        return newHead->next;
    }
};