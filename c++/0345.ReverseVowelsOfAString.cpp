/*
 * Leetcode 345 - Reverse Vowels of a String (Easy)
 *
 * Problem:
 * Given a string s, reverse only the vowels in the string.
 * Vowels are 'a', 'e', 'i', 'o', 'u' in both lowercase and uppercase.
 *
 * Approach:
 * - Use two pointers from both ends.
 * - Move pointers until vowels are found.
 * - Swap vowels.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
private:
    bool isVowel(char c) {
        switch(c) {
            case 'a': case 'e': case 'i': case 'o': case 'u':
            case 'A': case 'E': case 'I': case 'O': case 'U':
                return true;
            default:
                return false;
        }
    }
public:
    string reverseVowels(string s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            while (left < right && !isVowel(s[left])) {
                left++;
            }
            while (left < right && !isVowel(s[right])) {
                right--;
            }
            swap(s[left++], s[right--]);
        }
        return s;
    }
};

int main() {
    Solution solution;
    string s;
    cout << "Enter the string: ";
    getline(cin, s);

    string result = solution.reverseVowels(s);
    cout << "String after reversing vowels: " << result << endl;
}
