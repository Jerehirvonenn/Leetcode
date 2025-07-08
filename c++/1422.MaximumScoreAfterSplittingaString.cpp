/*
 * Leetcode 1422 - Maximum Score After Splitting a String (Easy)
 *
 * Problem:
 * Given a string s of zeros and ones, return the maximum score after splitting the string
 * into two non-empty substrings (i.e., left substring and right substring).
 *
 * The score after splitting a string is defined as:
 *     (number of '0's in the left substring) + (number of '1's in the right substring).
 *
 * Approach:
 * - First, count the total number of '1's in the entire string.
 * - Traverse the string from left to right (up to n - 1 to ensure non-empty right substring).
 * - Keep track of the number of '0's in the left substring and decrement the remaining '1's
 *   in the right substring.
 * - At each split point, calculate the score and update the maximum score found so far.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int n = s.size();

        int one = 0;
        for (int i = 0; i < n; i++) {
            one += (s[i] == '1');
        }

        int zero = 0;
        int result = 0;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '0')
                zero++;
            else
                one--;
            result = max(result, zero + one);
        }
        return result;
    }
};

int main(void)
{
    Solution solution;
    string s;
    cout << "Enter the binary string (containing only '0' and '1'): ";
    cin >> s;

    int score = solution.maxScore(s);
    cout << "Maximum score after splitting the string: " << score << endl;
}
