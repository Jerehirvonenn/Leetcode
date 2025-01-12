#include <ctype.h>
#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char *s)
{
	int end = strlen(s) - 1;
	while (end >= 0 && isspace(s[end]))
		end--;
	int i = 0;
	while (end >= 0 && isalpha(s[end]))
	{
		end--;
		i++;
	}
	return i;
}

int main(int ac, char **av)
{
	if (ac < 2)
		return 1;
	printf("Last word length is %d\n", lengthOfLastWord(av[1]));
}
