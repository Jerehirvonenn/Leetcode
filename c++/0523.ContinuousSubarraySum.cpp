/*
 * Leetcode 523 - Continuous Subarray Sum (Medium)
 *
 * Problem:
 * Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise.
 * 
 * A good subarray is a subarray where:
 * - its length is at least two, and
 * - the sum of the elements of the subarray is a multiple of k.
 * 
 * Approach:
 * - Use a running prefix sum and track (sum % k) in a hashmap with its earliest index.
 * - If we see the same modulo again and the subarray length is >= 2, return true.
 * - Initialize seen[0] = -1 to handle subarrays starting from index 0.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(k) at most due to modulo tracking
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

pair<int, int> indx = {- 1,-1};

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> seen;
        int sum = 0;
        seen[0] = -1;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int modulo = sum % k;
            if (seen.count(modulo)) {
                if (i - seen[modulo] > 1) {
					indx.first = seen[modulo] + 1;
					indx.second = i;
                    return true;
				}
            }
			else
                seen[modulo] = i;
        }
        return false;
    }
};

int main() {
    int n, k;
    cout << "Enter number of elements in nums: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements of nums: ";
    for (int i = 0; i < n; ++i)
        cin >> nums[i];

    cout << "Enter k: ";
    cin >> k;

    Solution sol;
    bool result = sol.checkSubarraySum(nums, k);
	if (result)
		cout << "true, from " << indx.first << " to " << indx.second << endl;
	else
		cout << "false" << endl;
}
