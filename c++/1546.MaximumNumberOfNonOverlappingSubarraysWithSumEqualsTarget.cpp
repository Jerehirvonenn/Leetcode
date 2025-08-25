/* Leetcode 1546 - Maximum Number of Non-Overlapping Subarrays With Sum Equals Target (Medium)
 *
 * Problem:
 * Given an array nums and an integer target, return the maximum number of non-empty
 * non-overlapping subarrays such that the sum of values in each subarray is equal to target.
 *
 * Approach:
 * - Use a prefix sum and a hash map to track sums and their indices.
 * - When a subarray sum equals target, increment result and clear map to ensure non-overlapping.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        seen[0] = -1;
        int sum = 0;
        int result = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            sum += nums[i];
            if (seen.count(sum - target)) {
                seen.clear();
                result++;
            }
            seen[sum] = i;
        }
        return result;
    }
};

int main(void)
{
    Solution solution;
    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter target sum: ";
    cin >> target;

    vector<int> nums(n);
    cout << "Enter the array elements:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int result = solution.maxNonOverlapping(nums, target);
    cout << "Max number of non-overlapping subarrays with sum equals target: " << result << endl;
}
