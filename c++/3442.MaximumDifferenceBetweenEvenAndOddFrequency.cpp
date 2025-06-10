/*
 * Source: 3442. Maximum Difference Between Even and Odd Frequency I (Easy)
 *
 * Problem:
 * You are given a string `s` consisting of lowercase English letters.
 * Your task is to find the maximum difference `diff = freq(a1) - freq(a2)` 
 * between the frequency of characters a1 and a2 in the string such that:
 * - a1 has an odd frequency in the string.
 *   - a2 has an even frequency in the string.
 *
 * Return this maximum difference.
 *
 * Approach:
 * 1. Count the frequency of each character using an unordered_map.
 * 2. Track the maximum frequency among characters that have odd frequencies (highOdd).
 * 3. Track the minimum frequency among characters that have even frequencies (lowEven).
 * 4. Return the difference: highOdd - lowEven.
 * - If no valid a1 or a2 exists, highOdd may be 0 and lowEven may remain INT_MAX, 
 *   resulting in a negative or undefined difference.
 *   5. This is a direct scan with O(n) time complexity and O(1) space (only 26 lowercase letters).
 *
 * Only lowercase 'a' to 'z' characters are accepted as input.
 * expects atleast 1 odd and 1 even freq in each string
*/

#include <iostream>
#include <unordered_map>
#include <climits>
#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
    int maxDifference(const string& s)
	{
        unordered_map<char, int> freq;
        for (const char c : s) {
            freq[c]++;
        }

        int highOdd = 0;
        int lowEven = INT_MAX;
        for (const auto& [key, value] : freq) {
            if (value % 2 == 1) {
                highOdd = max(highOdd, value);
            } else {
                lowEven = min(lowEven, value);
            }
        }

        return highOdd - lowEven;
    }
};

bool isValid(const string& s)
{
    for (char c : s) {
        if (c < 'a' || c > 'z')
            return false;
    }
    return true;
}

int main(int ac, char **av)
{
    Solution sol;

    if (ac < 2) {
        cerr << "Usage: " << av[0] << " <string1> <string2> ...\n";
        return 1;
    }

    for (int i = 1; i < ac; i++) {
        string input = av[i];
        if (!isValid(input)) {
            cout << "Invalid input (only a-z allowed): " << input << endl;
            continue;
        }

        int result = sol.maxDifference(input);
        cout << "String: " << input << " -> Max Difference: " << result << endl;
    }
}
