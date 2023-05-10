/**
 *  struct ListNode {
 *        int val;
 *        struct ListNode *next;
 *        ListNode(int x) :
 *              val(x), next(NULL) {
 *        }
 *  };
 */
class Solution
{
public:
    vector<int> printListFromTailToHead(ListNode *head)
    {
        if (head == nullptr)
            return vector<int>();

        vector<int> result;
        // 入栈后反转
        while (head != nullptr)
        {
            result.push_back(head->val);
            head = head->next;
        }
        // //反转
        // reverse(result.begin(),result.end());

        // 不反转也可，使用反向迭代器
        return vector<int>(result.rbegin(), result.rend());
    }
};