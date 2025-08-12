#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool travel(int *arr, int arrSize, int index, bool *visited)
{
    if (index < 0 || index >= arrSize)
        return false;
    if (visited[index] == true)
        return false;
	else
		visited[index] = true;
    if (arr[index] == 0)
        return true;
    return (travel(arr, arrSize, index + arr[index], visited) ||
    travel(arr, arrSize, index - arr[index], visited));
}

bool canReach(int* arr, int arrSize, int start)
{
    bool *visited = calloc(arrSize, sizeof(bool));

    bool result = travel(arr, arrSize, start, visited);
    free(visited);
    return result;
}

int main(void)
{
	int arr[] = {4,2,3,0,3,1,2};
	int size = 7;
	bool result = canReach(arr, size, 5);
	if (result)
		printf("True!\n");
	else
		printf("False!\n");
}
