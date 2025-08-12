#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
	int				 val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode *invertTree(struct TreeNode *root)
{
	if (!root)
	{
		return NULL;
	}
	struct TreeNode *tmp = root->left;
	root->left = root->right;
	root->right = tmp;
	invertTree(root->left);
	invertTree(root->right);
	return root;
}

struct TreeNode *newNode(int val)
{
	struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	node->val = val;
	node->left = node->right = NULL;
	return node;
}

void inorderPrint(struct TreeNode *root)
{
	if (root == NULL)
		return;
	inorderPrint(root->left);
	printf("%d ", root->val);
	inorderPrint(root->right);
}

int main(void)
{
	// tree
	//        4
	//       / \
    //      2   7
	//     / \  / \
    //    1   3 6  9
	struct TreeNode *root = newNode(4);
	root->left = newNode(2);
	root->right = newNode(7);
	root->left->left = newNode(1);
	root->left->right = newNode(3);
	root->right->left = newNode(6);
	root->right->right = newNode(9);

	printf("Original tree (in order): ");
	inorderPrint(root);
	printf("\n");

	root = invertTree(root);

	printf("Inverted tree (in order): ");
	inorderPrint(root);
	printf("\n");

	return 0;
}
