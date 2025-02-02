#include <stdio.h>
#include <stdlib.h>

int **generateMatrix(int n, int *returnSize, int **returnColumnSizes)
{
	*returnSize = n;
	int **ret = malloc(sizeof(int *) * n);
	*returnColumnSizes = malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		ret[i] = malloc(sizeof(int) * n);
		(*returnColumnSizes)[i] = n;
	}

	int size = n * n;
	int i = 1;
	int row = 0;
	int col = 0;
	int level = 0;
	while (i <= size)
	{
		while (i <= size && col < n - level)
		{
			ret[row][col] = i;
			i++;
			col++;
		}
		col--;
		row++;
		while (i <= size && row < n - level)
		{
			ret[row][col] = i;
			i++;
			row++;
		}
		row--;
		col--;
		while (i <= size && col >= level)
		{
			ret[row][col] = i;
			i++;
			col--;
		}
		col++;
		row--;
		while (i <= size && row >= level + 1)
		{
			ret[row][col] = i;
			i++;
			row--;
		}
		row++;
		col++;
		level++;
	}
	return ret;
}

void printMatrix(int **matrix, int size, int *colSizes)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < colSizes[i]; j++)
			printf("%3d ", matrix[i][j]); // Formatting for alignment
		printf("\n");
	}
}

int main()
{
	int	 n = 6; //change to test dif sizes;
	int	 returnSize;
	int *returnColumnSizes;

	int **matrix = generateMatrix(n, &returnSize, &returnColumnSizes);

	// Print the generated spiral matrix
	printf("Generated %dx%d Spiral Matrix:\n", n, n);
	printMatrix(matrix, returnSize, returnColumnSizes);

	// Free allocated memory
	for (int i = 0; i < returnSize; i++)
	{
		free(matrix[i]);
	}
	free(matrix);
	free(returnColumnSizes);
}
