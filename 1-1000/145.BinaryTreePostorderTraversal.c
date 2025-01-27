#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
	int				 val;
	struct TreeNode *left;
	struct TreeNode *right;
};

void free_tree(struct TreeNode *root)
{
	if (!root)
		return;
	free_tree(root->left);
	free_tree(root->right);
	free(root);
}

struct TreeNode *create_node(int value, struct TreeNode *root)
{
	struct TreeNode *new = malloc(sizeof(struct TreeNode));
	if (!new)
	{
		free_tree(root);
		exit(1);
	}
	new->val = value;
	new->left = NULL;
	new->right = NULL;
	return new;
}

void traverse_tree(struct TreeNode *root, int *size, int *array)
{
	if (!root)
		return;
	traverse_tree(root->left, size, array);
	traverse_tree(root->right, size, array);
	array[*size] = root->val;
	(*size)++;
}

int *postorderTraversal(struct TreeNode *root, int *returnSize)
{
	*returnSize = 0;
	if (!root)
	{
		free_tree(root);
		exit(1);
	}
	int *array = (int *)malloc(sizeof(int) * 100);
	traverse_tree(root, returnSize, array);
	return array;
}

int main(void)
{
	struct TreeNode *root = create_node(1, NULL);
	root->left = create_node(2, root);
	root->left->left = create_node(4, root);
	root->left->right = create_node(5, root);
	root->left->right->left = create_node(6, root);
	root->left->right->right = create_node(7, root);
	root->right = create_node(3, root);
	root->right->right = create_node(8, root);
	root->right->right->left = create_node(9, root);
	int	 size = 0;
	int *array = postorderTraversal(root, &size);
	printf("Postorder Tree:");
	for (int i = 0; i < size; i++)
		printf(" %d", array[i]);
	printf("\n");
	free(array);
	free_tree(root);
}
