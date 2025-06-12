/*
 * Leetcode 119 - Pascal's Triangle II (Easy)
 *
 * Problem:
 * Given an integer rowIndex, return the rowIndex-th (0-indexed) row of Pascal's Triangle.
 * In Pascal's Triangle, each number is the sum of the two numbers directly above it.
 * 
 *     0th row:        1
 *     1st row:       1 1
 *     2nd row:      1 2 1
 *     3rd row:     1 3 3 1
 *     4th row:    1 4 6 4 1
 *
 * Approach:
 * - Use a 1D vector dp initialized to be return size filled with 1s
 * - For each row from 2 to rowIndex, update the values from right to left.
 * - Each element dp[j] is updated using:
 *       dp[j] = dp[j] + dp[j - 1];
 * - This uses the previous row's values (still intact on the left) to build the current row.
 * - Right-to-left traversal ensures that values needed for future computations are not overwritten.
 *
 * Time Complexity: O(rowIndex^2)
 * Space Complexity: O(rowIndex)
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> dp(rowIndex + 1, 1);
        for (int i = 2; i <= rowIndex; i++) {
            for (int j = i - 1; j > 0; j--) {
                dp[j] = dp[j] + dp[j - 1];
            }
        }
        return dp;
    }
};

int main(void)
{
    Solution solution;
    int rowIndex;

    cout << "Enter the row index (0-based) for Pascal's Triangle: ";
    cin >> rowIndex;

    vector<int> row = solution.getRow(rowIndex);
    cout << "Pascal's Triangle row " << rowIndex << ":" << endl;
    for (int num : row)
        cout << num << " ";
    cout << endl;
}
