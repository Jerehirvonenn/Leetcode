#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isMatchingPair(char open, char close)
{
	return (open == '(' && close == ')') || (open == '{' && close == '}') ||
		   (open == '[' && close == ']');
}

bool isValid(char *s)
{
	int size = strlen(s);
	if (size % 2 != 0)
		return false;
	char *stack = (char *)malloc(sizeof(char) * size);
	int top = -1;
	for (int i = 0; i < size; i++)
	{
		if (s[i] == '(' || s[i] == '{' || s[i] == '[')
			stack[++top] = s[i];
		else
		{
			if (top == -1 || !isMatchingPair(stack[top], s[i]))
			{
				free(stack);
				return false;
			}
			top--;
		}
	}
	bool valid = (top == -1);
	free(stack);
	return valid;
}

int main(int ac, char **av)
{
	if (ac < 2)
	{
		printf("provide at least 1 argument\n");
		return 1;
	}
	bool result = isValid(av[1]);
	if (result)
		printf("valid\n");
	else
		printf("invalid\n");
}
