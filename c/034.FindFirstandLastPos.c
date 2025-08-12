#include <stdio.h>
#include <stdlib.h>

int *searchRange(int *nums, int numsSize, int target, int *returnSize)
{
	int *ret = malloc(sizeof(int) * 2);
	ret[0] = -1;
	ret[1] = -1;
	*returnSize = 2;

	int left = 0;
	int right = numsSize - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (nums[mid] == target)
		{
			while (mid >= 0 && nums[mid] == target)
				mid--;
			if (mid < 0 || nums[mid] != target)
				mid++;
			ret[0] = mid;
			while (mid < numsSize - 1 && nums[mid] == target)
				mid++;
			if (mid == numsSize || nums[mid] != target)
				mid--;
			ret[1] = mid;
			break;
		}
		else if (nums[mid] < target)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return ret;
}

int main(int ac, char **av)
{
	if (ac < 3)
		return 1;
	ac--;
	av++;
	int	 target = atoi(av[0]);
	int *array = malloc(sizeof(int) * (ac - 1));
	for (int i = 1; i < ac; i++)
		array[i - 1] = atoi(av[i]);
	int	 size = 0;
	int *result = searchRange(array, ac - 1, target, &size);
	printf("Target: %d was first and last occurrences in array ", target);
	for (int i = 0; i < ac - 1; i++)
		printf("%d ", array[i]);
	printf("were in indexes %d and %d\n", result[0], result[1]);
}
