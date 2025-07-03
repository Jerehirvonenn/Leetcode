/*
 * Leetcode 848 - Shifting Letters (Medium)
 *
 * Problem:
 * You are given a string s of lowercase English letters and an integer array shifts of the same length.
 * For each i, you must shift the first i + 1 characters of s by shifts[i] positions forward in the alphabet.
 * Wrap around so that 'z' becomes 'a'.
 *
 * Example:
 *   Input: s = "abc", shifts = [3,5,9]
 *   Output: "rpl"
 *
 * Approach:
 * - Traverse shifts from the end to the start, maintaining a running sum of total shifts.
 * - For each character, apply (sum % 26) shifts and update it accordingly.
 * - Use unsigned long long to avoid integer overflow during summation.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.size();

        long sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            sum += shifts[i];
            s[i] = (s[i] - 'a' + sum % 26) % 26 + 'a';
        }
        return s;
    }
};

int main() {
    string s;
    int n;
	cout << "string: ";
    cin >> s;

    vector<int> shifts(n);
	cout << s.size() << " shifts: ";
    for (int i = 0; i < s.size(); i++) {
        cin >> shifts[i];
    }

    Solution solution;
    string result = solution.shiftingLetters(s, shifts);
    cout << result << endl;
}
