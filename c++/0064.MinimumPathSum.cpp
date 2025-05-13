/*
 * Leetcode 64 - Minimum Path Sum (Medium)
 *
 * Problem:
 * Given an m x n grid filled with non-negative numbers, find a path from top left to bottom right,
 * which minimizes the sum of all numbers along its path.
 * Note: You can only move either down or right at any point in time.
 *
 * Approaches:
 * 1. Dynamic Programming (In-place):
 *    - Use cumulative sums along the first row and first column.
 *    - Each inner cell takes the min from its top or left neighbor.
 *
 * 2. Min Heap (Dijkstra-like):
 *    - Use a priority queue to expand paths by smallest cost.
 *    - Add right and down neighbors to the queue with updated costs.
 */
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        for (int i = 1; i < cols; i++) {
            grid[0][i] += grid[0][i - 1];
        }
        for (int i = 1; i < rows; i++) {
            grid[i][0] += grid[i - 1][0];
        }

        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[rows - 1][cols - 1];
    }

    int minPathSum_Heap(vector<vector<int>>& grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> minHeap;
        minHeap.emplace(grid[0][0], 0, 0);

        while (!minHeap.empty())
		{
            auto [cost, x, y] = minHeap.top();
            minHeap.pop();

            if (x == rows - 1 && y == cols - 1) {
				return cost;
			}

			if (x + 1 < rows) {
				minHeap.emplace(cost + grid[x + 1][y], x + 1, y);
			}
            if (y + 1 < cols) {
				minHeap.emplace(cost + grid[x][y + 1], x, y + 1);
			}
        }
        return -1;
    }
};

int main(void)
{
    int rows, cols;
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    vector<vector<int>> grid(rows, vector<int>(cols));
    cout << "Enter the grid values row by row:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> grid[i][j];
        }
    }

    Solution sol;
    vector<vector<int>> copyGrid = grid;
    cout << "Min Path Sum (DP):    " << sol.minPathSum(grid) << endl;
    cout << "Min Path Sum (Heap):  " << sol.minPathSum_Heap(copyGrid) << endl;
}
