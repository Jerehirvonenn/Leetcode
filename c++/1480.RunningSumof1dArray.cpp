/*
 * Leetcode 1480 - Running Sum of 1d Array (Easy)
 *
 * Problem:
 * Given an array nums, return the running sum of the array.
 * The running sum at index i is defined as the sum of all elements
 * from index 0 to i, inclusive.
 *
 * Example:
 * Input:  nums = [1, 2, 3, 4]
 * Output: [1, 3, 6, 10]
 *
 * Approach:
 * - Iterate through the input array and maintain a cumulative sum.
 * - Store each cumulative sum into the result array.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            result[i] = sum;
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
    vector<int> result = sol.runningSum(nums);

    cout << "Running sum: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
}
