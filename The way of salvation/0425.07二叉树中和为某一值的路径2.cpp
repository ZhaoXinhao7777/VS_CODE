// https://www.nowcoder.com/practice/b736e784e3e34731af99065031301bca?tpId=13&&tqId=11177&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
#include <vector>
class Solution
{
public:
	void path(vector<vector<int>> &res, vector<int> &temp, TreeNode *root, int sum)
	{
		if (root == nullptr)
			return;
		temp.push_back(root->val);
		if (root->left == nullptr && root->right == nullptr && sum == root->val)
			res.push_back(temp);
		else
		{
			if (root->left)
				path(res, temp, root->left, sum - root->val); // sum - root->val
			if (root->right)
				path(res, temp, root->right, sum - root->val);
		}
		temp.pop_back();
	}
	vector<vector<int>> FindPath(TreeNode *root, int expectNumber)
	{
		vector<vector<int>> res;
		vector<int> temp;
		path(res, temp, root, expectNumber);
		return res;
	}
};