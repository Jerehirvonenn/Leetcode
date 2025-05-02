#include <iostream>
#include <stack>

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    static std::vector<int> inorderTraversal(TreeNode* root)
	{
		std::stack<TreeNode*>	stack;
		std::vector<int>		result;

		while (root || !stack.empty())
		{
			//move all the way to leftmost node
			while (root)
			{
				stack.push(root);
				root = root->left;
			}

			//process node
			root = stack.top();
			stack.pop();
			result.push_back(root->val);

			//move to right if possible
			root = root->right;
		}
		return result;
    }
};

void	freeTree(TreeNode *root)
{
	if (!root)
		return;
	std::stack<TreeNode*> stack;

	stack.push(root);
	while (!stack.empty())
	{
		root = stack.top();
		stack.pop();
		if (root->left)
			stack.push(root->left);
		if (root->right)
			stack.push(root->right);
		delete root;
	}
}

int main(void)
{
	TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(8);
    root->right->left->left = new TreeNode(9);

	std::vector<int> result = Solution::inorderTraversal(root);
	for (const int &num : result)
		std::cout << num << " ";
	std::cout << std::endl;

	freeTree(root);
}
