#include <stdlib.h>
#include <stdio.h>

int majorityElement(int* nums, int numsSize)
{
    int majority = 0;
    int count = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (!count)
            majority = nums[i];
        if (nums[i] == majority)
            count++;
        else
            count--;
    }
    return majority;
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
	printf("Majority in array:");
	for (int i = 0; i < ac; i++)
	{
		array[i] = atoi(av[i]);
		printf(" %d", array[i]);
	}
	printf(" is %d\n", majorityElement(array, ac));
}
