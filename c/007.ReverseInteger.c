#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int reverse(int x)
{
	int result = 0;

	while (x)
	{
		int digit = x % 10;
		x /= 10;
		if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7))
			return 0;
		if (result < INT_MIN / 10 || (result == INT_MIN / 10 && digit < -8))
			return 0;
		result = result * 10 + digit;
	}
	return result;
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("Usage: ./a.out <integer to flip>\n");
		return 1;
	}
	int num = atoi(av[1]);
	int result = reverse(num);
	if (result || num == 0)
		printf("The reverse of %d is %d\n", num, result);
	else
		printf("Integer overflows when reversed");
}
