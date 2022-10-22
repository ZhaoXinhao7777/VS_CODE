//链表分割 较难
//现有一链表的头指针 ListNode* pHead，
//给一定值x，编写一段代码将所有小于x的结点排在其余结点之前，
//且不能改变原来的数据顺序，返回重新排列后的链表的头指针。
//

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
/*
//带头节点单链表
class Partition {
  public:
    ListNode* partition(ListNode* pHead, int x) {
        // write code here
    ListNode* highhead,*hightail,*lowhead,*lowtail;
    ListNode* cur=pHead;

    highhead=hightail=(ListNode*)malloc(sizeof(ListNode));
    lowhead=lowtail=(ListNode*)malloc(sizeof(ListNode));

        while(cur)
        {
            if(cur->val<x)
            {
                lowtail->next=cur;
                lowtail=lowtail->next;    
            }
            else
            {
                hightail->next=cur;
                hightail=hightail->next;  
            }
            cur=cur->next;
        }
        hightail->next=NULL;//
        lowtail->next=highhead->next;
        return lowhead->next;
    }
};
*/