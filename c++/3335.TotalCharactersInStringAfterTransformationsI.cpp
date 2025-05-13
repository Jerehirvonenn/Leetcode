/* Leetcode 3335 - Total Characters in String After Transformations I (Medium)
 *
 * Problem:
 * Given a string s and an integer t, representing the number of transformations to perform.
 * Each transformation modifies every character in s as follows:
 * - If the character is 'z', replace it with the string "ab"
 * - Otherwise, replace it with the next character in the alphabet (e.g., 'a' → 'b')
 *
 * Return the length of the resulting string after exactly t transformations,
 * modulo 10^9 + 7.
 *
 * Approach:
 * - Use a frequency array to count occurrences of each character ('a' to 'z')
 * - For each transformation:
 *     - Characters from 'a' to 'y' shift to the next character
 *     - 'z' becomes 'a' and 'b'
 * - Avoids building actual strings to handle large t efficiently
 *
 * Time Complexity: O(t * 26) = O(t)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
private:
    const int MOD = 1e9 + 7;
public:
    int lengthAfterTransformations(string s, int t)
    {
        int freq[26] = {0};
        for (const char c : s) {
            freq[c - 'a']++;
        }

        while (t--)
        {
            int updatedFreq[26] = {0};
            for (int cur = 0; cur < 25; cur++) {
                updatedFreq[cur + 1] = freq[cur];
            }
            updatedFreq[0] = freq[25];
            updatedFreq[1] = (updatedFreq[1] + freq[25]) % MOD;
            for (int i = 0; i < 26; i++) {
                freq[i] = updatedFreq[i];
            }
        }
        int result = 0;
        for (int i = 0; i < 26; i++) {
            result = (result + freq[i]) % MOD;
        }

        return result;
    }
};

int main(int ac, char **av)
{
    if (ac != 3) {
        cerr << "Usage: " << av[0] << " <lowercase_string> <t>" << endl;
        return 1;
    }

    string s = av[1];
    int t = atoi(av[2]);
    for (char c : s) {
        if (c < 'a' || c > 'z') {
            cerr << "Error: Input string must contain only lowercase English letters." << endl;
            return 1;
        }
    }

    Solution solution;
    int result = solution.lengthAfterTransformations(s, t);
    cout << result << endl;
}
