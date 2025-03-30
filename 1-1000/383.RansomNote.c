#include <stdio.h>
#include <stdbool.h>

bool canConstruct(char *ransomNote, char *magazine)
{
	int count[26] = {0};
	for (int i = 0; magazine[i]; i++)
		count[magazine[i] - 'a']++;
	for (int i = 0; ransomNote[i]; i++)
	{
		if (count[ransomNote[i] - 'a'] == 0)
			return false;
		count[ransomNote[i] - 'a']--;
	}
	return true;
}

int main(int ac, char **av)
{
	if (ac < 3)
	{
		printf("Usage: %s <ransomNote> <magazine>\n", av[0]);
		return 1;
	}

	if (canConstruct(av[1], av[2]))
		printf("String : %s can be constructed from string %s letter\n", av[1], av[2]);
	else
		printf("String : %s can't be constructed from string %s letter\n", av[1], av[2]);
}
