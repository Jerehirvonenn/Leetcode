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
