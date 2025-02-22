#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
	int				 val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int maxDepth(struct TreeNode *root)
{
	if (!root)
		return 0;
	int leftDepth = maxDepth(root->left);
	int rightDepth = maxDepth(root->right);
	return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
}

struct TreeNode *createNode(int value)
{
	struct TreeNode *newNode = malloc(sizeof(struct TreeNode));
	newNode->val = value;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void freeTree(struct TreeNode *root)
{
	if (!root)
		return;
	freeTree(root->left);
	freeTree(root->right);
	free(root);
}

int main(void)
{
	// Tree 1: symmetrical 3 depth
	struct TreeNode *root = createNode(1);
	root->left = createNode(2);
	root->left->left = createNode(4);
	root->left->right = createNode(5);
	root->right = createNode(3);
	root->right->left = createNode(6);
	root->right->right = createNode(7);
	int result = maxDepth(root);
	printf("Max depth of Tree 1 is %d\n", result);
	freeTree(root);

	// Tree 2: Non-Symmetric Tree depth 4
	root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->right->left = createNode(4);
	root->right->left->right = createNode(6);
	root->right->right = createNode(5);
	result = maxDepth(root);
	printf("Max depth of Tree 2 is %d\n", result);
	freeTree(root);

	// Tree 3: Empty Tree
	root = NULL;
	result = maxDepth(root);
	printf("Max depth of Tree 3 is %d\n", result);
	freeTree(root);
}
