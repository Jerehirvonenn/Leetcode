/*
 * Leetcode 1727 - Largest Submatrix With Rearrangements (Medium)
 *
 * Problem:
 * You are given a binary matrix `matrix` of size m x n, and you may rearrange
 * the columns of the matrix in any order.
 * 
 * Return the area of the largest submatrix within `matrix` where every element
 * is 1 after reordering the columns optimally.
 *
 * Example:
 * Input:
 * [[0,0,1],
 *  [1,1,1],
 *  [1,0,1]]
 *
 * After rearranging columns, the largest submatrix of 1’s has area 4.
 *
 * Approach:
 * - Treat each row as the base of a histogram, where each cell represents
 *   the height of consecutive 1’s up to that row.
 * - For each row, compute cumulative heights:
 *     if matrix[y][x] == 1:
 *         matrix[y][x] += matrix[y - 1][x]
 * - Sort each row in descending order — simulating the optimal column
 *   rearrangement to group tall columns together.
 * - Compute max area as `height * width` across all positions.
 *
 * Time Complexity: O(m * n log n)
 * Space Complexity: O(1) (in-place height accumulation)
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        for (int y = 1; y < rows; y++) {
            for (int x = 0; x < cols; x++) {
                if (matrix[y][x] == 1) {
                    matrix[y][x] += matrix[y - 1][x];
                }
            }
        }

        int result = 0;
        for (int y = 0; y < rows; y++) {
            sort(matrix[y].begin(), matrix[y].end(), greater<int>());
            for (int x = 0; x < cols; x++) {
                result = max(result, matrix[y][x] * (x + 1));
            }
        }
        return result;
    }
};

int main() {
    int m, n;
    cout << "Insert matrix dimensions (rows cols): ";
    cin >> m >> n;
    if (m == 0 || n == 0) return 1;

    cout << "Fill the matrix row by row (0 or 1 values):\n";
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];

    Solution sol;
	cout << sol.largestSubmatrix(matrix) << "\n";
}
