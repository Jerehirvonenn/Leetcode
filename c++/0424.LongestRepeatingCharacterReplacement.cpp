/* Leetcode 424 - Longest Repeating Character Replacement (Medium)
 *
 * Problem:
 * You are given a string `s` consisting of uppercase English letters and an integer `k`.
 * You can choose any character of the string and change it to any other uppercase English character.
 * You can perform this operation at most `k` times.
 *
 * Return the length of the longest substring containing the same letter 
 * you can get after performing the above operations.
 *
 * Approach:
 * - Count frequency of each character in the string.
 * - For each uppercase letter A-Z:
 *     - Use sliding window to find the longest window where we need at most `k` changes 
 *       to make all characters equal to the current letter.
 *     - Update the longest found so far.
 * - Optimized by skipping characters that can't improve the result.
 *
 * Time Complexity: O(26 * n), where n is the length of string `s`
 * Space Complexity: O(1), constant extra space used for character counts
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        if (k >= n)
			return n;

        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        int longest = 0;
        for (int i = 0; i < 26; ++i)
		{
            char c = 'A' + i;
            if (k + freq[c] <= longest)
				continue;
            int left = 0;
			int swap = 0;
            for (int right = 0; right < n; right++)
			{
                if (s[right] != c)
					swap++;
                while (swap > k)
                    if (s[left++] != c)
						swap--;
                longest = max(longest, right - left + 1);
            }
        }
        return longest;
    }
};

int main(void)
{
    string s;
    int k;

    cout << "Enter the uppercase string: ";
    cin >> s;

    cout << "Enter max number of allowed replacements (k): ";
    cin >> k;

    Solution sol;
    int result = sol.characterReplacement(s, k);
    cout << "Longest substring after replacements: " << result << endl;
}
