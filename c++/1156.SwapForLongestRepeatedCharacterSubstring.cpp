/* 
 * 1156. Swap For Longest Repeated Character Substring (Medium)
 * Topics: Hash Table, String, Sliding Window
 *
 * You are given a string `text`. You can swap two of the characters in the text.
 *
 * Return the length of the longest substring with repeated characters.
 *
 * Approach:
 * - Count the frequency of each character.
 *   - For each character 'a' to 'z', use a sliding window that allows at most one non-matching character.
 *   - Try to extend the window while keeping count of how many characters
 *     are not equal to the current target character.
 *   - The max length is limited by the total number of available characters for swapping.
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxRepOpt1(string text) {
        unordered_map<char, int> freq;
        for (const char c : text) {
            freq[c]++;
        }

        int biggest = 0;
        int n = text.size();
        for (int i = 0; i < 26; i++) {
            char c = i + 'a';
            int possible = freq[c];
            if (possible < biggest) {
                continue;
            }
            int left = 0;
            int toSwap = 0;
            for (int right = 0; right < n; right++) {
                if (text[right] != c) {
                    toSwap++;
                }
                while (toSwap > 1) {
                    if (text[left++] != c) {
                        toSwap--;
                    }
                }
                biggest = max(biggest, min(possible, right - left + 1));
            }
        }
        return biggest;
    }
};

int main(void)
{
    string text;
    cout << "Enter the string: ";
    cin >> text;

    Solution sol;
    int result = sol.maxRepOpt1(text);
    cout << "Longest repeated character substring (after at most one swap): " << result << endl;
}
