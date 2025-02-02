#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void backtrack(int *nums, int numsSize, bool *used, int *current, int level,
               int **result, int *returnSize, int *returnColumnSizes)
{
	//basecase
	if (level == numsSize)
	{
        result[*returnSize] = malloc(sizeof(int) * numsSize);
		for (int i = 0; i < numsSize; i++)
			result[*returnSize][i] = current[i];
        returnColumnSizes[*returnSize] = numsSize;
		(*returnSize)++;
		return;
	}
	//backtracking
	for (int i = 0; i < numsSize; i++)
	{
        if (used[i] || (i != 0 && nums[i] == nums[i - 1] && !used[i - 1]))
            continue;
		if (!used[i])
		{
			used[i] = true;
			current[level] = nums[i];
			//move to next level
			backtrack(nums, numsSize, used, current, level + 1, result, returnSize, returnColumnSizes);
			//revert pick and check next number
			used[i] = false;
		}
	}
}

int compare(const void* a, const void* b)
{
   return (*(int*)a - *(int*)b);
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
	int	maxPermutations = 1;	//number of permutations is numsSize!
	for (int i = 2; i < numsSize; i++)
		maxPermutations *= i;

    qsort(nums, numsSize, sizeof(int), compare);

	//malloc for return and column sizes
	int **result = malloc(sizeof(int*) * maxPermutations);
	*returnColumnSizes = malloc(sizeof(int) * maxPermutations);

	bool used[numsSize];
    int current[numsSize];
	for (int i = 0; i < numsSize; i++) //init used array as false
		used[i] = false;

	*returnSize = 0;
    backtrack(nums, numsSize, used, current, 0, result, returnSize, *returnColumnSizes);

    return result;
}

int main()
{
	int	 nums[] = {1, 1, 1, 5 ,5};
	int	 numsSize = sizeof(nums) / sizeof(nums[0]);
	int	 returnSize;
	int *returnColumnSizes;

	int **result = permuteUnique(nums, numsSize, &returnSize, &returnColumnSizes);

	printf("Permutations:\n");
	for (int i = 0; i < returnSize; i++)
	{
		for (int j = 0; j < returnColumnSizes[i]; j++)
		{
			printf("%d ", result[i][j]);
		}
		printf("\n");
		free(result[i]);
	}

	free(result);
	free(returnColumnSizes);
}
