#include <stdio.h>
#include <string.h>

int strStr(char *haystack, char *needle)
{
	int needleSize = strlen(needle);
	int haystackSize = strlen(haystack);
	if (needleSize > haystackSize)
		return -1;
	for (int i = 0; i <= haystackSize - needleSize; i++)
	{
		int j = 0;
		while (needle[j] && needle[j] == haystack[i + j])
			j++;
		if (!needle[j])
			return i;
	}
	return -1;
}

int main(int ac, char **av)
{
	if (ac < 3)
	{
		printf("Usage: ./a.out needle haystack\n");
		return -1;
	}
	int result = strStr(av[2], av[1]);
	if (result != -1)
	{
		printf("The needle '%s' was found in the haystack '", av[1]);
		for (int i = 0; av[2][i] != '\0'; i++)
		{
			if (i == result)
				printf("\033[0;32m"); // start green text
			putchar(av[2][i]);
			if (i == result + (int)strlen(av[1]) - 1)
				printf("\033[0m"); // end green text:w
		}
		printf("' at index %d\n", result);
	}
	else
	{
		printf("The needle '%s' was not found in the haystack '%s'\n", av[1],
			   av[2]);
	}
}
