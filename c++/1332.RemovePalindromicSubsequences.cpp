/*
 * Leetcode 1332 - Remove Palindromic Subsequences (Easy)
 *
 * Problem:
 * You are given a string s consisting only of letters 'a' and 'b'.
 * In a single step you can remove one palindromic subsequence from s.
 * Return the minimum number of steps to make the given string empty.
 *
 * Approach:
 * - If the string is already a palindrome, we can remove it in 1 step.
 * - Otherwise, we can always remove all 'a's in one step and all 'b's in another step
 *   (since they form palindromic subsequences individually).
 * - So, the answer is either 1 or 2.
 * - To check for palindrome, compare characters from both ends moving toward the center.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int removePalindromeSub(string s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            if (s[left++] != s[right--])
                return 2;
        }
        return 1;
    }
};

int main(void)
{
    Solution solution;
    string s;
    cout << "Enter the string consisting of 'a' and 'b': ";
    cin >> s;

    int result = solution.removePalindromeSub(s);
    cout << "Minimum number of steps to remove palindromic subsequences: " << result << endl;
}
