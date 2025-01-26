#include <stdio.h>
#include <stdlib.h>

char *intToRoman(int num)
{
	char *symbols[] = {"M",	 "CM", "D",	 "CD", "C",	 "XC", "L",
					   "XL", "X",  "IX", "V",  "IV", "I"};
	int	  values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
	char *result = calloc(20, sizeof(char));
	int	  index = 0;
	for (int i = 0; i < 13 && num; i++)
	{
		while (num >= values[i])
		{
			for (int j = 0; symbols[i][j]; j++)
				result[index++] = symbols[i][j];
			num -= values[i];
		}
	}
	return result;
}

int main(int ac, char **av)
{
	if (ac < 2)
		return 1;
	int	  num = atoi(av[1]);
	char *result = intToRoman(num);
	printf("%d in roman is %s\n", num, result);
}
