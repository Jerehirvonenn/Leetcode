/*
 * Leetcode 1413 - Minimum Value to Get Positive Step by Step Sum (Easy)
 *
 * Problem:
 * Given an array of integers nums, you start with an initial positive value startValue.
 *
 * In each iteration, you calculate the step by step sum of startValue
 * plus elements in nums (from left to right).
 *
 * Return the minimum positive value of startValue such that the step by step sum is never less than 1.
 *
 * Approach:
 * - Simulate the process by iterating over the array.
 * - Keep track of the prefix sum as you traverse the array.
 * - Track the minimum prefix sum encountered during the traversal.
 * - The minimum start value needed is:
 *       1 - (minimum prefix sum)
 *   to ensure that the cumulative sum never drops below 1.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int result = 1;
        int sum = 0;
        for (const int num : nums) {
            sum += num;
            result = min(result, sum);
        }
        return result <= 0 ? -result + 1 : result;
    }
};

int main(void)
{
    Solution solution;
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the array elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int startValue = solution.minStartValue(nums);
    cout << "Minimum start value to keep step by step sum >= 1: " << startValue << endl;
}
