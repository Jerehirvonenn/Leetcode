/*
 * Leetcode 1432: Max Difference You Can Get From Changing an Integer
 *
 * Problem:
 * You are given an integer num. You may apply the following operation twice:
 * - Pick a digit x (0 <= x <= 9) and replace all occurrences of x with another digit y (0 <= y <= 9).
 * - The resulting number must not have leading zeros and must not be 0.
 * 
 * Goal:
 * Apply the operation two separate times to get two different integers (a and b).
 * Return the maximum possible value of a - b.
 *
 * Approach:
 * - For the maximum number:
 *     Replace the first digit (not '9') with '9', and all its occurrences.
 * - For the minimum number:
 *     Replace the first digit ≥ '2' with:
 *         '1' if it's the leading digit (to avoid leading zero),
 *         otherwise '0'.
 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxDiff(int num) {
        string  max = to_string(num);
        string  min = max;
        int     n = max.size();

        char    looking = 0;
        char    first = min[0];
        for (int i = 0; i < n; i++) {
            if (looking == 0 && min[i] >= '2') {
                looking = min[i];
            }
            if (min[i] == looking) {
                if (first == looking)
                    min[i] = '1';
                else
                    min[i] = '0';
            }
        }
        
        looking = 0;
        for (int i = 0; i < max.size(); i++) {
            if (looking == 0 && max[i] != '9')
                looking = max[i];
            if (max[i] == looking)
                max[i] = '9';
        }
        return stoi(max) - stoi(min);
    }
};

int main(void)
{
    int num;
	cout << "Provide integer: ";
    cin >> num;

    Solution sol;
    cout << sol.maxDiff(num) << endl;
}
