/*
 * Problem: 594. Longest Harmonious Subsequence
 *
 * A harmonious array is defined as one where the difference between the maximum
 * and minimum values is exactly 1. Given an integer array `nums`, this function
 * finds the length of the longest harmonious subsequence — i.e., any subsequence
 * where the max - min == 1.
 *
 * Approach:
 * - Count the frequency of each element using an unordered_map.
 * - For each key, check if key + 1 exists.
 * - If it does, the sum of frequencies of key and key + 1 is a valid subsequence.
 * - Track the maximum length found across all such pairs.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums)
    {
        unordered_map<int, int> freq;
        for (const int num : nums) {
            freq[num]++;
        }

        int longest = 0;
        for (const auto& [key, value] : freq) {
            if (freq.count(key + 1)) {
                longest = max(longest, value + freq[key + 1]);
            }
        }
        return longest;
    }
};

int main(void)
{
    Solution sol;

    vector<int> test1 = {1, 3, 2, 2, 5, 2, 3, 7};
    cout << "Test 1 Output: " << sol.findLHS(test1) << endl;

    vector<int> test2 = {1, 2, 3, 4};
    cout << "Test 2 Output: " << sol.findLHS(test2) << endl;

    vector<int> test3 = {1, 1, 1, 1};
    cout << "Test 3 Output: " << sol.findLHS(test3) << endl;
}
