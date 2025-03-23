#include <stdio.h>
#include <stdlib.h>

int minSubArrayLen(int target, int* nums, int numsSize)
{
    int result = numsSize + 1;
    int sum = 0;
    int left = 0;

    for (int right = 0; right < numsSize; right++)
    {
        sum += nums[right];
        while (sum >= target)
        {
            if (right - left + 1 < result)
                result = right - left + 1;
            sum -= nums[left];
            left++;
        }
    }
    if (result == numsSize + 1)
        return 0;
    return result;
}

int main(int ac, char **av)
{
	if (ac < 2)
	{
		printf("Usage: %s <num1> <num2> ... <numN>\n", av[0]);
		return 1;
	}

	ac--;
	av++;
	int target = 7;
	int *array = malloc(sizeof(int) * ac);
	printf("ARRAY:");
	for (int i = 0; i < ac; i++)
	{
		array[i] = atoi(av[i]);
		printf(" %d", array[i]);
	}
	printf("\n");
	int numsSize = ac;
	int result = minSubArrayLen(target, array, numsSize);
	printf("Smallest subarray to hit target %d is %d", target, result);
}
