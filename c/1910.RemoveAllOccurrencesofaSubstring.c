#include <stdio.h>
#include <string.h>

char* removeOccurrences(char* s, char* part)
{
	int partLen = strlen(part);

	int	left = 0;
	for (int right = 0; s[right]; right++)
	{
		s[left++] = s[right];
		if (left >= partLen && !strncmp(&s[left - partLen], part, partLen))
			left -= partLen;
	}
	s[left] = 0;
	return s;
}

int main(int ac, char **av)
{
	if (ac < 3)
	{
		printf("Usage: %s <String> <ToRemove>\n", av[0]);
		return 1;
	}

	printf("Before: %s ToRemove: %s\n",av[1], av[2]);
	char *result = removeOccurrences(av[1], av[2]);
	printf("After: %s\n", result);
}
