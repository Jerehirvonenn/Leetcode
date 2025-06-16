/*
 * Leetcode 2016: Maximum Difference Between Increasing Elements
 *
 * Problem:
 * Given a 0-indexed integer array nums, find the maximum difference nums[j] - nums[i]
 * such that:
 *   - 0 <= i < j < n
 *   - nums[i] < nums[j]
 * Return the maximum difference. If no such i and j exist, return -1.
 *
 * Approach:
 * - Iterate through the array, keeping track of the smallest value seen so far.
 * - At each step, calculate the difference between the current value and the smallest value.
 * - Update the result if a larger difference is found.
 * - Return -1 if no valid pair was found (i.e., result remains 0).
 */
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maximumDifference(vector<int>& nums)
	{
        int smallest = INT_MAX;
        int result = 0;
        for (const int num : nums) {
            smallest = min(smallest, num);
            result = max(result, num - smallest);
        }
        return result == 0 ? -1 : result;
    }
};

int main(void)
{
    int n;
	cout << "vector size: ";
    cin >> n;
	cout << "Provide " << n << " numbers: ";
    vector<int> nums(n);
    for (int& num : nums) {
        cin >> num;
    }

    Solution sol;
    cout << sol.maximumDifference(nums) << endl;
}
