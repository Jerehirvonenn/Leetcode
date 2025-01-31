#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void backtrack(int *nums, int numsSize, bool *used, int *current, int level,
               int **result, int *returnSize, int *returnColumnSizes)
{
	//basecase
	if (level == numsSize)
	{
		for (int i = 0; i < numsSize; i++)
			result[*returnSize][i] = current[i];
		(*returnSize)++;
		return;
	}
	//backtracking
	for (int i = 0; i < numsSize; i++)
	{
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

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
	int	maxPermutations = 1;	//number of permutations is numsSize!
	for (int i = 2; i <= numsSize; i++)
		maxPermutations = maxPermutations * i;

	//malloc for return and column sizes
	int **result = malloc(sizeof(int*) * maxPermutations);
	*returnColumnSizes = malloc(sizeof(int) * maxPermutations);
	for (int i = 0; i < maxPermutations; i++)
	{
		(*returnColumnSizes)[i] = numsSize;
		result[i] = malloc(sizeof(int) * numsSize);
	}

	bool used[numsSize];
    int current[numsSize];
	for (int i = 0; i < numsSize; i++) //init used array as false
		used[i] = false;
	
	*returnSize = 0;
    backtrack(nums, numsSize, used, current, 0, result, returnSize, *returnColumnSizes);

    return result;
}

int main() {
    int nums[] = {1, 2, 3};
    int returnSize;
    int *returnColumnSizes;

    int **result = permute(nums, 3, &returnSize, &returnColumnSizes);

    printf("Permutations:\n");
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
        free(result[i]);
    }

    free(result);
    free(returnColumnSizes);
}
