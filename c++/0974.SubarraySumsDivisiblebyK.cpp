/*
 * Leetcode 974 - Subarray Sums Divisible by K (Medium)
 *
 * Problem:
 * Given an integer array nums and an integer k, return the number of non-empty subarrays
 * whose sum is divisible by k.
 *
 * A subarray is a contiguous sequence of elements within the array.
 *
 * Approach:
 * - Use prefix sum and a hashmap to store counts of modulo values.
 * - For each prefix sum, compute mod = ((sum % k) + k) % k to handle negative values.
 * - If we've seen this mod before, add its count to the result.
 * - This works because if two prefix sums have the same mod, their difference is divisible by k.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(k) in the worst case (all different mods)
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> seen;
        seen[0]++;

        int sum = 0;
        int result = 0;
        for (const int num : nums) {
            sum += num;
            int looking = ((sum % k) + k) % k;
            if (seen.count(looking)) {
                result += seen[looking];
            }
            seen[looking]++;
        }
        return result;
    }
};

int main() {
    int n, k;
	cout << "Number of elements: ";
    cin >> n;
    vector<int> nums(n);
	cout << n << " Elements: ";
    for (int& num : nums)
		cin >> num;
	cout << "divisible by K: ";
    cin >> k;

    Solution sol;
    int result = sol.subarraysDivByK(nums, k);
    cout << "Number of subarrays divisible by " << k << ": " << result << endl;
}
