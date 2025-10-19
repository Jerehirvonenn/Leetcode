/*
 * Leetcode 1827 - Minimum Operations to Make the Array Increasing (Easy)
 *
 * Problem:
 * Given an integer array `nums`, find the minimum number of increment
 * operations to make the array strictly increasing.
 *
 * Approach:
 * - Use a greedy approach. Iterate through the array starting from the second element.
 * - For each element `nums[i]`, compare it to the previous element `nums[i-1]`.
 * - If `nums[i]` is not greater than `nums[i-1]`, we must increase `nums[i]`.
 * - The new value for `nums[i]` must be `nums[i-1] + 1`. The number of
 * operations is the difference, which is added to the total count.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int result = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i - 1]) {
                result += nums[i - 1] - nums[i] + 1;
                nums[i] = nums[i - 1] + 1;
            }
        }
        return result;
    }
};

int main(void)
{
    Solution solution;

    // Example 1
    vector<int> nums1 = {1, 1, 1};
    cout << "Input: {1, 1, 1}" << endl;
    int ops1 = solution.minOperations(nums1);
    cout << "Minimum operations: " << ops1 << endl; // Expected: 3

    cout << "--------------------" << endl;

    // Example 2
    vector<int> nums2 = {1, 5, 2, 4, 1};
    cout << "Input: {1, 5, 2, 4, 1}" << endl;
    int ops2 = solution.minOperations(nums2);
    cout << "Minimum operations: " << ops2 << endl; // Expected: 14
    
    cout << "--------------------" << endl;

    // Example 3
    vector<int> nums3 = {8};
    cout << "Input: {8}" << endl;
    int ops3 = solution.minOperations(nums3);
    cout << "Minimum operations: " << ops3 << endl; // Expected: 0
}
