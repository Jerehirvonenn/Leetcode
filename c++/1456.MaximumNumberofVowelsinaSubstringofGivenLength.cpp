/*
 * 1456. Maximum Number of Vowels in a Substring of Given Length
 *
 * Approach:
 * We use a fixed-length sliding window of size k.
 * - Count vowels in the first window.
 *   - Slide the window across the string one character at a time:
 *   - Add new right character (if it's a vowel)
 *   - Remove leftmost character from the window (if it's a vowel)
 *   - Track the maximum vowel count found in any window.
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
private:
    bool isVowel(char c) {return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');}
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        int right = 0;
        int vowels = 0;
        while (right < n && right < k) {
            if (isVowel(s[right++]))
                vowels++;
        }
        int longest = vowels;

        while (right < n) {
            if (isVowel(s[right]))
                vowels++;
            if (isVowel(s[right - k]))
                vowels--;
            right++;
            longest = max(longest, vowels);
        }
        return longest;
    }
};

int main(void)
{
    string s;
    int k;

    cout << "Enter string: ";
    cin >> s;

    cout << "Enter k: ";
    cin >> k;

    Solution sol;
    int result = sol.maxVowels(s, k);
    cout << "Maximum number of vowels in any substring of length " << k << ": " << result << endl;
}
