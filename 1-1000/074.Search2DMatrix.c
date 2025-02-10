#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool searchMatrix(int **matrix, int matrixSize, int *matrixColSize, int target)
{
	int row = -1;
	int top = 0;
	int bottom = matrixSize - 1;
	while (top <= bottom)
	{
		int middle = (top + bottom) / 2;
		if (matrix[middle][0] <= target &&
			target <= matrix[middle][*matrixColSize - 1])
		{
			row = middle;
			break;
		}
		else if (matrix[middle][0] < target)
			top = middle + 1;
		else
			bottom = middle - 1;
	}
	if (row == -1)
		return false;

	top = 0;
	bottom = *matrixColSize - 1;
	while (top <= bottom)
	{
		int middle = (top + bottom) / 2;
		if (matrix[row][middle] == target)
		{
			printf("Found in matrix[%d][%d]\n", row, middle);
			return true;
		}
		else if (matrix[row][middle] < target)
			top = middle + 1;
		else
			bottom = middle - 1;
	}
	return false;
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

	// matric size is always set to 10x10
	// change row/col and numbers inside those values to dif test cases
	int rows = 3;
	int cols = 4;
	int target = 34;
	int matrixData[10][10] = {{1, 2, 5, 7, 5},
							  {10, 11, 16, 20, 5},
							  {23, 30, 34, 60, 0},
							  {4, 2, 2, 2, 1},
							  {0, 1, 2, 3, 3}};
	set_matrix(matrixData, matrix);
	printf("Original Matrix:\n");
	printMatrix(matrix, rows, cols);
	printf("Target is %d\n", target);

	bool result = searchMatrix(matrix, rows, &cols, target);
	if (!result)
		printf("Not found :(\n");

	for (int i = 0; i < MaxRow; i++)
		free(matrix[i]);
	free(matrix);
}
