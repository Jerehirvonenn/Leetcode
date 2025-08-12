#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool	isPalindrome(char* s)
{
    int	len = strlen(s);
    int	end = len - 1;
    int	start = 0;

    while (start < end)
    {
        while (end > start && !isalnum(s[start])) {start++;}
        while (end > start && !isalnum(s[end])) {end--;}
        if (tolower(s[start]) != tolower(s[end])) {return false;}
        start++;
        end--;
    }
    return true;
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("Usage: ./a.out <string>\n");
		return (1);
	}
	bool result = isPalindrome(av[1]);
	if (result)
		printf("%s is phrase palindrome\n", av[1]);
	else
		printf("%s is not phrase palindrome\n", av[1]);
}
