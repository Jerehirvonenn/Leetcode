#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool isIsomorphic(char* s, char* t)
{
    int letters[128] = {0};
	int usedLetter[128] = {0};

    for (int i = 0; s[i]; i++)
    {
		if (letters[s[i]] == 0 && usedLetter[t[i]] == 0)
		{
			letters[s[i]] = t[i];
			usedLetter[t[i]] = s[i];
		}
		else if (letters[s[i]] != t[i] || usedLetter[t[i]] != s[i])
			return false;
    }
    return true;
}

int main(int ac, char **av)
{
	if (ac < 3)
	{
		printf("Usage: %s <s1> <s2>\n", av[0]);
		return 1;
	}
	if (isIsomorphic(av[1], av[2]))
		printf("True\n");
	else
		printf("false\n");
}
