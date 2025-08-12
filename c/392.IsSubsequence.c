#include <stdbool.h>
#include <stdio.h>

bool isSubsequence(char *s, char *t)
{
	if (!s || !*s)
		return true;
	if (!t || !*t)
		return false;
	int pos = 0;
	int i = 0;
	while (t[i])
	{
		if (t[i] == s[pos])
			pos++;
		if (s[pos] == '\0')
			return true;
		i++;
	}
	return false;
}

int main(int ac, char **av)
{
	if (ac < 3)
	{
		printf("Usage: %s <needle> <hay>\n", av[0]);
		return 1;
	}

	bool result = isSubsequence(av[1], av[2]);
	if (result)
		printf("Found!\n");
	else
		printf("Not found!\n");
}
