/*
 * Leetcode 2901 - Longest Unequal Adjacent Groups Subsequence II (Medium)
 *
 * Problem:
 * You are given a string array `words` and an integer array `groups`, both of the same length `n`.
 * Select the longest subsequence of indices such that:
 *   1. Adjacent elements in the subsequence belong to *different* groups.
 *   2. The corresponding words have the same length.
 *   3. The hamming distance between each pair of adjacent words is exactly 1.
 * Return the longest such list of words. If multiple answers exist, return any.
 *
 * Example:
 * 		- Input: words = ["bab","dab","cab"], groups = [1,2,2]
 * 		- Output: ["bab","cab"]
 *
 * Approach:
 * - Use dynamic programming (similar to LIS - Longest Increasing Subsequence):
 *   - For each index i, store the longest subsequence ending at i using `dp[i]`.
 *   - Only update dp[i] if:
 *     - words[i] and words[j] differ by exactly 1 char
 *     - groups[i] != groups[j]
 *
 * Time Complexity: O(n^2 * k) where k is word length (for Hamming check)
 * Space Complexity: O(n)
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
private:
    bool isEligible(const string &a, const string &b) {
        if (a.size() != b.size()) return false;
        int diff = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) ++diff;
            if (diff > 1) return false;
        }
        return diff == 1;
    }

public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);

        int maxLength = 0;
        int endIndex = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (groups[i] != groups[j] && isEligible(words[i], words[j])) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
            }
            if (dp[i] > maxLength) {
                maxLength = dp[i];
                endIndex = i;
            }
        }

        vector<string> result;
        while (endIndex != -1) {
            result.push_back(words[endIndex]);
            endIndex = prev[endIndex];
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main(void)
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<string> words(n);
    vector<int> groups(n);

    cout << "Enter words:\n";
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }

    cout << "Enter groups:\n";
    for (int i = 0; i < n; ++i) {
        cin >> groups[i];
    }

    cout << "Original words: ";
    for (const auto &w : words) cout << w << " ";
    cout << "\nOriginal groups: ";
    for (int g : groups) cout << g << " ";
    cout << "\n";

    Solution sol;
    vector<string> result = sol.getWordsInLongestSubsequence(words, groups);

    cout << "Longest valid subsequence:\n";
    for (const auto &w : result) {
        cout << w << " ";
    }
    cout << endl;
}
