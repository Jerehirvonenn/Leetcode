#include <stdio.h>
#include <stdlib.h>

int *plusOne(int *digits, int digitsSize, int *returnSize)
{
	int	 carry = 1;
	int *array = (int *)malloc(sizeof(int) * (digitsSize + 1));

	for (int i = digitsSize - 1; i >= 0; i--)
	{
		if (carry == 1 && digits[i] >= 9)
			digits[i] = 0;
		else if (carry)
		{
			digits[i]++;
			carry = 0;
		}
		array[i] = digits[i];
	}
	if (!carry)
	{
		*returnSize = digitsSize;
		return array;
	}
	else
	{
		*returnSize = digitsSize + 1;
		for (int i = digitsSize - 1; i >= 0; i--)
			array[i + 1] = array[i];
		array[0] = 1;
		return array;
	}
}

int main(int ac, char **av)
{
	if (ac < 2)
	{
		printf("Usage: ./a.out numbers(0-9)...\n");
		return 1;
	}
	int array[ac - 1];
	for (int i = 1; i < ac; i++)
		array[i - 1] = atoi(av[i]);
	int	 returnSize;
	int *result = plusOne(array, ac - 1, &returnSize);
	printf("Result: ");
	for (int i = 0; i < returnSize; i++)
	{
		printf("%d", result[i]);
	}
	printf("\n");
	free(result);
}
