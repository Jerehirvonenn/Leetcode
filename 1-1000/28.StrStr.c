#include<string.h>
#include<stdio.h>

int	strStr(char* haystack, char* needle)
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

int	main(int ac, char **av)
{
	if (ac < 3)
	{
		printf("Usage: ./a.out needle haystack\n");
		return -1;
	}
	int result = strStr(av[2], av[1]);
	result != -1 ? printf("The needle '%s' was found in the haystack '%s' at index %d\n", av[1], av[2], result)
        : printf("The needle '%s' was not found in the haystack '%s'\n", av[1], av[2]);
}
