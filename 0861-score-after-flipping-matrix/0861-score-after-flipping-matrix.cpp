class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int rows = grid.size();
        if (rows == 0)
            return 0;
        int cols = grid[0].size();

        int result = rows * (1 << (cols - 1));
        for (int col = 1; col < cols; col++) {
            int ones = 0;
            for (int row = 0; row < rows; row++) {
                if (grid[row][0] == grid[row][col])
                    ones++;
            }
            ones = max(ones, rows - ones);
            result += ones * (1 << (cols - col - 1));
        }
        return result;
    }
};