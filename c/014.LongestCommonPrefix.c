#include <string.h>

char *longestCommonPrefix(char **strs, int strsSize)
{
	char *prefix = strdup(strs[0]);
	for (int i = 1; i <= strsSize - 1; i++)
	{
		int j = 0;
		while (prefix[j] && strs[i][j] && prefix[j] == strs[i][j])
			j++;
		prefix[j] = '\0';
		if (j == 0)
			return (prefix);
	}
	return (prefix);
}

#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	if (ac < 2)
		return (1);
	char *longest = longestCommonPrefix(av + 1, ac - 1);
	if (strlen(longest) > 0)
		printf("Longest common prefix is %s\n", longest);
	else
		printf("No Common prefix\n");
	free(longest);
}
