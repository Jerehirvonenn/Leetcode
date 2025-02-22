#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
	int				 val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int minDepth(struct TreeNode *root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	if (root->left == NULL && root->right != NULL)
		return 1 + minDepth(root->right);
	if (root->left != NULL && root->right == NULL)
		return 1 + minDepth(root->left);
	int left = minDepth(root->left);
	int right = minDepth(root->right);
	if (left < right)
		return 1 + left;
	else
		return 1 + right;
}

struct TreeNode *newNode(int value)
{
	struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	node->val = value;
	node->left = node->right = NULL;
	return node;
}

int main(void)
{
	struct TreeNode *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	int depth = minDepth(root);
	printf("Minimum Depth: %d\n",
		   depth); // Should print 2, as node 3 is a leaf at depth 2.

	return 0;
}
