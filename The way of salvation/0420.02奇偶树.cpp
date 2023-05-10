//���һ�ö���������������������������Գ�Ϊ ��ż�� ��
//
//���������ڵ����ڲ��±�Ϊ 0 �������ӽڵ����ڲ��±�Ϊ 1 ��������ڵ����ڲ��±�Ϊ 2 ���������ơ�
//ż���±� ���ϵ����нڵ��ֵ���� �� �����������Ұ�˳�� �ϸ����
//�����±� ���ϵ����нڵ��ֵ���� ż �����������Ұ�˳�� �ϸ�ݼ�
//����������ĸ��ڵ㣬���������Ϊ ��ż�� ���򷵻� true �����򷵻� false ��
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode.cn/problems/even-odd-tree

//�������+����

#include<queue>

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while (!q.empty())
        {
            int size = q.size();
            int prev = level % 2 == 0 ? INT_MIN : INT_MAX;
            //�жϴ˲��Ƿ���������
            //���������нڵ�Ϊż���������������εݼ�
            //ż�������нڵ�Ϊ�����������������ε���

            for (int i = 0; i < size; i++)
            {
                //��ȡ������Ԫ�أ�������Ӳ�����
                TreeNode* node = q.front();
                q.pop();
                int value = node->val;

                if (level % 2 == value % 2)
                    return false;
                //ÿһ����Ԫ���޷����бȽϣ���������INT_MIN��INT_MAX�������ٸ���prev��ֵ
                if ((level % 2 == 0 && value <= prev) || (level % 2 == 1 && value >= prev))
                    return false;
                prev = value;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            level++;
        }
        return true;
    }
};