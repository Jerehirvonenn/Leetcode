/*
 * Leetcode 1004 - Max Consecutive Ones III (Medium)
 *
 * Problem:
 * Given a binary array `nums` and an integer `k`, return the maximum number of consecutive 1's
 * in the array if you can flip at most `k` 0's.
 *
 * Example:
 * Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
 * Output: 6
 * Explanation: Flip indexes 5 and 10 (0s) to get 6 consecutive 1s.
 *
 * Approach:
 * - Use the sliding window technique with two pointers (`left` and `right`).
 * - Expand the right pointer and count the number of zeroes in the window.
 * - If the number of zeroes exceeds `k`, move the left pointer to shrink the window.
 * - Track the maximum window length that satisfies the condition.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int longestOnes(vector<int>& nums, int k) {
		int zeroes = 0, biggest = 0, left = 0;
		for (int right = 0; right < nums.size(); right++) {
			if (nums[right] == 0)
				zeroes++;
			while (zeroes > k)
				if (nums[left++] == 0) zeroes--;
			biggest = max(biggest, right - left + 1);
		}
		return biggest;
	}
};

int main() {
	int n, k;
	cout << "Enter size of array: ";
	cin >> n;

	vector<int> nums(n);
	cout << "Enter binary elements (0 or 1): ";
	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
	}

	cout << "Enter k (max flips): ";
	cin >> k;

	Solution sol;
	cout << "Maximum consecutive ones after flipping at most " << k << " zeroes: "
	     << sol.longestOnes(nums, k) << endl;
}
