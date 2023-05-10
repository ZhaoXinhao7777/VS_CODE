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
    // 利用栈的特性
    //  ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    //   stack<ListNode*> s;
    //   ListNode* node=pListHead->next;
    //   int count=0;
    //   while(node!=NULL)
    //   {
    //   	s.push(node);
    //   	node=node->next;
    //   	count++;
    //   	//cout<<count<<" ";
    //   }
    //   if(k>count)
    //   	return NULL;
    //   int i=k-1;
    //   while(i>0)
    //   {
    //   	i--;
    //   	s.pop();
    //   }
    //   node=s.top();
    //   return node;
    // }

    // //遍历链表
    // ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    //     int count = 0;
    //     ListNode* node = pListHead;
    //     while (pListHead != nullptr) {
    //         count++;
    //         pListHead = pListHead->next;
    //     }
    //     count = count - k;
    //     if (count < 0) return nullptr;
    //     while (count--)
    //         node = node->next;
    //     return node;
    // }

    // 快慢指针
    ListNode *FindKthToTail(ListNode *pListHead, unsigned int k)
    {
        ListNode *fast = pListHead;
        ListNode *low = pListHead;
        while (k > 0)
        {
            k--;
            if (fast) // 防止k大于链表节点数
                fast = fast->next;
            else
                return NULL;
        }
        while (fast)
        {
            fast = fast->next;
            low = low->next;
        }
        return low;
    }
};
