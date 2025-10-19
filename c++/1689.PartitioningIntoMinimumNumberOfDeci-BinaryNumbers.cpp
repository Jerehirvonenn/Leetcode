/*
 * Leetcode 1689 - Partitioning Into Minimum Number Of Deci-Binary Numbers (Medium)
 *
 * Problem:
 * Find the minimum number of positive deci-binary numbers (containing only
 * digits 0 or 1) that sum up to a given decimal number string `n`.
 *
 * Approach:
 * - Total number of deci-binary numbers required is determined
 * by the largest digit present in the string `n`.
 * - The answer is simply the maximum digit value in the string.
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        char biggest = '0';
        for (const char c : n) {
            biggest = max(biggest, c);
        }
        return biggest - '0';
    }
};

int main(void)
{
    Solution solution;

    // Example 1
    string n1 = "32";
    cout << "Input: \"" << n1 << "\"" << endl;
    int res1 = solution.minPartitions(n1);
    cout << "Minimum partitions: " << res1 << endl; // Expected: 3

    cout << "--------------------" << endl;

    // Example 2
    string n2 = "82734";
    cout << "Input: \"" << n2 << "\"" << endl;
    int res2 = solution.minPartitions(n2);
    cout << "Minimum partitions: " << res2 << endl; // Expected: 8

    cout << "--------------------" << endl;

    // Example 3
    string n3 = "27346209830709182346";
    cout << "Input: \"" << n3 << "\"" << endl;
    int res3 = solution.minPartitions(n3);
    cout << "Minimum partitions: " << res3 << endl; // Expected: 9

    return 0;
}
