#include <stdio.h>
#include <stdlib.h>

int maxProfit(int *prices, int pricesSize)
{
	int profit = 0;
	for (int i = 0; i < pricesSize - 1; i++)
		if (prices[i + 1] > prices[i])
			profit += prices[i + 1] - prices[i];
	return profit;
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
