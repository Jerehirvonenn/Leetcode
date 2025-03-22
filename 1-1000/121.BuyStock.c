#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

int maxProfit(int* prices, int pricesSize)
{
    int smallest = INT_MAX;
    int maxProfit = 0;
    for (int i = 0; i < pricesSize; i++)
    {
        if (prices[i] < smallest) { smallest = prices[i]; }
        else if (prices[i] - smallest > maxProfit) { maxProfit = prices[i] - smallest;}
    }
    return maxProfit;
}

int	main(int ac, char **av)
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
	int	result = maxProfit(array, ac);
	printf("Max profit to be made is %d\n", result);
	free(array);
}
