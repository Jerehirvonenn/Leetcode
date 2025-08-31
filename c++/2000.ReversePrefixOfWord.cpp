/*
 * Leetcode 2000 - Reverse Prefix of Word (Easy)
 *
 * Problem:
 * Given a string word and a character ch, reverse the segment of word from index 0
 * up to and including the first occurrence of ch. If ch doesn't exist in word, return word as is.
 *
 * Approach:
 * - Find the first occurrence index of ch.
 * - Reverse the substring from 0 to that index.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n = word.size();
        int i = 0;
        while (i < n && word[i] != ch) {
            i++;
        }
        if (i >= n) {
            return word;
        }
        for (int j = 0; j < i; j++) {
            swap(word[j], word[i--]);
        }
        return word;
    }
};

int main() {
    Solution solution;
    string word;
    char ch;

    cout << "Enter the word: ";
    getline(cin, word);
    cout << "Enter the character to reverse prefix up to: ";
    cin >> ch;

    string result = solution.reversePrefix(word, ch);
    cout << "Resulting string: " << result << endl;
}
