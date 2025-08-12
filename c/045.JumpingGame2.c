#include <stdio.h>
#include <stdlib.h>

int jump(int* nums, int numsSize)
{
    int jumps = 0;
    int longest = -1;
    int end = 0;
    for (int i = 0; i < numsSize - 1; i++)
    {
        if (nums[i] + i > longest)
            longest = nums[i] + i;
        if (i == end)
        {
            jumps++;
            end = longest;
        }
        if (end >= numsSize - 1)
            break;
    }
    return jumps;    
}

int main(int ac, char **av)
{
	if (ac < 2 || ac > 101)
	{
		printf("Usage: %s <nums1> <nums2> ... <numsN> N <= 100\n", av[0]);
		return 1;
	}

	ac--;
	av++;
	int array[100];
	for (int i = 0; i < ac; i++)
		array[i] = atoi(av[i]);
	int numsSize = ac;

	int result = jump(array, numsSize);
	printf("Min jumps to get to the end is %d\n", result);
	printf("Array:");
	for (int i = 0; i < ac; i++)
		printf("%d ", array[i]);
	printf("\n");
}
