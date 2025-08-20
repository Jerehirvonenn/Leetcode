/*
 * Leetcode 557 - Reverse Words in a String III (Easy)
 *
 * Problem:
 * Given a string s, reverse the characters in each word while preserving word order and whitespace.
 *
 * Approach:
 * - Iterate over the string to find each word boundaries.
 * - Reverse characters in place for each word.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = 0;

        while (i < n) {
            int start = i;
            int end = i + 1;
            while (end < n && s[end] != ' ')
                end++;
            i = end;
            end--;
            while (start < end)
                swap(s[start++], s[end--]);
            while (i < n && s[i] == ' ')
                i++;
        }
        return s;
    }
};

int main(void) {
    Solution solution;
    string s;
    cout << "Enter a sentence: ";
    getline(cin, s);

    string result = solution.reverseWords(s);
    cout << "Reversed words: " << result << endl;
}
