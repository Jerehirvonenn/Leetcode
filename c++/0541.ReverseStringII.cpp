/*
 * Leetcode 541 - Reverse String II (Easy)
 *
 * Problem:
 * Given a string s and an integer k, reverse the first k characters for every 2k characters
 * counting from the start of the string.
 *
 * If there are fewer than k characters left, reverse all of them.
 * If there are less than 2k but greater than or equal to k characters, then reverse
 * the first k characters and leave the other as original.
 *
 * Approach:
 * - Iterate over the string in steps of 2k.
 * - Reverse the first k characters (or less if fewer remain).
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        for (int start = 0; start < n; start += 2 * k) {
            int end = min(n - 1, start + k - 1);
            for (int i = start; i < end; i++) {
                swap(s[i], s[end--]);
            }
        }
        return s;
    }
};

int main(void)
{
    Solution solution;
    string s;
    int k;

    cout << "Enter the string: ";
    getline(cin, s);
    cout << "Enter the integer k: ";
    cin >> k;

    string result = solution.reverseStr(s, k);
    cout << "Resulting string: " << result << endl;
}
