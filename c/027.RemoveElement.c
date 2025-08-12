#include <stdio.h>
#include <stdlib.h>

int removeElement(int *nums, int numsSize, int val)
{
	int i = 0;
	for (int j = 0; j < numsSize; j++)
		if (nums[j] != val)
			nums[i++] = nums[j];
	return i;
}

int main(int ac, char **av)
{
	if (ac < 2)
		return (1);

	int array[ac - 1];
	for (int i = 1; i < ac; i++)
		array[i - 1] = atoi(av[i]);
	int size = removeElement(array, ac - 1, 3);
	for (int i = 0; i < size; i++)
		printf("%d ", array[i]);
	printf("\n");
}
