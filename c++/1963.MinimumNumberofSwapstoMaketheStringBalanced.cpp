/*
 * Leetcode 1963 - Minimum Number of Swaps to Make the String Balanced (Medium)
 *
 * Problem:
 * You are given a 0-indexed string s of even length n.
 * The string consists of exactly n / 2 opening brackets '[' and n / 2 closing brackets ']'.
 * A string is called balanced if:
 * - It is empty.
 * - It can be written as AB, where both A and B are balanced strings.
 * - It can be written as [C], where C is a balanced string.
 * You may swap the brackets at any two indices any number of times.
 * Return the minimum number of swaps to make s balanced.
 *
 * Approach:
 * - Use a two-pointer technique:
 *   - Move through the string, adjusting a balance counter `open`:
 *     - Increment if '[' is found.
 *     - Decrement if ']' is found.
 *   - If the balance goes negative, find the next available '[' from the right side to swap.
 *   - Every such swap increases the result count.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1) (in-place swaps)
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        int left = 0;
        int right = n - 1;
        int open = 0;
        int result = 0;
        while (left < right) {
            if (s[left] == '[') {
                open++;
            }
            else {
                open--;
            }
            if (open < 0) {
                while (left < right && s[right] != '[')
                    right--;
                result++;
                swap(s[left], s[right]);
                open = 1;
            }
            left++;
        }
        return result;
    }
};

int main(void)
{
    Solution solution;
    string s;
    cout << "Enter the string of brackets: ";
    cin >> s;

    int result = solution.minSwaps(s);
    cout << "Minimum number of swaps to balance the string: " << result << endl;
}
