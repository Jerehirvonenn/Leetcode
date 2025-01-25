#include <stdio.h>
#include <stdlib.h>

int maxArea(int *height, int heightSize)
{
	int maxSize = 0;
	int left = 0;
	int right = heightSize - 1;
	while (left != right)
	{
		int small = height[left] <= height[right] ? left : right;
		int size = height[small] * (right - left);
		if (size > maxSize)
			maxSize = size;
		height[left] <= height[right] ? left++ : right--;
	}
	return maxSize;
}

int main(int ac, char **av)
{
	if (ac < 3)
		return 1;
	ac--;
	av++;
	int *array = malloc(sizeof(int) * ac);
	if (!array)
		return 2;
	for (int i = 0; i < ac; i++)
		array[i] = atoi(av[i]);
	int result = maxArea(array, ac);
	printf("Larges area from array ");
	for (int i = 0; i < ac; i++)
		printf("%d ", array[i]);
	printf("is %d\n", result);
}
