/*
 * Leetcode 1177 - Can Make Palindrome from Substring (Medium)
 *
 * Problem:
 * You are given a string s and an array queries where queries[i] = [lefti, righti, ki].
 * For each query, you may rearrange the substring s[lefti...righti] and replace up to ki letters.
 * A query is true if it's possible to make the substring a palindrome after those operations.
 *
 * Approach:
 * - Precompute prefix frequency counts for each letter.
 * - For a query, compute how many characters in the substring have odd counts.
 * - At most ki replacements can be used to fix odd-count characters into pairs.
 * - A palindrome allows at most one unmatched character (if length is odd).
 * - If (odd_count / 2) <= ki, it's possible to make it a palindrome.
 *
 * Time Complexity: O(n + q * 26), where n is string length and q is number of queries
 * Space Complexity: O(n * 26) for prefix frequency table
 */

// 1177.CanMakePalindromeFromSubstring.cpp

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    bool canPalindrome(vector<vector<int>> &freq, int l, int r, int k) {
        vector<int> &left = freq[l];
        vector<int> &right = freq[r];
        int maxOdds = (r - l) % 2 == 0 ? 0 : 1;
        int odds = 0;
        for (int i = 0; i < 26; i++) {
            int checking = right[i] - left[i];
            if (checking % 2 == 1) {
                odds++;
            }
        }
        return (odds - k * 2 <= maxOdds);
    }

public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> currentFreq(26, 0);
        vector<vector<int>> freq;
        freq.push_back(currentFreq);

        for (const char c : s) {
            currentFreq[c - 'a']++;
            freq.push_back(currentFreq);
        }

        vector<bool> result;
        for (auto &current : queries) {
            result.push_back(canPalindrome(freq, current[0], current[1] + 1, current[2]));
        }
        return result;
    }
};

int main() {
    string s;
    int q;

    cout << "Enter string s: ";
    cin >> s;

    cout << "Enter number of queries: ";
    cin >> q;

    vector<vector<int>> queries(q, vector<int>(3));
    for (int i = 0; i < q; i++) {
        cout << "Enter query " << i + 1 << " (format: left right k): ";
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
    }

    Solution sol;
    vector<bool> result = sol.canMakePaliQueries(s, queries);

    for (bool res : result)
        cout << (res ? "true" : "false") << endl;
}
