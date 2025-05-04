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
    static bool hasPathSum(TreeNode* root, int targetSum)
	{
		std::stack<std::pair<TreeNode*, int>> stack;

		stack.push({root, targetSum});
		while (!stack.empty())
		{
			auto [node, target] = stack.top();
			stack.pop();

			int sum = target - node->val;
			if (!sum && !node->left && !node->right) {
				return true;
			}
			if (node->left) {
				stack.push({node->left, sum});
			}
			if (node->right) {
				stack.push({node->right, sum});
			}
		}
		return false;
    }
};

int main(int ac, char **av)
{
	if (ac < 2)
		return 1;
	int target = atoi(av[1]);

	TreeNode* root1 = new TreeNode(5);
    root1->left = new TreeNode(4);
    root1->left->left = new TreeNode(11);
    root1->left->left->left = new TreeNode(7);
    root1->left->left->right = new TreeNode(2);
    root1->right = new TreeNode(8);
    root1->right->left = new TreeNode(13);
    root1->right->right = new TreeNode(4);
    root1->right->right->right = new TreeNode(1);

	if (Solution::hasPathSum(root1, target))
		std::cout << "Target: " << target << " possible" << std::endl;
	else
		std::cout << "Target: " << target << " not possible" << std::endl;
}
