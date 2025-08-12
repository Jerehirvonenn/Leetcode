#include <stdlib.h>
#include <stdio.h>

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize)
{
    int left= 0;
    int right = numbersSize - 1;
    int *result = malloc(sizeof(int) * 2);
    *returnSize = 2;

    while (left <= right)
    {
        int sum = numbers[left] + numbers[right];
        if (sum == target)
        {
            result[0] = left + 1;
            result[1] = right + 1;
            return result;
        }
        sum > target ? right-- : left++;
    }
    *returnSize = 0;
    return NULL;  
}

int main(void)
{
	int	numbers[] = {2, 7, 11, 15, 21, 27, 33};
	int	numbersSize = sizeof(numbers) / sizeof(numbers[0]);
	int target = 36;
	int returnSize = 0;

	int *result = twoSum(numbers, numbersSize, target, &returnSize);
	printf("Target %d found in indexes %d and %d\n", target, result[0] - 1, result[1] - 1);
	free(result);
}
