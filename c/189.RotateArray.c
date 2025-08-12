#include <stdio.h>
#include <stdlib.h>


void rotate(int *nums, int numsSize, int k)
{
	int *result = malloc(sizeof(int) * numsSize);
	for (int i = 0; i < numsSize; i++)
		result[(i + k) % numsSize] = nums[i];

	for (int i = 0; i < numsSize; i++)
		nums[i] = result[i];
	free(result);
}


void reverse(int *array, int start, int end)
{
	int tmp = array[end];
	while (start < end)
	{
		int tmp = array[end];
		array[end] = array[start];
		array[start] = tmp;
		end--;
		start++;
	}
}

void ft_rotate(int *nums, int numsSize, int k)
{
	k = k % numsSize;

	reverse(nums, 0, numsSize - 1);
	reverse(nums, 0, k - 1);
	reverse(nums, k, numsSize - 1);
}

void printArray(int *nums, int size, int num)
{
	printf("Array%d:", num);
	for (int i = 0; i < size; i++)
		printf(" %d", nums[i]);
	printf("\n");
}

int main(int ac, char **av)
{
	if (ac < 3)
	{
		printf("Usage: %s <RotaNum> <num1> <num2> ... <numN>\n", av[0]);
		return 1;
	}

	ac--;
	av++;
	int rota = atoi(av[0]);
	ac--;
	av++;
	int *array1 = malloc(sizeof(int) * ac);
	int *array2 = malloc(sizeof(int) * ac);
	printf("ARRAY:");
	for (int i = 0; i < ac; i++)
	{
		array1[i] = atoi(av[i]);
		array2[i] = atoi(av[i]);
		printf(" %d", array1[i]);
	}
	printf("\n");
	int numsSize = ac;
	rotate(array1, numsSize, rota);
	ft_rotate(array2, numsSize, rota);
	printArray(array1, numsSize, 1);
	printArray(array2, numsSize, 1);
}
