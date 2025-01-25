#include <stdio.h>

void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n)
{
	(void)nums2Size;
	int index1 = m - 1;
	int index2 = n - 1;
	int toPut = nums1Size - 1;
	while (index1 >= 0 && index2 >= 0)
	{
		if (nums1[index1] >= nums2[index2])
			nums1[toPut--] = nums1[index1--];
		else
			nums1[toPut--] = nums2[index2--];
	}
	while (index2 >= 0)
		nums1[toPut--] = nums2[index2--];
}

int main(void)
{
	int nums1[10] = {1, 3, 5, 7, 9};
	int nums2[5] = {2, 4, 6, 8, 10};
	int m = 5;
	int n = 5;

	merge(nums1, 10, m, nums2, 5, n);

	printf("Merged array: ");
	for (int i = 0; i < m + n; i++)
		printf("%d ", nums1[i]);
	printf("\n");
}
