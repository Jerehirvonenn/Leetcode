#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
	int				 val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int countNodes(struct TreeNode *root)
{
	if (!root)
		return 0;
	return 1 + countNodes(root->left) + countNodes(root->right);
}

void fillArray(struct TreeNode *root, int *array, int *index)
{
	if (root->left)
		fillArray(root->left, array, index);
	array[*index] = root->val;
	(*index)++;
	if (root->right)
		fillArray(root->right, array, index);
}

int *inorderTraversal(struct TreeNode *root, int *returnSize)
{
	if (!root)
	{
		*returnSize = 0;
		return NULL;
	}
	int	 size = countNodes(root);
	int *array = (int *)malloc(sizeof(int) * size);
	int	 index = 0;
	fillArray(root, array, &index);
	*returnSize = size;
	return array;
}

int main()
{
	//      1
	//     / \
    //    2   3
	struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	root->val = 1;
	root->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	root->left->val = 2;
	root->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	root->right->val = 3;

	root->left->left = NULL;
	root->left->right = NULL;
	root->right->left = NULL;
	root->right->right = NULL;

	int	 returnSize;
	int *result = inorderTraversal(root, &returnSize);

	printf("Inorder traversal: ");
	for (int i = 0; i < returnSize; i++)
		printf("%d ", result[i]);
	printf("\n");

	free(result);
	free(root->left);
	free(root->right);
	free(root);
}
