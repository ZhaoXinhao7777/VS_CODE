/*
struct RandomListNode {
int label;
struct RandomListNode *next, *random;
RandomListNode(int x) :
        label(x), next(NULL), random(NULL) {
}
};
*/
class Solution
{
public:
    typedef RandomListNode Node;
    RandomListNode *Clone(RandomListNode *pHead)
    {

        // 1.在每一个旧节点之后，创建一个新节点，并将新旧节点之间相互连接
        Node *prev = pHead;
        while (prev)
        {
            Node *temp = new Node(prev->label);
            temp->next = prev->next;
            prev->next = temp;
            prev = temp->next;
        }
        // 2.连接新节点的radom节点
        prev = pHead;
        while (prev)
        {
            Node *temp = prev->next;
            if (prev->random)
                temp->random = prev->random->next;
            prev = temp->next;
        }

        // 3.分割新旧节点
        Node *pNode = pHead;
        Node *pClonedHead = nullptr;
        Node *pClonedNode = nullptr;

        // 初始化
        if (pNode != nullptr)
        {
            pClonedHead = pNode->next;
            pClonedNode = pNode->next;
            pNode->next = pClonedNode->next;
            pNode = pNode->next;
        }
        // 循环
        while (pNode != nullptr)
        {
            pClonedNode->next = pNode->next;
            pClonedNode = pClonedNode->next;
            pNode->next = pClonedNode->next;
            pNode = pNode->next;
        }

        return pClonedHead;
    }
};