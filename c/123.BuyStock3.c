#include <stdio.h>
#include <stdlib.h>

int maxProfit(int* prices, int pricesSize)
{
	int	array_L[pricesSize];
	int	array_R[pricesSize];
	//calculate profit left of i
	array_L[0] = 0;
	int	smallest = prices[0];
	for (int i = 1; i < pricesSize; i++)
	{
		if (prices[i] < smallest)
			smallest = prices[i];
		if (prices[i] - smallest > array_L[i - 1])
			array_L[i] = prices[i] - smallest;
		else
			array_L[i] = array_L[i- 1];
	}
	//calculate profit right of i
	array_R[pricesSize - 1] = 0;
	int	biggest = prices[pricesSize - 1];
	for (int i = pricesSize - 2; i >= 0; i--)
	{
		if (prices[i] > biggest)
			biggest = prices[i];
		if (biggest - prices[i] > array_R[i + 1])
			array_R[i] = biggest - prices[i];
		else
			array_R[i] = array_R[i + 1];
	}
	//find best combination l[i] + R[i]
	int	maxProfit = 0;
	for (int i = 0; i < pricesSize; i++)
	{
		int	profit = array_L[i] + array_R[i];
		if (profit > maxProfit)
			maxProfit = profit;
	}
	return maxProfit;
}

int main(int ac, char **av)
{
	if (ac < 2)
	{
		printf("Usage: ./a.out <num1> <num2> ... <numN>\n");
		return (1);
	}
	ac--;
	av++;
	int *array = malloc(sizeof(int) * ac);
	for (int i = 0; i < ac; i++)
		array[i] = atoi(av[i]);
	int result = maxProfit(array, ac);
	printf("Max profit to be made is %d\n", result);
	free(array);
}
