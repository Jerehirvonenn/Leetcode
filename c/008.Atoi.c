#include <limits.h>
#include <stdio.h>

int myAtoi(char *s)
{
	long result = 0;
	int	 sign = 1;
	int	 i = 0;
	while (s[i] == ' ')
		i++;
	if (s[i] == '+' || s[i] == '-')
		if (s[i++] == '-')
			sign = -1;
	while (s[i] >= '0' && s[i] <= '9')
	{
		result = result * 10 + (s[i] - '0');
		if (sign == 1 && result > INT_MAX)
			return INT_MAX;
		if (sign == -1 && -result < INT_MIN)
			return INT_MIN;
		i++;
	}
	return result * sign;
}

int main(int ac, char **av)
{
	if (ac != 2)
		return 1;
	printf("Number is %d\n", myAtoi(av[1]));
}
