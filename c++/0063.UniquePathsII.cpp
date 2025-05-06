/*
 * Leetcode 63 - Unique Paths II (Medium)
 *
 * Given a grid with obstacles (1 = blocked, 0 = open), count how many unique paths
 * exist from the top-left to the bottom-right corner. The robot can only move
 * down or right at each step
 *
 * Approach 1:
 *   - Dynamic Programming with grid[0].size extra space
 *   - update cell to 0 if its a rock otherwise keep incresing 
 *     dp[j] from whats left of it
 * Approach 2:
 * - Dynamic Programming (in-place)
 *   - If a cell has an obstacle, set paths to 0
 *   - For all other cells, paths = paths from left + paths from above
 *   - Change first row/col to 1 if reachable 0 if not
 *
 * Time Complexity: O(m * n)
 * Space Complexity: O(1) — in-place DP
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        vector<int> dp(col, 0);

        dp[0] = (obstacleGrid[0][0] == 0) ? 1 : 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0;
                }
                else if (j > 0) {
                    dp[j] += dp[j - 1];
                }
            }
        }
        return dp[col - 1];
    }
	//inplace
    int uniquePathsWithObstacles2(vector<vector<int>>& grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        if (grid[0][0] == 1 || grid[row - 1][col - 1] == 1) {
            return 0;
        }

        bool obstacle = false;
        if (grid[0][0] == 1)
            obstacle = true;
        for (int i = 1; i < row; i++) {
            if (grid[i][0] == 1) {
                obstacle = true;
            }
            grid[i][0] = obstacle ? 0 : 1;

        }
        obstacle = false;
        for (int i = 0; i < col; i++) {
            if (grid[0][i] == 1) {
                obstacle = true;
            }
            grid[0][i] = obstacle ? 0 : 1;
        }

        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                }
                else {
                    grid[i][j] = grid[i][j - 1] + grid[i - 1][j];
                }
            }
        }
        return grid[row - 1][col - 1];
    }
};

int main(void)
{
    Solution sol;

    vector<vector<int>> obstacleGrid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    int result = sol.uniquePathsWithObstacles(obstacleGrid);
    cout << "Unique paths (with obstacles): " << result << endl;
}
