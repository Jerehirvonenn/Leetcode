#include <string.h>

int romanToInt(char *s)
{
	int values[128] = {0};
	values['I'] = 1;
	values['V'] = 5;
	values['X'] = 10;
	values['L'] = 50;
	values['C'] = 100;
	values['D'] = 500;
	values['M'] = 1000;

	int result = 0;
	int prev = 0;

	for (int i = strlen(s) - 1; i >= 0; i--)
	{
		int current = values[(unsigned char)s[i]];
		if (current < prev)
			result -= current;
		else
			result += current;
		prev = current;
	}
	return result;
}

#include <stdio.h>

int main(int ac, char **av)
{
	if (ac < 2)
		return 1;
	printf("Value of %s is %d", av[1], romanToInt(av[1]));
}
