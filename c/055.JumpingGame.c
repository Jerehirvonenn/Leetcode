#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool canJump(int* nums, int numsSize)
{
    int maxReach = 0;
    int i = 0;
    while (i < numsSize && i <= maxReach)
    {
        if (maxReach >= numsSize - 1)
            return true;
        maxReach = nums[i] + i > maxReach ? nums[i] + i : maxReach;
        i++;
    }
    return false;
}

int main(int ac, char **av)
{
	if (ac < 2)
	{
		printf("Usage: ./a.out <num1> <num2> ... <numN>\n");
		return (1);
	}
	ac--;
	av++;
	int *array = malloc(sizeof(int) * ac);
	if (!array)
		return (1);
	printf("Array:");
	for (int i = 0; i < ac; i++)
	{
		array[i] = atoi(av[i]);
		printf(" %d", array[i]);
	}
	printf("\n");
	bool result = canJump(array, ac);
	if (result)
		printf("It's possible to get to end\n");
	else
		printf("It's not possible to get to end\n");
	free(array);
}
