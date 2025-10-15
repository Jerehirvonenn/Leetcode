/*
 * Leetcode 807 - Max Increase to Keep City Skyline (Medium)
 *
 * Problem:
 * Given a grid of building heights, find the maximum total height increase
 * possible without changing the city's skyline from any cardinal direction.
 *
 * Approach:
 * - A building's height is constrained by the tallest building in its row
 * and the tallest building in its column. Changing it must not exceed either.
 * - First, pre-calculate the maximum height for each row and each column.
 * - Iterate through the grid. For each building at `grid[r][c]`, its new
 * maximum possible height is the minimum of `max_in_row[r]` and `max_in_col[c]`.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> maxInCol(n, 0);
        vector<int> maxInRow(n, 0);

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                maxInRow[r] = max(maxInRow[r], grid[r][c]);
                maxInCol[c] = max(maxInCol[c], grid[r][c]);
            }
        }

        int result = 0;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                int potential = min(maxInRow[r], maxInCol[c]);
                result += potential - grid[r][c];
            }
        }
        return result;
    }
};

int main(void)
{
    Solution solution;
    
    vector<vector<int>> grid = {
        {3, 0, 8, 4},
        {2, 4, 5, 7},
        {9, 2, 6, 3},
        {0, 3, 1, 0}
    };

    cout << "Input grid:" << endl;
    for (const auto& row : grid) {
        for (int height : row) {
            cout << height << " ";
        }
        cout << endl;
    }

    int totalIncrease = solution.maxIncreaseKeepingSkyline(grid);
    cout << "\nMaximum total increase: " << totalIncrease << endl; // Expected: 35

    return 0;
}
