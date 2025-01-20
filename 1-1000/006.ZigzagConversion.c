#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *convert(char *s, int numRows)
{
	int len = strlen(s);
	if (numRows <= 1 || numRows >= len)
		return strdup(s);

	char **strs = (char **)calloc(numRows, sizeof(char *));
	for (int i = 0; i < numRows; i++)
		strs[i] = (char *)calloc((len + 1), sizeof(char));

	int i = 0;
	int currentRow = 0;
	int direction = -1; // 1 is down and -1 is up
	while (s[i])
	{
		int j = 0;
		while (strs[currentRow][j])
			j++;
		strs[currentRow][j] = s[i];
		if (currentRow == 0 || currentRow == numRows - 1)
			direction = direction * -1;
		currentRow += direction;
		i++;
	}
	char *result = (char *)calloc((len + 1), sizeof(char));
	int	  k = 0;
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; strs[i][j]; j++)
			result[k++] = strs[i][j];
	}
	free(strs);
	return result;
}

int main(int ac, char **av)
{
	if (ac != 3)
	{
		printf("Usage: <string to convert> <rows>\n");
		return 1;
	}
	char *str = convert(av[1], atoi(av[2]));
	printf("ZigZag of %s is %s\n", av[1], str);
	free(str);
}
