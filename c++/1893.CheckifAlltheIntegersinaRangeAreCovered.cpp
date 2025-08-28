/*
 * Leetcode 1893 - Check if All the Integers in a Range Are Covered (Easy)
 *
 * Problem:
 * Given a 2D array ranges and two integers left and right,
 * each ranges[i] = [starti, endi] represents an inclusive interval.
 * Return true if every integer in [left, right] is covered by at least one interval.
 *
 * Approach:
 * - Create a boolean vector to mark coverage for each integer in [left, right].
 * - For each range, mark the covered positions.
 * - Check if all positions are covered.
 *
 * Time Complexity: O(m * n), where m = number of ranges, n = size of [left, right]
 * Space Complexity: O(n)
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<bool> covered(right - left + 1, false);
        for (const auto& range : ranges) {
            int start = max(left, range[0]);
            int end = min(right, range[1]);
            for (int j = start; j <= end; j++) {
                covered[j - left] = true;
            }
        }
        for (const bool check : covered) {
            if (!check) {
                return false;
            }
        }
        return true;
    }
};

int main(void)
{
    Solution solution;
    int m, left, right;
    cout << "Enter number of ranges: ";
    cin >> m;
    cout << "Enter left and right bounds: ";
    cin >> left >> right;

    vector<vector<int>> ranges(m, vector<int>(2));
    cout << "Enter each range (start end):" << endl;
    for (int i = 0; i < m; ++i) {
        cin >> ranges[i][0] >> ranges[i][1];
    }

    bool result = solution.isCovered(ranges, left, right);
    cout << (result ? "True" : "False") << endl;
}
