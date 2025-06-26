/*
 * Leetcode 525 - Contiguous Array (Medium)
 *
 * Problem:
 * Given a binary array nums, return the maximum length of a contiguous subarray
 * with an equal number of 0 and 1.
 *
 * Approach:
 * - Use a prefix sum (sum += 1 for 1, sum -= 1 for 0).
 * - Use a hash map to store the first index where a given sum occurs.
 * - If the same sum appears again at index i, then the subarray between that index and i has sum 0.
 * - Track the maximum such subarray length.
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
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int biggest = 0;
        int sum = 0;
        unordered_map<int, int> seen;
        seen[0] = -1;
        for (int i = 0; i < n; i++) {
            nums[i] == 1 ? sum += 1 : sum -= 1;
            if (seen.count(sum))
                biggest = max(biggest, i - seen[sum]);
            else
                seen[sum] = i;
        }
        return biggest;
    }
};

int main() {
    int n;
	cout << "Number of elements: ";
    cin >> n;
    vector<int> nums(n);
	cout << "Provide " << n << " numbers (only 0, 1): ";
    for (int& x : nums)
		cin >> x;

    Solution sol;
    cout << "Longest subarray with equal amount of 0's and 1's is " << sol.findMaxLength(nums) << endl;
}
