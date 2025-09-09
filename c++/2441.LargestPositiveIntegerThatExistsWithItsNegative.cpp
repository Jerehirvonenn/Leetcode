/*
 * Leetcode 2441 - Largest Positive Integer That Exists With Its Negative (Easy)
 *
 * Problem:
 * Given an integer array nums that does not contain any zeros, find the largest positive integer k such that -k also exists in the array.
 * Return the positive integer k. If there is no such integer, return -1.
 *
 * Approach:
 * - Use an unordered_set to store the seen numbers.
 * - For each number, check if its negative counterpart already exists in the set.
 * - If so, update the largest such value found.
 * - Return the largest value found, or -1 if none exists.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int biggest = -1;
        unordered_set<int> seen;
        for (const int num : nums) {
            seen.insert(num);
            if (seen.count(-num)) {
                biggest = max(biggest, abs(num));
            }
        }
        return biggest;
    }
};

int main(void)
{
    Solution solution;
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the array elements (no zeros): ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int result = solution.findMaxK(nums);
    cout << "Largest positive integer k such that both k and -k exist: " << result << endl;
}
