class Solution {
private:
    int rows;
    int cols;
    int empty;
    int result;

    void traverse(vector<vector<int>> &grid, int y, int x, int steps) {
        if (y < 0 || y >= rows || x < 0 || x >= cols || grid[y][x] == -1)
            return ;
        if (grid[y][x] == 2) {
            if (steps == empty) {
                result++;
                return ;
            }
            return ;
        }
        grid[y][x] = -1;
        traverse(grid, y + 1, x, steps + 1);
        traverse(grid, y - 1, x, steps + 1);
        traverse(grid, y, x + 1, steps + 1);
        traverse(grid, y, x - 1, steps + 1);
        grid[y][x] = 0;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int startX, startY;
        rows = grid.size();
        cols = grid[0].size();
        empty = 1;
        result = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) { empty++; }
                else if (grid[i][j] == 1) {
                    startY = i;
                    startX = j;
                }
            }
        }
        traverse(grid, startY, startX, 0);
        return result;
    }
};