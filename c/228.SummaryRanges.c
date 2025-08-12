#include <stdlib.h>
#include <stdio.h>

int integerSize(int num)
{
    int size = num < 0 ? 2 : 1;
    while (num)
    {
        num /= 10;
        size++;
    }
    return size;
}

char** summaryRanges(int* nums, int numsSize, int* returnSize)
{
    if (numsSize == 0)
    {
        *returnSize = 0;
        return NULL;
    }
    char **result = malloc(sizeof(char*) * numsSize);
    *returnSize = 0;

    int start = 0;
    for (int i = 1; i <= numsSize; i++)
    {
        if (i == numsSize || nums[i] != nums[i - 1] + 1)
        {
            if (start == i - 1)
            {
                int size = integerSize(nums[start]);
                result[*returnSize] = malloc(sizeof(char) * (size + 1));
                sprintf(result[*returnSize], "%d", nums[start]);
            }
            else
            {
                int size = integerSize(nums[start]) + integerSize(nums[i - 1]);
                result[*returnSize] = malloc(sizeof(char) * (size + 3));
                sprintf(result[*returnSize], "%d->%d", nums[start], nums[i - 1]);
            }
            (*returnSize)++;
            start = i;
        }
    }
    return result;
}

int main(void)
{
	int array[] = {0, 1, 2, 4, 5, 7};
	int numsSize = sizeof(array) / sizeof(array[0]);
	int returnSize = 0;

	char **result = summaryRanges(array, numsSize, &returnSize);
	printf("Original Array:  ");
	for (int i = 0; i < numsSize; i++)
		printf(" %d", array[i]);
	printf("\n");
	printf("Array in ranges: [");
	for (int i = 0; i < returnSize; i++)
	{
		printf("\"%s\"", result[i]);
		if (i != returnSize - 1)
			printf(",");
		free(result[i]);
	}
	printf("]\n");
	free(result);
}
