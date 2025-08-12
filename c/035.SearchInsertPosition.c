#include <stdio.h>
#include <stdlib.h>

int searchInsert(int *nums, int numsSize, int target)
{
	int low = 0;
	int high = numsSize - 1;
	while (low <= high)
	{
		int check = low + (high - low) / 2;
		if (nums[check] == target)
			return check;
		if (nums[check] < target)
			low = check + 1;
		else
			high = check - 1;
	}
	return low;
}

int compare(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int main(int ac, char **av)
{
	if (ac < 3)
	{
		printf("Usage: ./a.out target array nums...\n");
		return (1);
	}
	int target = atoi(av[1]);
	int array[ac - 2];
	for (int i = 0; i < ac - 2; i++)
		array[i] = atoi(av[i + 2]);
	qsort(array, ac - 2, sizeof(int), compare);
	int index = searchInsert(array, ac - 2, target);
	printf("Target %d would be found at index %d\n", target, index);
}
