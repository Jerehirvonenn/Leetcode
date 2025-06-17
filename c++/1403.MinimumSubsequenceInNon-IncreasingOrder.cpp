/*
 * Leetcode 1403 - Minimum Subsequence in Non-Increasing Order (Easy)
 *
 * Problem:
 * Given an integer array `nums`, return the smallest subsequence in non-increasing order
 * such that the sum of its elements is strictly greater than the sum of the remaining elements.
 *
 * If multiple solutions exist:
 * - Choose the one with the minimum size.
 * - If still multiple, choose the one with the largest total sum.
 * Return the answer sorted in non-increasing order.
 *
 * Approach:
 * - Sort the array in descending order.
 * - Iterate through the sorted array, adding elements to a result subsequence
 *   while tracking the current sum and remaining total.
 * - Stop when the current sum exceeds the remaining total.
 *
 * Time Complexity: O(n log n) due to sorting
 * Space Complexity: O(n) for the result array
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
private:
    static bool greater(const int a, const int b) {
        return a > b;
    }

public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater);

        int total = accumulate(nums.begin(), nums.end(), 0);
        int current = 0;
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            if (current > total) {
                break;
            }
            current += nums[i];
            total -= nums[i];
            result.push_back(nums[i]);
        }

        return result;
    }
};

int main(void)
{
    Solution sol;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    vector<int> result = sol.minSubsequence(nums);
    cout << "Minimum subsequence with greater sum: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
}
