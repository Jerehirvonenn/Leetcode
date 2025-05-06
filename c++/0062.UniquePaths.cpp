/*
 * Leetcode 62 - Unique Paths (Medium)
 *
 * Problem:
 * A robot is placed on an m x n grid at the top-left corner and must reach the bottom-right corner
 * It can only move either right or down at any step
 * Return the total number of unique paths from start to destination
 *
 * Approach:
 * Uses dynamic programming to build up the number of ways to reach each cell
 * Each cell [i][j] can be reached either from the left ([i][j-1]) or from above ([i-1][j]),
 * so the number of paths to [i][j] is the sum of those two values
 * 		grid[i][j] = grid[i][j - 1] + grid[i - 1][j];
 *
 * Time Complexity: O(m * n)
 * Space Complexity: O(m * n)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> grid(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            grid[i][0] = 1;
        }
        for (int i = 0; i < n; i++) {
            grid[0][i] = 1;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                grid[i][j] = grid[i][j - 1] + grid[i - 1][j];
            }
        }
        return grid[m - 1][n - 1];
    }
};

int main(int ac, char **av)
{
	if (ac < 3)
		return 42;
    Solution sol;
    int m = atoi(av[1]);
    int n = atoi(av[2]);

    int result = sol.uniquePaths(m, n);
    cout << "Unique Paths from (0,0) to (" << m-1 << "," << n-1 << ") = " << result << endl;
}
