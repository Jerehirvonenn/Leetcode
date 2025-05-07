#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>

using namespace std;

class Solution {
public:
    int minTimeToReach(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> minHeap;
        vector<vector<int>> visited(rows, vector<int>(cols, INT_MAX));
        vector<pair<int, int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        minHeap.emplace(0, 0, 0);
        while (!minHeap.empty())
		{
            auto [time, row, col] = minHeap.top();
            minHeap.pop();
            if (row == rows - 1 && col == cols - 1)
				return time;
            if (visited[row][col] < time)
                continue;
            visited[row][col] = time;

            for (auto [dx, dy] : directions) {
                int nx = row + dx;
                int ny = col + dy;
                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols)
				{
                    int waitTime = max(time + 1, grid[nx][ny] + 1);
                    if (waitTime < visited[nx][ny]) {
                        visited[nx][ny] = waitTime;
                        minHeap.emplace(waitTime, nx, ny);
                    }
                }
            }
        }
        return -1;
    }
};

int main(void)
{
	Solution sol;
	vector<vector<vector<int>>> testCases = {
		{{0, 4}, {4, 4}},
		{{0, 0}, {0, 0}},
		{{0, 1, 2}, {2, 3, 4}},
		{{0, 2}, {1, 0}},
		{{0, 1, 2, 3}, {4, 3, 4, 1}, {1, 6, 6, 6}, {1, 2, 2, 1}}
    };

    for (int i = 0; i < testCases.size(); ++i) {
        int result = sol.minTimeToReach(testCases[i]);
        cout << "Test Case #" << i + 1 << ": " << result << endl;
    }
}
