/* Leetcode 2900 - Longest Unequal Adjacent Groups Subsequence I (Easy)
 *
 * Problem:
 * Given a string array `words` and a binary array `groups`, both of the same length,
 * return the longest subsequence of `words` such that no two adjacent elements in the
 * subsequence have the same corresponding group value.
 *
 * A subsequence is formed by deleting some (or no) elements from the array while maintaining order.
 *
 * Approach:
 * - Greedy approach, Start with the first word.
 * - Iterate through the groups array.
 * - Only add a word to the result if its group differs from the previous one added.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups)
    {
        vector<string> result;
        result.push_back(words[0]);
        for (int i = 1; i < words.size(); i++) {
            if (groups[i] != groups[i - 1]) {
                result.push_back(words[i]);
            }
        }
        return result;
    }
};

int main(void)
{
    vector<string> words = {"apple", "banana", "cherry", "date", "elderberry"};
    vector<int> groups = {1, 1, 2, 2, 3};

    Solution sol;
    vector<string> result = sol.getLongestSubsequence(words, groups);
    cout << "Longest subsequence with different consecutive groups:" << endl;
    for (const string& word : result) {
        cout << word << " ";
    }
    cout << endl;
}
