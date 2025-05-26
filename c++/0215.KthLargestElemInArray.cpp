/*
 * Leetcode 215 - Kth Largest Element in an Array (Medium)
 *
 * Given an integer array nums and an integer k, return the kth largest element in the array.
 * Note that it is the kth largest element in the sorted order, not the kth distinct element.
 * Sorting the array is prohibited
 *
 * Approach:
 * - Uses a *min-heap* to maintain the top k largest elements.
 * - Traverse the array, inserting elements into the heap.
 * - If the heap exceeds size 'k', pop the smallest element.
 * - After processing all elements, the root of the heap will be the kth largest element.
 * 
 * Time Complexity: O(n log k) — where n is the number of elements in the array
 * Space Complexity: O(k) — since we store k elements in the heap
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
	{
        priority_queue<int, vector<int>, greater<>> minHeap;

        int size = 0;
        for (int num : nums) {
            minHeap.push(num);
            if (++size > k)
                minHeap.pop();
        }
        return minHeap.top();
    }
};

int main(void)
{
    int n, k;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter k (position of the largest element): ";
    cin >> k;
	if (k > n)
		return 42;

    Solution solution;
    int result = solution.findKthLargest(nums, k);
    cout << "The " << k << "th largest element is: " << result << endl;
}
