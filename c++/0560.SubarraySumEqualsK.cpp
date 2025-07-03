/*
 * Leetcode 560 - Subarray Sum Equals K (Medium)
 *
 * Problem:
 * Given an array of integers nums and an integer k, return the total number of subarrays
 * whose sum equals to k.
 *
 * A subarray is a contiguous non-empty sequence of elements within an array.
 *
 * Approach:
 * - Use a hash map to store the frequency of prefix sums.
 * - Initialize the map with {0:1} to count subarrays that directly start at index 0.
 * - As we iterate over the array, we calculate the prefix sum.
 * - If (prefixSum - k) exists in the map, it means there's a subarray that sums to k.
 * - Add the frequency of (prefixSum - k) to the result.
 * - Update the frequency of the current prefix sum in the map.
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
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        freq[0]++;

        int sum = 0;
        int result = 0;
        for (const int num : nums) {
            sum += num;
            if (freq.count(sum - k)) {
                result += freq[sum - k];
            }
            freq[sum]++;
        }
        return result;
    }
};

int main() {
    int n, k;
	cout << "Provide size of array: ";
    cin >> n;

    vector<int> nums(n);
	cout << "Provide " << n << " elements: ";
    for (int& x : nums) {
        cin >> x;
    }
	cout << "K value: ";
	cin >> k;

    Solution sol;
    int result = sol.subarraySum(nums, k);
    cout << result << endl;
}
