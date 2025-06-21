/*
 * Leetcode 3085 - Minimum Deletions to Make String K-Special (Medium)
 *
 * Problem:
 * A string is k-special if for all pairs of characters,
 * the absolute difference between their frequencies is ≤ k.
 * Given a lowercase string `word` and an integer `k`,
 * return the minimum number of deletions needed to make it k-special.
 *
 * Approach:
 * - Count frequency of each character using a 26-element vector.
 * - Extract non-zero frequencies into a list.
 * - Try all possible target frequencies `f` from 1 to maxFreq - k.
 *   For each f, calculate how many deletions are required to make all character frequencies fall in [f, f + k].
 *   - Delete all characters with freq < f
 *   - Delete the excess from characters with freq > f + k
 * - Track and return the minimal number of deletions across all valid target frequencies.
 *
 * Time Complexity: O(n + 26 * maxFreq) ≈ O(n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumDeletions(string word, int k) {
        int n = word.size();
        if (k >= n) {
            return 0;
        }
        vector<int> freqs(26, 0);
        int maxFreq = 0;
        for (const char c : word) {
            maxFreq = max(maxFreq, ++freqs[c - 'a']);
        }

        vector<int> freq;
        for (const int num : freqs) {
            if (num > 0) {
                freq.push_back(num);
            }
        }

        int minDel = INT_MAX;
        for (int f = 1; f <= maxFreq - k; f++)
        {
            int del = 0;
            for (const int num : freq) {
                if (num < f)
                    del += num;
                else if (num > f + k)
                    del += num - (f + k);
            }
            minDel = min(minDel, del);
        }
        return minDel == INT_MAX ? 0 : minDel;
    }
};

int main(void)
{
    string word;
    int k;

    cout << "Enter a lowercase word: ";
    cin >> word;
    for (char c : word) {
        if (c < 'a' || c > 'z') {
            cout << "Invalid input: word must contain only lowercase letters.\n";
            return 1;
        }
    }

    cout << "Enter value of k: ";
    cin >> k;
    Solution sol;
    int result = sol.minimumDeletions(word, k);
    cout << "Minimum deletions to make the word k-special: " << result << endl;
}
