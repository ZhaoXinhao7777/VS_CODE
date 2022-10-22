//链表的回文结构
//对于一个链表，请设计一个时间复杂度为O(n),额外空间复杂度为O(1)的算法，判断其是否为回文结构。
//给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构。保证链表长度小于等于900。
//https://www.nowcoder.com/practice/d281619e4b3e4a60a2cc66ea32855bfa?tpId=49&&tqId=29370&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
/*
class PalindromeList {
  public:
    bool chkPalindrome(ListNode* A) {
        // write code here
        if (A == NULL) {
            return false;
        }
        else if (A->next == NULL) {
            return true;
        }
//1.找中间节点
        ListNode* fast = A;
        ListNode* slow = A;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
//2.反转后一半链表
        ListNode* p = slow->next;
        ListNode* p1 = p->next;

        while (p != NULL) {
            p->next=slow;
            slow=p;
            p=p1;
            p1=p1->next;
        }
//3.判断是否为回文结构
        while(A!=slow)
        {
            if(A->val!=slow->val)
            {
                return false;
            }
            else
            {
                if(A->next==slow)
                {
                    return true;
                }
            }
            A=A->next;
            slow=slow->next;
        }
        return true;
    }


};
*/