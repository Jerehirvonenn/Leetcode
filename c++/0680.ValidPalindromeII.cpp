/*
 * Leetcode 680 - Valid Palindrome II (Easy)
 *
 * Problem:
 * Given a string s, return true if s can be a palindrome after deleting at most one character.
 *
 * Approach:
 * - Use two pointers: one from the left and one from the right.
 * - While characters match, continue inward.
 * - On first mismatch, try skipping either the left or the right character.
 *   Check both resulting substrings for palindrome validity.
 * - If either is a palindrome, return true.
 * - Otherwise, return false.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
private:
    bool isPalindrome(const string &s, int left, int right) {
        while (left < right)
		{
            if (s[left++] != s[right--]) {
                return false;
            }
        }
        return true;
    }

public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right)
		{
            if (s[left] != s[right]) {
                return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
            }
            left++;
            right--;
        }
        return true;
    }
};

int main(void)
{
    string input;
    cout << "Enter a string: ";
    cin >> input;

    Solution solution;
    bool result = solution.validPalindrome(input);

    cout << "Original string: " << input << endl;
    cout << "Can be a palindrome by removing at most one character? "
         << (result ? "Yes" : "No") << endl;
}
