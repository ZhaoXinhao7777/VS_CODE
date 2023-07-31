
// /*
// struct ListNode {
//     int val;
//     struct ListNode *next;
//     ListNode(int x) :
//         val(x), next(NULL) {
//     }
// };
// */
// // 利用哈希表实现删除链表中重复的节点
// class Solution
// {
// public:
//     ListNode *deleteDuplication(ListNode *pHead)
//     {
//         unordered_map<int, int> mp;
//         ListNode *temp = pHead;
//         // 遍历链表，将统计出现过的val的次数
//         while (temp)
//         {
//             mp[temp->val]++;
//             temp = temp->next;
//         }
//         // 增加一个新表头
//         ListNode *newHead = new ListNode(0);
//         newHead->next = pHead;
//         temp = newHead;
//         while (temp->next)
//         {
//             if (temp->next)
//             {
//                 // val!=1，即为重复出现的节点，应该删除
//                 if (mp[temp->next->val] != 1)
//                 {
//                     temp->next = temp->next->next;
//                 }
//                 else
//                 {
//                     // 否则往后找
//                     temp = temp->next;
//                 }
//             }
//         }
//         return newHead->next;
//     }
// };
ListNode *deleteDuplication(ListNode *pHead)
{
    if (pHead == nullptr || pHead->next == nullptr)
        return pHead;
    ListNode *preHead = new ListNode(0); 
    preHead->next = pHead;

    ListNode *pre = preHead;
    ListNode *cur = pHead;
    while (cur)
    {
        ListNode *nextDifferent = cur->next;
        while (nextDifferent && nextDifferent->val == cur->val) 
        // nextDifferent表示下一个不同数的节点
            nextDifferent = nextDifferent->next;
            
        if (cur->next == nextDifferent)
        { // 如果代表前后两个数不同，那么可以更新pre和cur
            pre->next = cur;
            pre = cur;
            cur = nextDifferent;
        }
        else
        {
            cur = nextDifferent; // 这里表示当前cur有重复值，那么就把cur更新到下一个数，pre不动
        }
    }
    pre->next = cur;
    return preHead->next;
}