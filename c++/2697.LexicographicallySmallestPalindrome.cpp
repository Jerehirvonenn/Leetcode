/*
 * Leetcode 2697 - Lexicographically Smallest Palindrome (Easy)
 *
 * Problem:
 * You are given a string s consisting of lowercase English letters,
 * and you can replace characters to make it a palindrome.
 * In one operation, you can replace a character with any lowercase English letter.
 * Your task is to make s a palindrome with the minimum number of operations possible.
 * If multiple palindromes can be made with the same number of operations,
 * return the lexicographically smallest one.
 *
 * Approach:
 * - Use two pointers from left and right towards the center:
 *   - If characters at left and right differ, set both to the smaller of the two.
 * - This ensures minimal replacements and the lex smallest result.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1) (in-place)
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                s[left] = s[right] = min(s[left], s[right]);
            }
            left++;
            right--;
        }
        return s;
    }
};

int main(void)
{
    Solution solution;
    string s;
    cout << "Enter the string: ";
    cin >> s;

    string result = solution.makeSmallestPalindrome(s);
    cout << "Lexicographically smallest palindrome: " << result << endl;
}
