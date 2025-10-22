class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int y = grid.size();
        if (y == 0) { return 0; }
        int x = grid[0].size();

        int result = 0;
        for (int i = 0; i < x; i++) {
            for (int j = 1; j < y; j++) {
                if (grid[j][i] <= grid[j - 1][i]) {
                    result += grid[j - 1][i] - grid[j][i] + 1;
                    grid[j][i] = grid[j - 1][i] + 1;
                }
            }
        }
        return result;
    }
};