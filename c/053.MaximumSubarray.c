#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int maxSubArray(int* nums, int numsSize)
{
    int maxSum = INT_MIN;
    int sum = 0;

    for (int i = 0; i < numsSize; i++)
    {
        sum += nums[i];
        if (sum > maxSum) {maxSum = sum;}
        if (sum < 0) {sum = 0;}
    }
    return maxSum; 
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
	int *array = malloc(sizeof(int) * ac);
	printf("ARRAY:");
	for (int i = 0; i < ac; i++)
	{
		array[i] = atoi(av[i]);
		printf(" %d", array[i]);
	}
	printf("\n");
	int numsSize = ac;
	int result = maxSubArray(array, numsSize);
	printf("max subarray sum is %d\n", result);
}
