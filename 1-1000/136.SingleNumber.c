#include <stdio.h>

/*
 * This uses the XOR operator to find the single number
 * XOR cancels out duplicate numbers because a ⊕ a = 0
 * when we XOR all numbers in the array, duplicates cancel out
 * leaving only the single number that appears once
 *
 * example walkthrough with nums = 4, 1, 2, 1, 2
 * initial result = 0
 * result ⊕ 4 = 4  (0 ⊕ 4 = 4)
 * result ⊕ 1 = 5  (4 ⊕ 1 = 5)
 * result ⊕ 2 = 7  (5 ⊕ 2 = 7)
 * result ⊕ 1 = 6  (7 ⊕ 1 = 6, cancels out the first 1)
 * result ⊕ 2 = 4  (6 ⊕ 2 = 4, cancels out the first 2)
 * Final result = 4 (the single number)
 */

int singleNumber(int *nums, int numsSize)
{
	int result = 0;
	for (int i = 0; i < numsSize; i++)
		result ^= nums[i];
	return result;
}

int main(void)
{
	int nums[] = {4, 1, 2, -1, 2};
	int size = sizeof(nums) / sizeof(nums[0]);
	printf("Single number: %d\n", singleNumber(nums, size));
}
