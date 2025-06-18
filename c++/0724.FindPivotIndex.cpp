/*
 * Leetcode 724 - Find Pivot Index (Easy)
 *
 * Problem:
 * Given an array of integers nums, return the pivot index — the index where the
 * sum of the numbers to the left is equal to the sum of the numbers to the right.
 * If no such index exists, return -1. If there are multiple, return the leftmost.
 *
 * Approach:
 * - First pass: build prefix sum array where prefix[i] is the sum of elements before index i.
 * - Second pass (from right to left): track the suffix sum and compare to prefix[i].
 * - If they match, update result with current index (ensuring leftmost by scanning right to left).
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 0);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            prefix[i] = sum;
            sum += nums[i];
        }

        sum = 0;
        int result = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (sum == prefix[i]) {
                result = i;
            }
            sum += nums[i];
        }
        return result;
    }
};

int main(void)
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    int pivot = sol.pivotIndex(nums);
    cout << "Pivot index: " << pivot << endl;
}
