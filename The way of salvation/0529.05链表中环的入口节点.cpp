
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/

//双指针法 当两指针相遇,对于fast指针来说,在环中剩余的步数与链表头部到环的入口节点步数相等
//利用数学公式证明
class Solution
{
public:
    // 双指针法
    ListNode *EntryNodeOfLoop(ListNode *pHead)
    {
        ListNode *fast = pHead;
        ListNode *slow = pHead;

        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                break;
        }
        if (!fast || !fast->next)
            return NULL;
        slow = pHead; // low从链表头出发
        while (fast != slow)
        { // fast从相遇点出发
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }

    //     //借助哈希表实现
    // ListNode* EntryNodeOfLoop(ListNode* pHead) {
    //     unordered_map<ListNode*,int> mp;
    //     ListNode* temp=pHead;
    //     while(temp)
    //     {
    //         mp[temp]++;
    //         if(mp[temp]>1)
    //             return temp;
    //         temp=temp->next;
    //     }
    //     return nullptr;
    // }
};