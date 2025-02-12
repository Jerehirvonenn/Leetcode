#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void sortColors(int *nums, int numsSize)
{
	int zero = 0;
	int two = numsSize - 1;
	int i = zero;
	while (i <= two)
	{
		if (nums[i] == 0)
		{
			swap(&(nums[i]), &(nums[zero]));
			i++;
			zero++;
		}
		else if (nums[i] == 2)
		{
			swap(&(nums[i]), &(nums[two]));
			two--;
		}
		else
			i++;
	}
}

void print_array(char *str, int *array, int size)
{
	printf("%s", str);
	for (int i = 0; i < size; i++)
		printf(" %d", array[i]);
	printf("\n");
}

int main(int ac, char **av)
{
	if (ac < 2 || ac > 101)
	{
		printf("Usage: %s <num1> <num2> ... <numN> || N < 100 0 <= num <= 2\n",
			   av[0]);
		return (1);
	}
	ac--;
	av++;
	int *array = malloc(sizeof(int) * ac);
	for (int i = 0; i < ac; i++)
	{
		array[i] = atoi(av[i]);
		if (array[i] > 2 || array[i] < 0)
		{
			printf(
				"Usage: %s <num1> <num2> ... <numN> || N < 100 0 <= num <= 2\n",
				av[0]);
			return (2);
		}
	}
	print_array("Original Array:", array, ac);
	sortColors(array, ac);
	print_array("Array after   :", array, ac);
}
