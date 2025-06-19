/*
 * Leetcode 2294 - Partition Array Such That Maximum Difference Is K (Medium)
 *
 * Problem:
 * Given an integer array nums and an integer k, partition the array into the minimum number
 * of subsequences such that the difference between the maximum and minimum elements in each
 * subsequence is at most k. Each element must be in exactly one subsequence.
 *
 * Example:
 * Input: nums = [3,6,1,2,5], k = 2
 * Output: 2
 * Explanation: One optimal partition is [1,2,3] and [5,6]
 *
 * Approach:
 * - Sort the array.
 * - Iterate through elements and track the start of the current group (smallest).
 * - When the difference between current number and the start exceeds k, start a new group.
 *
 * Time Complexity: O(n log n)  (due to sorting)
 * Space Complexity: O(1)       (ignoring sorting space)
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int result = 0;
        int smallest = -100000;
        for (const int num : nums) {
            if (num - smallest > k) {
                result++;
                smallest = num;
            }
        }
        return result;
    }
};

int main(void)
{
    int n, k;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter k: ";
    cin >> k;

    Solution sol;
    int result = sol.partitionArray(nums, k);
    cout << "Minimum number of subsequences: " << result << endl;
}
