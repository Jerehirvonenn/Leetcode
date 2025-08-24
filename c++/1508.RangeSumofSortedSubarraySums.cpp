/*
 * Leetcode 1508 - Range Sum of Sorted Subarray Sums (Medium)
 *
 * Problem:
 * Given an array nums of n positive integers, compute the sums of
 * all non-empty continuous subarrays.
 * Sort these sums in non-decreasing order.
 * Return the sum of the numbers from index left to right (1-based), inclusive, modulo 10^9 + 7.
 *
 * Approach:
 * - Generate all subarray sums using nested loops.
 * - Store them in a vector and sort the vector.
 * - Sum the elements from left-1 to right-1 indices modulo 1,000,000,007.
 *
 * Time Complexity: O(n^2 log n^2) = O(n^2 log n)
 * Space Complexity: O(n^2)
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    const int MOD = 1e9 + 7;
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> sums;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                sums.push_back(sum);
            }
        }

        sort(sums.begin(), sums.end());

        long long result = 0;
        for (int i = left - 1; i < right; i++) {
            result = (result + sums[i]) % MOD;
        }
        return (int)result;
    }
};

int main(void)
{
    Solution solution;
    int n, left, right;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter left and right indices (1-based): ";
    cin >> left >> right;

    vector<int> nums(n);
    cout << "Enter the array elements:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int result = solution.rangeSum(nums, n, left, right);
    cout << "Range sum of sorted subarray sums: " << result << endl;
}
