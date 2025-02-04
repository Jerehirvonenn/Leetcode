#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_combinations(char *digits)
{
	int result = 1;
	int digit[] = {0, 0, 3, 3, 3, 3, 3, 4, 3, 4};
	for (int i = 0; digits[i]; i++)
	{
		int index = digits[i] - '0';
		result *= digit[index];
	}
	return result;
}

void backtrack(char *digits, char **result, char *current, int level, int len,
			   int *size, char intToChar[10][5])
{
	// basecase
	if (level == len)
	{
		result[*size] = strdup(current);
		(*size)++;
		return;
	}
	// backtrack
	int letters = (digits[level] == '7' || digits[level] == '9') ? 4 : 3;
	for (int i = 0; i < letters; i++)
	{
		int index = digits[level] - '0';
		current[level] = intToChar[index][i];
		backtrack(digits, result, current, level + 1, len, size, intToChar);
	}
}

char **letterCombinations(char *digits, int *returnSize)
{
	if (!digits || !*digits)
	{
		*returnSize = 0;
		return NULL;
	}

	char intToChar[10][5] = {
		{' ', '\0', '\0', '\0', '\0'}, // 0 placeholder
		{' ', '\0', '\0', '\0', '\0'}, // 1 placeholder
		{'a', 'b', 'c', '\0', '\0'},   // 2
		{'d', 'e', 'f', '\0', '\0'},   // 3
		{'g', 'h', 'i', '\0', '\0'},   // 4
		{'j', 'k', 'l', '\0', '\0'},   // 5
		{'m', 'n', 'o', '\0', '\0'},   // 6
		{'p', 'q', 'r', 's', '\0'},	   // 7 (4 letters)
		{'t', 'u', 'v', '\0', '\0'},   // 8
		{'w', 'x', 'y', 'z', '\0'}	   // 9 (4 letters)
	};

	int combinations = get_combinations(digits);

	char **result = malloc(sizeof(char *) * (combinations + 1));
	result[combinations] = NULL;
	int	  len = strlen(digits);
	char *current = malloc(sizeof(char) * (len + 1));
	current[len] = 0;

	*returnSize = 0;
	backtrack(digits, result, current, 0, len, returnSize, intToChar);

	free(current);
	return result;
}

bool check_string(char *s)
{
	if (!s)
		return true;
	int i = -1;
	while (s[++i])
		if (s[i] < '2' || s[i] > '9')
			return false;
	return true;
}

int main(int ac, char **av)
{
	(void)ac;
	if (!check_string(av[1]))
	{
		printf("Include numbers between 2-9\n");
		return 1;
	}
	int	   returnSize = 0;
	char **result = letterCombinations(av[1], &returnSize);
	if (!result)
	{
		printf("No combinations for empty/NULL string\n");
		return 0;
	}
	printf("Combinations\n");
	for (int i = 0; result[i]; i++)
	{
		printf("%s\n", result[i]);
		free(result[i]);
	}
	free(result);
}
