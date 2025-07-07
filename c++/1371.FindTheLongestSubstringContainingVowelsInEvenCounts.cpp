/*
 * Leetcode 1371 - Find the Longest Substring Containing Vowels in Even Counts (Medium)
 *
 * Problem:
 * Given a string s, return the length of the longest substring in which each vowel
 * ('a', 'e', 'i', 'o', 'u') appears an even number of times.
 *
 * Approach:
 * - Use a bitmask to track the parity (even/odd) of each vowel.
 * - Use a hash map to remember the first index where each mask was seen.
 * - If a mask repeats at index j and i, the substring s[i+1..j] has balanced vowels.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n) worst case for map
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findTheLongestSubstring(string s) {
        int mask = 0;
        int longest = 0;
        unordered_map<int, int> seen;
        seen[0] = -1;
        for (int i = 0; i < s.size(); i++) {
            switch (s[i]) {
                case 'a': mask ^= (1 << 0); break;
                case 'e': mask ^= (1 << 1); break;
                case 'i': mask ^= (1 << 2); break;
                case 'o': mask ^= (1 << 3); break;
                case 'u': mask ^= (1 << 4); break;
            }
            if (seen.count(mask))
                longest = max(longest, i - seen[mask]);
            else
                seen[mask] = i;
        }
        return longest;
    }
};

int main() {
    Solution sol;
    string s;
    cout << "Enter the string: ";
    cin >> s;

    int result = sol.findTheLongestSubstring(s);
    cout << "Length of the longest substring with even vowel counts: " << result << endl;
}
