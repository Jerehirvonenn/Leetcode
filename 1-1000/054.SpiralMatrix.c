#include <stdio.h>
#include <stdlib.h>

int *spiralOrder(int **matrix, int matrixSize, int *matrixColSize,
				 int *returnSize)
{
	int	 size = *matrixColSize * matrixSize;
	int *array = malloc(sizeof(int) * size);
	if (!array)
		return NULL;
	*returnSize = size;
	int level = 0;
	int i = 0;
	int col = 0;
	int row = 0;
	while (i < size)
	{
		while (col < *matrixColSize - level && i < size)
			array[i++] = matrix[row][col++];
		col--;
		row++;
		while (row < matrixSize - level && i < size)
			array[i++] = matrix[row++][col];
		row--;
		col--;
		while (col >= level && i < size)
			array[i++] = matrix[row][col--];
		row--;
		col++;
		while (row >= level + 1 && i < size)
			array[i++] = matrix[row--][col];
		row++;
		col++;
		level++;
	}
	return array;
}

int main(void)
{
	int matrixSize = 3;
	int matrixColSize = 4;
	int returnSize;

	int **matrix = malloc(matrixSize * sizeof(int *));
	if (!matrix)
		return (1);
	for (int i = 0; i < matrixSize; i++)
	{
		matrix[i] = malloc(matrixColSize * sizeof(int));
		if (!matrix[i])
		{
			while (i)
				free(matrix[i]);
			return (1);
		}
	}

	int counter = 1;
	for (int i = 0; i < matrixSize; i++)
		for (int j = 0; j < matrixColSize; j++)
			matrix[i][j] = counter++;

	printf("Input Matrix:\n");
	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < matrixColSize; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}

	int *result = spiralOrder(matrix, matrixSize, &matrixColSize, &returnSize);
	if (!result)
		return (1);
	printf("\nSpiral Order:\n");
	for (int i = 0; i < returnSize; i++)
		printf("%d ", result[i]);
	printf("\n");

	// Free all
	for (int i = 0; i < matrixSize; i++)
		free(matrix[i]);
	free(matrix);
	free(result);
}
