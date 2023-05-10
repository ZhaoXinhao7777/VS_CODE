/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
class Solution
{
public:
    ListNode *ReverseList(ListNode *pHead)
    {
        // 借助三个节点完成逆序
        if (pHead == nullptr || pHead->next == nullptr)
            return pHead;
        ListNode *prev = nullptr;
        ListNode *cur = pHead;
        ListNode *after = pHead->next;
        while (cur)
        {
            cur->next = prev;
            prev = cur;
            cur = after;
            if (after)
                after = after->next;
        }
        return prev;
    }
};