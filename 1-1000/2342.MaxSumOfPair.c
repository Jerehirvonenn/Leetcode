#include <stdlib.h>
#include <stdio.h>

int digitSum(int num)
{
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int maximumSum(int* nums, int numsSize) {
    if (numsSize == 1)
        return -1;
    int sums[100][2] = {0};
    int biggest = 0;
    for (int i = 0; i < numsSize; i++)
    {
        int sum = digitSum(nums[i]);
        if (sums[sum][0] < nums[i]){
                sums[sum][1] = sums[sum][0];
                sums[sum][0] = nums[i];
        }
        else if (sums[sum][1] < nums[i]) {
            sums[sum][1] = nums[i];
        }
        else {continue;}
        int total = sums[sum][0] + sums[sum][1];
        if (total > biggest && total != sums[sum][0]) {
            biggest = total;
        }
    }
    if (biggest == 0)
        return -1;
    return biggest;
}

int main(int ac, char **av)
{
	if (ac < 2)
	{
		printf("Usage: %s <num1> <num2> ... <numN>\n", av[0]);
		return 1;
	}

	ac--;
	av++;
	int *array = malloc(sizeof(int) * ac);
	printf("ARRAY:");
	for (int i = 0; i < ac; i++)
	{
		array[i] = atoi(av[i]);
		printf(" %d", array[i]);
	}
	printf("\n");
	int numsSize = ac;
	int result = maximumSum(array, numsSize);
	printf("Max Sum of a Pair With Equal Sum of Digits is %d\n", result);
}
