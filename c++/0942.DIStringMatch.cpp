/*
 * Leetcode 942 - DI String Match (Easy)
 *
 * Problem:
 * Given a string `s` of 'I's and 'D's, construct a permutation of integers
 * from `[0, n]` (where n is the length of s) that matches the increasing ('I')
 * or decreasing ('D') pattern specified by `s`.
 *
 * Approach:
 * - Use a greedy approach with two pointers, `low` starting at 0 and `high` at `n`.
 * - These pointers represent the smallest and largest available numbers for the permutation.
 * - Iterate through the string `s`. If the character is 'I', we need an increasing
 * step, so we take the smallest available number (`low++`).
 * - If the character is 'D', we need a decreasing step, so we take the largest
 * available number (`high--`).
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        int lowestPossible = 0;
        int highestPossible = n;

        vector<int> result;
        result.reserve(n + 1);
        for (const char c : s) {
            if (c == 'I') {
                result.push_back(lowestPossible++);
            } else {
                result.push_back(highestPossible--);
            }
        }
        result.push_back(lowestPossible);
        return result;
    }
};

void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

int main(void)
{
    Solution solution;
    string s1 = "IDID";
    string s2 = "III";
    string s3 = "DDI";

    cout << "Input: \"" << s1 << "\"" << endl;
    vector<int> result1 = solution.diStringMatch(s1);
    cout << "Output: ";
    printVector(result1); // Expected: 0 4 1 3 2 (or other valid)

    cout << "--------------------" << endl;

    cout << "Input: \"" << s2 << "\"" << endl;
    vector<int> result2 = solution.diStringMatch(s2);
    cout << "Output: ";
    printVector(result2); // Expected: 0 1 2 3

    cout << "--------------------" << endl;

    cout << "Input: \"" << s3 << "\"" << endl;
    vector<int> result3 = solution.diStringMatch(s3);
    cout << "Output: ";
    printVector(result3); // Expected: 3 2 0 1
}
