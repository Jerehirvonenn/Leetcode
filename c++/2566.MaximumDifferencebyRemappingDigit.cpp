/*
 * Leetcode 2566 - Maximum Difference by Remapping a Digit (Easy)
 *
 * Problem:
 * You are given an integer num. You know that Bob will sneakily remap one digit (0–9) to another digit.
 * He does this separately for maximizing and minimizing the number.
 *
 * Rules:
 * - When remapping digit d1 to d2, all occurrences of d1 are replaced with d2.
 * - Bob can remap a digit to itself (no change).
 * - Leading zeroes are allowed after remapping.
 * 
 * Task:
 * Return the maximum difference possible between a "maximized" and a "minimized" version of num.
 *
 * Approach:
 * - Convert the number to a string.
 * - For max:
 *     - Replace the first non-9 digit with '9' in all its occurrences.
 * - For min:
 *     - Replace all occurrences of the first digit with '0'.
 * - Convert both back to int and return the difference.
 *
 * Time Complexity: O(n) where n is the number of digits in num
 * Space Complexity: O(n) for the string copies
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int minMaxDifference(int num) {
        string max = to_string(num);
        string min = max;
        int n = max.size();

        char looking = min[0];
        for (int i = 0; i < n; i++) {
            if (min[i] == looking) {
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

int main(void) {
    Solution sol;
    int num;
	cout << "Provide integer: ";
	cin >> num;
    int result = sol.minMaxDifference(num);
    cout << "Max difference after remapping digits of " << num << " is: " << result << endl;
}
