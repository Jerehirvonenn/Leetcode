#include <iostream>
#include <stack>

using namespace std;

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
    static bool isSameTree(TreeNode* p, TreeNode* q)
	{
		stack<TreeNode*> tree1;
		stack<TreeNode*> tree2;

		tree1.push(p);
		tree2.push(q);
		while (!tree1.empty() && !tree2.empty())
		{
			TreeNode *ptr1 = tree1.top();
			tree1.pop();
			TreeNode *ptr2 = tree2.top();
			tree2.pop();
			if (!ptr1 && !ptr2) {
				continue;
			}
			else if (ptr1 && ptr2 && ptr1->val == ptr2->val) {
				tree1.push(ptr1->left);
				tree2.push(ptr2->left);
				tree1.push(ptr1->right);
				tree2.push(ptr2->right);
			}
			else {
				return false;
			}
		}
		return (tree1.empty() && tree2.empty());
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
	TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);
    root1->left->right->left = new TreeNode(6);
    root1->left->right->right = new TreeNode(7);
    root1->right = new TreeNode(3);
    root1->right->left = new TreeNode(8);
    root1->right->left->left = new TreeNode(9);

	TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->left->left = new TreeNode(4);
    root2->left->right = new TreeNode(5);
    root2->left->right->left = new TreeNode(6);
    root2->left->right->right = new TreeNode(7);
    root2->right = new TreeNode(3);
    root2->right->left = new TreeNode(8);
    root2->right->left->left = new TreeNode(9);

	 if (Solution::isSameTree(root1, root2))
		 cout << "Trees are same" << endl;
	 else
		 cout << "Trees are not same" << endl;

	freeTree(root1);
	freeTree(root2);
}
