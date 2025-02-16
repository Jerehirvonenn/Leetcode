#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
	int				 val;
	struct TreeNode *left;
	struct TreeNode *right;
};

bool isMirrored(struct TreeNode *left, struct TreeNode *right)
{
	if (!left && !right)
		return true;
	if (!left || !right)
		return false;
	if (left->val != right->val)
		return false;
	return isMirrored(left->left, right->right) &&
		   isMirrored(left->right, right->left);
}

bool isSymmetric(struct TreeNode *root)
{
	if (!root)
		return (true);
	return isMirrored(root->left, root->right);
}

struct TreeNode *createNode(int val)
{
	struct TreeNode *newNode =
		(struct TreeNode *)malloc(sizeof(struct TreeNode));
	newNode->val = val;
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
	// Tree 1 - is symmetrical
	struct TreeNode *root1 = createNode(1);
	root1->left = createNode(2);
	root1->right = createNode(2);
	root1->left->left = createNode(3);
	root1->left->right = createNode(4);
	root1->right->left = createNode(4);
	root1->right->right = createNode(3);

	printf("Tree 1: Symmetric Tree\n");
	if (isSymmetric(root1))
		printf("The tree is symmetric.\n");
	else
		printf("The tree is not symmetric.\n");
	freeTree(root1);

	// Tree 2: Non-Symmetric Tree
	struct TreeNode *root2 = createNode(1);
	root2->left = createNode(2);
	root2->right = createNode(2);
	root2->left->right = createNode(3);
	root2->right->right = createNode(3);

	printf("Tree 2: Non-Symmetric Tree\n");
	if (isSymmetric(root2))
		printf("The tree is symmetric.\n");
	else
		printf("The tree is not symmetric.\n");
	freeTree(root2);

	// Tree 3: Empty Tree
	struct TreeNode *root3 = NULL;
	printf("Tree 3: Empty Tree\n");
	if (isSymmetric(root3))
		printf("The tree is symmetric.\n");
	else
		printf("The tree is not symmetric.\n");
}
