#include <stdio.h>

#define MAX_SIZE 1000

/* finding childs and parent in Min-Heap array
 * left child	2 * i + 1
 * right child	2 * i + 2
 * parent		(i - 1) / 2
 **/

// min-heap struct
typedef struct
{
	int arr[MAX_SIZE];
	int size;
} MinHeap;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void insert(MinHeap *head, int value)
{
	// to prevent overflow, inc max if needed
	if (head->size == MAX_SIZE)
	{
		return;
	}

	// insert value to the end of the list
	head->arr[head->size] = value;
	int i = head->size;
	head->size++;

	// bubble up if value is smaller then parents
	int parent = (i - 1) / 2;
	while (i > 0 && head->arr[i] < head->arr[parent])
	{
		swap(&head->arr[i], &head->arr[parent]);
		i = parent;
		parent = (i - 1) / 2;
	}
}

/*restores the min heap order from the given node
 * if parent is greater than any of its children, swap with smalles
 * repeat until heap is valid again
 * heap array looks like this atm 9 4 6 10 8 7
 * example (root, 0)
 *       9
 *     /   \
 *    4     6
 *   / \   /
 *  10  8 7
 *
 *       4
 *     /   \
 *    9     6
 *   / \   /
 *  10  8 7
 *
 * recursive call to (root, 1) becouse 9 is now in wrong place still
 * 9 changes with 8 and recursive call to right children right = 2 * 1 + 2 = 4
 * both children dont exist/out of bounds so call ends
 *
 * Final Heap after recursive call, heap is valid again
 *       4
 *     /   \
 *    8     6
 *   / \   /
 *  10  9 7
 */
void minHeapify(MinHeap *heap, int i)
{
	// calculate the index of children with the heap formula
	// assume smallest is root at this point
	int smallest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	// check that child exist and if its smaller than parent
	// update smallest to the index of the new found smallest
	if (left < heap->size && heap->arr[left] < heap->arr[smallest])
		smallest = left;
	if (right < heap->size && heap->arr[right] < heap->arr[smallest])
		smallest = right;

	// if parent wasnt the smallest swap parent and smallest child
	// call heapify recursively from the child that was swapped to ensure rest
	// of the heap stays valid
	if (smallest != i)
	{
		swap(&heap->arr[i], &heap->arr[smallest]);
		minHeapify(heap, smallest);
	}
}

void buildMinHeap(MinHeap *heap, int *nums, int numsSize)
{
	heap->size = numsSize;
	// copy the array into the heap without order
	for (int i = 0; i < numsSize; i++)
		heap->arr[i] = nums[i];

	// turn into Min heap
	// start from last parent node(size/2 - 1) and move up until root
	// nodes below this are leaf nodes and already valid min heaps
	for (int i = (heap->size / 2) - 1; i >= 0; i--)
		minHeapify(heap, i);
}

// removes the smallest (root) from the heap
// restores order of the Min heap
int extractMin(MinHeap *heap)
{
	if (heap->size == 0)
		return -1;

	// store the min value
	// move the last element to the root
	// heapify down from root to maintain order
	int minValue = heap->arr[0];
	heap->arr[0] = heap->arr[heap->size - 1];
	heap->size--;

	minHeapify(heap, 0);

	return minValue;
}

int minOperations(int *nums, int numsSize, int k)
{
	MinHeap heap;
	buildMinHeap(&heap, nums, numsSize);

	int operations = 0;
	while (heap.size > 1 && heap.arr[0] < k)
	{
		int x = extractMin(&heap);
		int y = extractMin(&heap);
		int new_val = (x * 2) + y;
		insert(&heap, new_val);
		operations++;
	}

	return operations;
}

int main(void)
{
	int nums[] = {97, 73, 5, 78};
	int k = 98;
	int numsSize = sizeof(nums) / sizeof(nums[0]);

	int result = minOperations(nums, numsSize, k);
	printf("Minimum operations: %d\n", result);
}
