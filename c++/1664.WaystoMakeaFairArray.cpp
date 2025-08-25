/*
 * Leetcode 1664 - Ways to Make a Fair Array (Medium)
 *
 * Problem:
 * Given an integer array nums, you can remove exactly one element at index i.
 * After removal, an array is fair if the sum of values at even indices equals
 * the sum at odd indices.
 * Return the number of indices i such that removing nums[i] results in a fair array.
 *
 * Approach:
 * - Calculate total sums of odd and even indexed elements.
 * - Iterate over each index removing nums[i]:
 *   - Update the totals by removing nums[i].
 *   - Check if after removal the sums of even and odd indexed elements match.
 *   - Use prefix sums to maintain sums on left side.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        int totalOdd = 0;
        int totalEven = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                totalEven += nums[i];
            }
            else {
                totalOdd += nums[i];
            }
        }

        int prefixOdd = 0;
        int prefixEven = 0;
        int result = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                totalEven -= nums[i];
                if (prefixEven + totalOdd == prefixOdd + totalEven)
                    result++;
                prefixEven += nums[i];
            }
            else {
                totalOdd -= nums[i];
                if (prefixEven + totalOdd == prefixOdd + totalEven)
                    result++;
                prefixOdd += nums[i];   
            }
        }
        return result;
    }
};

int main(void)
{
    Solution solution;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the array elements:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int result = solution.waysToMakeFair(nums);
    cout << "Number of ways to make the array fair: " << result << endl;
}
