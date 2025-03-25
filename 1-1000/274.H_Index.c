#include <stdlib.h>
#include <stdio.h>

int compare(const void *a, const void *b)
{
    return (*(int*)b - *(int*)a);
}

int hIndex(int * citations, int citationsSize)
{
    qsort(citations, citationsSize, sizeof(int), compare);

    int biggest = 0;
    for (int i = 0; i < citationsSize; i++)
    {
        if (citations[i] >= i + 1) {
            biggest = i + 1;
        }
        else {
            return biggest;
        }
    }
    return biggest;
}

int main(void)
{
	int array[] = {3, 0, 6, 1, 5};
	int size = 5;
	int result = hIndex(array, size);
	printf("H-Index is %d\n", result);
}
