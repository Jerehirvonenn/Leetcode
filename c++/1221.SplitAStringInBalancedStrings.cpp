/*
 * Leetcode 1221 - Split a String in Balanced Strings (Easy)
 *
 * Problem:
 * Balanced strings have an equal number of 'L' and 'R' characters.
 * Given a balanced string `s`, split it to get the maximum number
 * of balanced substrings.
 *
 * Approach:
 * - Keep a running count of 'L' and 'R' characters.
 * - Whenever the counts of 'L' and 'R' become equal, a balanced
 * substring has been found.
 * - Increment the result counter and reset the 'L' and 'R' counts to zero
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) {
        int L = 0, R = 0, result = 0;
        for (const char c : s) {
            L += c == 'L';
            R += c == 'R';
            if (L == R) {
                result++;
                L = 0;
                R = 0;
            }
        }
        return result;
    }
};

int main(void)
{
    Solution solution;

    // Example 1
    string s1 = "RLRRLLRLRL";
    cout << "Input: \"" << s1 << "\"" << endl;
    int res1 = solution.balancedStringSplit(s1);
    cout << "Maximum balanced substrings: " << res1 << endl; // Expected: 4

    cout << "--------------------" << endl;

    // Example 2
    string s2 = "RLRRRLLRLL";
    cout << "Input: \"" << s2 << "\"" << endl;
    int res2 = solution.balancedStringSplit(s2);
    cout << "Maximum balanced substrings: " << res2 << endl; // Expected: 2

    cout << "--------------------" << endl;

    // Example 3
    string s3 = "LLLLRRRR";
    cout << "Input: \"" << s3 << "\"" << endl;
    int res3 = solution.balancedStringSplit(s3);
    cout << "Maximum balanced substrings: " << res3 << endl; // Expected: 1

    return 0;
}
