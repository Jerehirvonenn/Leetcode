#include <stdio.h>
#include <stdlib.h>

void backtrack(int *nums, int numsSize, int start, int *subset, int subsetSize, int **array, int *returnSize, int *returnColumnSizes)
{
	//copy current subset to the return array
	array[*returnSize] = malloc(sizeof(int) * subsetSize);
	for (int i = 0; i < subsetSize; i++)
		array[*returnSize][i] = subset[i];
	returnColumnSizes[*returnSize] = subsetSize;
	(*returnSize)++;

	//backtrack all the candidates
	for (int i = start; i < numsSize; i++)
	{
        if (i > start && nums[i] == nums[i - 1])
            continue;
		subset[subsetSize] = nums[i];
		backtrack(nums, numsSize, i + 1, subset, subsetSize + 1, array, returnSize, returnColumnSizes);
	}
}

int cmpfunc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
	int maxSubsets = 1 << numsSize;
	int **array = malloc(sizeof(int*) * maxSubsets);		//array to store the subsets
	int *subset = malloc(sizeof(int) * numsSize);			//tmp array to hold subset
	*returnColumnSizes = malloc(sizeof(int) * maxSubsets);	//holding size of each return arr
    qsort(nums, numsSize, sizeof(int), cmpfunc);
	*returnSize = 0;
	backtrack(nums, numsSize, 0, subset, 0, array, returnSize, *returnColumnSizes);

	free(subset);
	return array;
}

void printSubsets(int **result, int returnSize, int *returnColumnSizes)
{
	for (int i = 0; i < returnSize; i++)
	{
		printf("[");
		for (int j = 0; j < returnColumnSizes[i]; j++)
		{
			printf("%d", result[i][j]);
			if (j < returnColumnSizes[i] - 1)
				printf(", ");
		}
		printf("]\n");
	}
}

int main()
{
	int	 nums[] = {1, 2, 2}; // Input array
	int	 numsSize = sizeof(nums) / sizeof(nums[0]);
	int	 returnSize;
	int *returnColumnSizes;

	int **result = subsetsWithDup(nums, numsSize, &returnSize, &returnColumnSizes);

	printf("Subsets:\n");
	printSubsets(result, returnSize, returnColumnSizes);

	// Free allocated memory
	for (int i = 0; i < returnSize; i++)
	{
		free(result[i]);
	}
	free(result);
	free(returnColumnSizes);

	return 0;
}
