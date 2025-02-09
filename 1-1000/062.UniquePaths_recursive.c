#include <stdio.h>
#include <stdlib.h>

int travel(int maxRow, int maxCol, int row, int col)
{
    if (row == maxRow && col == maxCol)
        return 1;
    int result = 0;
    if (row + 1 <= maxRow)
        result += travel(maxRow, maxCol, row + 1, col);
    if (col + 1 <= maxCol)
        result += travel(maxRow, maxCol, row, col + 1);
    return result;
}

int uniquePaths(int m, int n)
{
    if (m < 1 || n < 1)
        return 0;
    int result = travel(m, n, 1, 1);
    return result;
}

int main(int ac ,char **av)
{
	if (ac != 3)
	{
		printf("Usage: %s <rows> <columns>\n", av[0]);
		return (1);
	}
	int	m = atoi(av[1]);
	int n = atoi(av[2]);
	int result = uniquePaths(m, n);
	printf("Unique Ways to reach bottom right in grid size %dx%d is %d", m, n, result);
}
