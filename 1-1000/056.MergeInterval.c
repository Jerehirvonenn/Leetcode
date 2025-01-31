#include <stdio.h>
#include <stdlib.h>

int sortIntervals(const void *a, const void *b)
{
	int *intervalA = *(int **)a;
	int *intervalB = *(int **)b;
	return intervalA[0] - intervalB[0]; // Compare start times
}

int **merge(int **intervals, int intervalsSize, int *intervalsColSize,
			int *returnSize, int **returnColumnSizes)
{
	//silence flag for unused variable
	(void)intervalsColSize;
	// sort intervals based in start number
	qsort(intervals, intervalsSize, sizeof(int *), sortIntervals);

	// malloc for return
	*returnSize = intervalsSize;
	int **ret = malloc(sizeof(int *) * intervalsSize);
	*returnColumnSizes = malloc(*returnSize * sizeof(int));

	int index = -1;
	for (int i = 0; i < intervalsSize; i++)
	{
		if (i != 0 && intervals[i][0] <= ret[index][1])
			ret[index][1] = ret[index][1] > intervals[i][1] ? ret[index][1]
															: intervals[i][1];
		else
		{
			ret[++index] = malloc(sizeof(int) * 2);
			ret[index][0] = intervals[i][0];
			ret[index][1] = intervals[i][1];
			(*returnColumnSizes)[index] = 2;
		}
	}
	*returnSize = index + 1;
	return ret;
}

// Helper function to print the 2D array
void printIntervals(int **intervals, int size)
{
	printf("[");
	for (int i = 0; i < size; i++)
	{
		printf("[%d, %d]", intervals[i][0], intervals[i][1]);
		if (i < size - 1)
			printf(", ");
	}
	printf("]\n");
}

int main(void)
{
	// Input: [[1,3],[2,6],[8,10],[15,18]]
	int intervalsSize = 4;
	int intervalsColSize = 2;

	// Allocate the intervals
	int **intervals = malloc(intervalsSize * sizeof(int *));
	intervals[0] = (int[]){1, 5};
	intervals[1] = (int[]){2, 6};
	intervals[2] = (int[]){8, 10};
	intervals[3] = (int[]){15, 18};

	// Variables to store results
	int	 returnSize;
	int *returnColumnSizes;

	// Original intervals
	printf("Original intervals: ");
	printIntervals(intervals, intervalsSize);

	// Merge
	int **mergedIntervals = merge(intervals, intervalsSize, &intervalsColSize,
								  &returnSize, &returnColumnSizes);

	// Merged intervals
	printf("Merged intervals: ");
	printIntervals(mergedIntervals, returnSize);

	// Free
	for (int i = 0; i < returnSize; i++)
	{
		free(mergedIntervals[i]);
	}
	free(mergedIntervals);
	free(returnColumnSizes);
	free(intervals);
}
