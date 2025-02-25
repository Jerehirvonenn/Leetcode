#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
	int		val;
	struct	TreeNode *left;
	struct	TreeNode *right;
};

bool traverse_sum(struct TreeNode *root, int current)
{
	if (!root)
		return false;
	current -= root->val;
	if (!root->left && !root->right)
		return (current == 0);
	return (traverse_sum(root->left, current) ||
			traverse_sum(root->right, current));
}

bool hasPathSum(struct TreeNode *root, int targetSum)
{
	if (!root)
		return false;
	return traverse_sum(root, targetSum);
}

struct TreeNode *createNode(int val)
{
	struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	node->val = val;
	node->left = NULL;
	node->right = NULL;
	return node;
}

int main(void)
{
	/*
		 Example Tree:
				 5
			   /   \
			  4     8
			 /     / \
			11    13  4
		   /  \         \
		  7    2         1
	*/
	struct TreeNode *root = createNode(5);
	root->left = createNode(4);
	root->right = createNode(8);
	root->left->left = createNode(11);
	root->left->left->left = createNode(-7);
	root->left->left->right = createNode(2);
	root->right->left = createNode(13);
	root->right->right = createNode(4);
	root->right->right->right = createNode(1);

	int targetSum1 = 22; // Expected: true (5 -> 4 -> 11 -> 2)
	int targetSum2 = 26; // Expected: true (5 -> 8 -> 13)
	int targetSum3 = 18; // Expected: true (5 -> 8 -> 4 -> 1)
	int targetSum4 = 5;	 // Expected: false (no path ends in 5)
	int targetSum5 = 13; // Expected: true (5 -> 4 -> 11 -> -7)

	printf("Test 1: %s\n", hasPathSum(root, targetSum1) ? "true" : "false");
	printf("Test 2: %s\n", hasPathSum(root, targetSum2) ? "true" : "false");
	printf("Test 3: %s\n", hasPathSum(root, targetSum3) ? "true" : "false");
	printf("Test 4: %s\n", hasPathSum(root, targetSum4) ? "true" : "false");
	printf("Test 5: %s\n", hasPathSum(root, targetSum5) ? "true" : "false");

	free(root->right->right->right);
	free(root->right->left);
	free(root->right->right);
	free(root->left->left->right);
	free(root->left->left->left);
	free(root->left->left);
	free(root->right);
	free(root->left);
	free(root);
}
