#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void backtrack(int *nums, int numsSize, bool *used, int *current, int level, int **result, int *returnSize, int *returnColumnSizes)
{
	if (level == numsSize)
	{
		result[*returnSize] = malloc(sizeof(int) * numsSize);
		for (int i = 0; i < numsSize; i++)
			result[*returnSize][i] = current[i];
		returnColumnSizes[*returnSize] = numsSize;
		(*returnSize)++;
		return ;
	}
	for (int i = 0; i < numsSize; i++)
	{
		if (!used[i])
		{
			used[i] = true;
			current[level] = nums[i];
			backtrack(nums, numsSize, used, current, level + 1, result, returnSize, returnColumnSizes);
			used[i] = false;
		}
	}
}

int **permute(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
	int	maxPermutations = 1;
	for (int i = 2; i <= numsSize; i++)
		maxPermutations *= i;

	int	**result = malloc(sizeof(int*) * maxPermutations);
	*returnColumnSizes = malloc(sizeof(int) * maxPermutations);
	int	*current = malloc(sizeof(int) * numsSize);
	bool *used = calloc(numsSize, sizeof(bool));

	*returnSize = 0;
	backtrack(nums, numsSize, used, current, 0, result, returnSize, *returnColumnSizes);

	free(used);
	free(current);
	return result;
}

int main()
{
	int	 nums[] = {1, 2, 3};
	int	 returnSize;
	int *returnColumnSizes;
	int numsSize = sizeof(nums) / sizeof(int);

	int **result = permute(nums, numsSize, &returnSize, &returnColumnSizes);
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
