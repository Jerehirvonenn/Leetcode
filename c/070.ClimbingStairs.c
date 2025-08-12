#include <stdio.h>
#include <stdlib.h>

int climbStairs(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	int first = 1;
	int second = 2;
	for (int i = 3; i <= n; i++)
	{
		int current = first + second;
		first = second;
		second = current;
	}
	return second;
}

int main(int ac, char **av)
{
	if (ac < 2)
	{
		printf("Usage: ./a.out <number>\n");
		return 1;
	}
	int num = atoi(av[1]);
	if (num < 0)
	{
		printf("provide a non negative number\n");
		return 1;
	}
	int result = climbStairs(num);
	printf("There are %d distinct ways to climb %d steps.\n", result, num);
}
