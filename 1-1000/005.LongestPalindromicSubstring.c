#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void expandFromChar(int left, int right, int *len, int *maxLen, int *start,
					char *s)
{
	while (left >= 0 && right < *len && s[left] == s[right])
	{
		int length = right - left + 1;
		if (length > *maxLen)
		{
			*start = left;
			*maxLen = length;
		}
		left--;
		right++;
	}
}

char *longestPalindrome(char *s)
{
	if (!s || !*s)
		return strdup("");
	int len = strlen(s);
	int start = 0;
	int maxLen = 0;

	for (int i = 0; i < len; i++)
	{
		expandFromChar(i, i, &len, &maxLen, &start, s);
		expandFromChar(i, i + 1, &len, &maxLen, &start, s);
	}

	char *result = (char *)malloc(sizeof(char) * (maxLen + 1));
	strncpy(result, s + start, maxLen);
	result[maxLen] = 0;
	return result;
}

int main(int ac, char **av)
{
	if (ac < 2)
		return 1;
	char *str = longestPalindrome(av[1]);
	printf("Longest substring palindrome in %s is %s\n", av[1], str);
	free(str);
}
