#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int threeSumClosest(int *nums, int numsSize, int target)
{
	qsort(nums, numsSize, sizeof(int), compare);
	int result = INT_MAX;
	;

	for (int i = 0; i < numsSize - 2; i++)
	{
		if (i != 0 && nums[i] == nums[i - 1])
			continue;
		int left = i + 1;
		int right = numsSize - 1;
		while (left < right)
		{
			int sum = nums[i] + nums[left] + nums[right];
			if (abs(sum - target) < abs(result - target))
				result = sum;
			if (sum < target)
				left++;
			else if (sum > target)
				right--;
			else
				return sum;
		}
	}
	return result;
}

int main(int ac, char **av)
{
	if (ac < 2)
		return 1;
	ac--;
	av++;
	int *nums = malloc(sizeof(int) * ac);
	for (int i = 0; i < ac; i++)
		nums[i] = atoi(av[i]);
	int result = threeSumClosest(nums, ac, 10);
	printf("Closest sum to target 10 is %d\n", result);
}
