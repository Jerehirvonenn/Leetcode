/*
 * Leetcode 917 - Reverse Only Letters (Easy)
 *
 * Problem:
 * Given a string s, reverse only the English letters in the string.
 * Non-letter characters remain in the same position.
 *
 * Approach:
 * - Use two pointers from both ends.
 * - Move pointers inward skipping non-letters.
 * - Swap letters when both pointers point to letters.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            if (!isalpha(s[left])) {
                left++;
                continue;
            }
            if (!isalpha(s[right])) {
                right--;
                continue;
            }
            swap(s[left++], s[right--]);
        }
        return s;
    }
};

int main(void) {
    Solution solution;
    string s;
    cout << "Enter the string: ";
    getline(cin, s);

    string result = solution.reverseOnlyLetters(s);
    cout << "Reversed only letters: " << result << endl;
}
