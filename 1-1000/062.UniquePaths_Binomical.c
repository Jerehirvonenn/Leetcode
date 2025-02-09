#include <stdio.h>
#include <stdlib.h>

int uniquePaths(int m, int n)
{
    if (m < 1 || n < 1)
        return 0;
    if (n < m)
    {
        int tmp = n;
        n = m;
        m = tmp;
    }
    long long result = 1;
    int small = m - 1;
    int total = m + n - 2;
    for (int i = 1; i <= small; i++)
        result = result * (total - i + 1) / i;
    return (int)result;
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
