#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int *nums, int numsSize)
{
	int i = 0;

	for (int j = 1; j < numsSize; j++)
		if (nums[i] != nums[j])
			nums[++i] = nums[j];
	return (i + 1);
}

int compare(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int main(int ac, char **av)
{
	if (ac < 2)
		return (1);

	int array[ac - 1];
	for (int i = 1; i < ac; i++)
		array[i - 1] = atoi(av[i]);
	qsort(array, ac - 1, sizeof(int), compare);
	int size = removeDuplicates(array, ac - 1);
	for (int i = 0; i < size; i++)
		printf("%d ", array[i]);
	printf("\n");
}
