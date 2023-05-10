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
    // 双指针 思路：a+b=b+a
    ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
    {
        if (pHead1 == nullptr || pHead2 == nullptr)
            return nullptr;
        ListNode *Node1 = pHead1;
        ListNode *Node2 = pHead2;
        while (Node1 != Node2)
        {
            Node1 = Node1->next;
            Node2 = Node2->next;

            // 防止出现两节点不相交，发生死循环
            if (Node2 == nullptr && Node1 == nullptr)
                return nullptr;

            if (Node1 == nullptr)
                Node1 = pHead2;
            if (Node2 == nullptr)
                Node2 = pHead1;
        }
        return Node1;
    }
};
