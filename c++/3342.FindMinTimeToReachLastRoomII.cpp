/**
 * Leetcode 3342 - Find Minimum Time to Reach Last Room II (Medium)
 *
 * Problem:
 * You are given a grid `moveTime` where moveTime[i][j] indicates the earliest time you can step into room (i,j).
 * You start from (0, 0) at t = 0 and must reach (n-1, m-1).
 * Moving to adjacent cells takes alternating time: 1 second, then 2 seconds, then 1, and so on.
 *
 * Return the minimum time required to reach the bottom-right cell.
 *
 * Approach:
 * - Use a Dijkstra's algorithm with a min-heap.
 * - Each state includes current time, cost to move (1 or 2), and position.
 * - At each step, consider the earliest time we can enter the next room, based on moveTime grid.
 * - Use a 3D visited array to track minimal time for each cell and cost state (cost = 1 or 2).
 */

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>
#include <random>

using namespace std;

class Solution {
public:
    int minTimeToReach(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        // Min-heap: (time, cost, (x, y))
        priority_queue<tuple<int, int, pair<int, int>>, vector<tuple<int, int, pair<int, int>>>, greater<>> minHeap;
		// Tracks earliest time visited each cell with either 1 or 2 cost
		// -> could be optimized to calculate the 2 cost on fly to reduce checking
        vector<vector<vector<int>>> visited(rows, vector<vector<int>>(cols, vector<int>(3, INT_MAX)));
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        minHeap.emplace(0, 1, make_pair(0, 0));
        while (!minHeap.empty())
        {
            auto [time, cost, position] = minHeap.top();
            int x = position.first;
            int y = position.second;
            minHeap.pop();

            if (x == rows - 1 && y == cols - 1) {
                return time;
            }

            if (visited[x][y][cost] <= time) {
                continue;
            }
            visited[x][y][cost] = time;

            for (auto [dx, dy] : directions) {
                int nx = x + dx;
                int ny = y + dy;
                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols) {
                    int nextCost = (cost == 1 ? 2 : 1);
                    int nextTime = max(time + cost, grid[nx][ny] + cost);
                    if (visited[nx][ny][nextCost] > nextTime) {
                        minHeap.emplace(nextTime, nextCost, make_pair(nx, ny));
                    }
                }
            }
        }
        return -1;
    }
};

int main(int ac, char **av)
{
	if (ac < 3) {
		cout << "Usage ./a.out <N> <M>\n";
		return 1;
	}
    int n, m;
	n = atoi(av[1]);
	m = atoi(av[2]);

    vector<vector<int>> grid(n, vector<int>(m));
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 9);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            grid[i][j] = dist(gen);

    cout << "Generated grid:\n";
    for (const auto& row : grid) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }

    Solution sol;
    int result = sol.minTimeToReach(grid);
    cout << "Minimum time to reach bottom-right: " << result << endl;
}
