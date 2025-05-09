#include <iostream>
#include <stack>
#include <vector>
#include <numeric>

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

using namespace std;;

class Solution {
public:
    static  vector<vector<int>> PathSum(TreeNode* root, int targetSum)
	{
		if (!root)
			return {};
		stack<pair<TreeNode*, vector<int>>> stack;
		vector<vector<int>> result;

		stack.push({root, {}});
		while (!stack.empty())
		{
			auto [node, nums] = stack.top();
			stack.pop();
			nums.push_back(node->val);

			int sum = accumulate(nums.begin(), nums.end(), 0);
			if (sum == targetSum && !node->left && !node->right) {
				result.push_back(nums);
			}
			if (node->left) {
				stack.push({node->left, nums});
			}
			if (node->right) {
				stack.push({node->right, nums});
			}
		}
		return result;
    }
};

void printVector(const std::vector<std::vector<int>> &vec)
{
	for (const auto &row : vec) {
		for (const int &num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

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

	auto result = Solution::PathSum(root1, target);
	printVector(result);
}
