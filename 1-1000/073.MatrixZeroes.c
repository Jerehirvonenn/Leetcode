#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void setZeroes(int **matrix, int matrixSize, int *matrixColSize)
{
	bool firstRow = false;
	bool firstCol = false;

	for (int i = 0; i < matrixSize; i++)
	{
		if (matrix[i][0] == 0)
		{
			firstCol = true;
			break;
		}
	}
	for (int i = 0; i < *matrixColSize; i++)
	{
		if (matrix[0][i] == 0)
		{
			firstRow = true;
			break;
		}
	}
	for (int i = 1; i < matrixSize; i++)
	{
		for (int j = 1; j < *matrixColSize; j++)
		{
			if (matrix[i][j] == 0)
			{
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}
	}
	for (int i = 1; i < matrixSize; i++)
	{
		for (int j = 1; j < *matrixColSize; j++)
		{
			if (matrix[i][0] == 0 || matrix[0][j] == 0)
				matrix[i][j] = 0;
		}
	}
	if (firstRow)
	{
		for (int j = 0; j < *matrixColSize; j++)
		{
			matrix[0][j] = 0;
		}
	}
	if (firstCol)
	{
		for (int i = 0; i < matrixSize; i++)
		{
			matrix[i][0] = 0;
		}
	}
}

void printMatrix(int **matrix, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			printf("%d ", matrix[i][j]);
		printf("\n");
	}
}

const int MaxCol = 10;
const int MaxRow = 10;

void set_matrix(int matrixData[10][10], int **matrix)
{
	for (int i = 0; i < MaxCol; i++)
		for (int j = 0; j < MaxCol; j++)
			matrix[i][j] = matrixData[i][j];
}

int main(void)
{

	int **matrix = (int **)malloc(MaxRow * sizeof(int *));
	for (int i = 0; i < MaxRow; i++)
		matrix[i] = (int *)malloc(MaxCol * sizeof(int));

	int rows = 5;
	int cols = 5;
	int matrixData[10][10] = {{0, 2, 3, 4, 5},
							  {4, 0, 6, 1, 5},
							  {7, 8, 9, 8, 0},
							  {4, 2, 2, 2, 1},
							  {0, 1, 2, 3, 3}};
	set_matrix(matrixData, matrix);
	printf("Original Matrix:\n");
	printMatrix(matrix, rows, cols);

	setZeroes(matrix, rows, &cols);

	printf("\nMatrix After:\n");
	printMatrix(matrix, rows, cols);

	for (int i = 0; i < MaxRow; i++)
		free(matrix[i]);
	free(matrix);
}
