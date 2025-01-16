#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int index;
	int value;
	int isOccupied;
} HashMap;

int hash(int key, int size) { return abs(key % size); }

void insert(HashMap *map, int key, int value, int size)
{
	int idx = hash(key, size);
	while (map[idx].isOccupied)
	{
		if (map[idx].index == key)
		{
			return; // Skip inserting duplicates
		}
		idx = (idx + 1) % size;
	}
	map[idx].index = key;
	map[idx].value = value;
	map[idx].isOccupied = 1; // Mark slot as occupied
}

int find(HashMap *map, int key, int size)
{
	int idx = hash(key, size);
	while (map[idx].isOccupied)
	{
		if (map[idx].index == key)
		{
			return map[idx].value;
		}
		idx = (idx + 1) % size;
	}
	return -1; // Not found
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
	int *ret = (int *)malloc(sizeof(int) * 2);
	*returnSize = 2;
	if (numsSize == 2)
	{
		ret[0] = 0;
		ret[1] = 1;
		return ret;
	}

	HashMap *hashMap = (HashMap *)malloc(numsSize * sizeof(HashMap));
	for (int i = 0; i < numsSize; i++)
	{
		hashMap[i].isOccupied = 0; // Initialize with isOccupied = 0
	}

	for (int i = 0; i < numsSize; i++)
	{
		int toFind = target - nums[i];
		int toFindIndex = find(hashMap, toFind, numsSize);
		if (toFindIndex != -1)
		{
			ret[0] = toFindIndex;
			ret[1] = i;
			free(hashMap);
			return ret;
		}
		insert(hashMap, nums[i], i, numsSize);
	}
	*returnSize = 0;
	free(hashMap);
	return NULL;
}

int main()
{
	int	 returnSize;
	int *result;

	// Test case 1: Simple positive numbers
	int nums1[] = {2, 7, 11, 15};
	result = twoSum(nums1, 4, 9, &returnSize);
	printf("Test 1: [%d, %d]\n", result[0], result[1]); // Expected: [0, 1]
	free(result);

	// Test case 2: Contains negative numbers
	int nums2[] = {-10, -1, -18, -19};
	result = twoSum(nums2, 4, -19, &returnSize);
	printf("Test 2: [%d, %d]\n", result[0], result[1]); // Expected: [1, 2]
	free(result);

	// Test case 3: Mix of positive and negative
	int nums3[] = {-3, 4, 3, 90};
	result = twoSum(nums3, 4, 0, &returnSize);
	printf("Test 3: [%d, %d]\n", result[0], result[1]); // Expected: [0, 2]
	free(result);

	// Test case 4: Duplicates in the array
	int nums4[] = {3, 2, 5, 3};
	result = twoSum(nums4, 4, 6, &returnSize);
	printf("Test 4: [%d, %d]\n", result[0], result[1]); // Expected: [0, 3]
	free(result);

	// Test case 5: Only two elements
	int nums5[] = {1, 3};
	result = twoSum(nums5, 2, 4, &returnSize);
	printf("Test 5: [%d, %d]\n", result[0], result[1]); // Expected: [0, 1]

	// Test case 6: No valid pair (return NULL)
	int nums6[] = {1, 2, 3, 4};
	result = twoSum(nums6, 4, 10, &returnSize);
	if (result == NULL)
	{
		printf("Test 6: No valid pair\n"); // Expected: No valid pair
	}
	else
	{
		printf("Test 6: [%d, %d]\n", result[0], result[1]);
		free(result);
	}
}
