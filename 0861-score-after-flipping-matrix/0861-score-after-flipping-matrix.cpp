class Solution {
private:
    int binaryToInt(vector<int> num) {
        int result = 0;
        for (int i = 0; i < num.size(); i++) {
            result = (result * 2) + num[i];
        }
        return result;
    }
public:
    int matrixScore(vector<vector<int>>& grid) {
        int rows = grid.size();
        if (rows == 0)
            return 0;
        int cols = grid[0].size();

        //check rows start with 1
        for (int i = 0; i < rows; i++) {
            if (grid[i][0] == 0) {
                for (int j = 0; j < cols; j++) {
                    grid[i][j] = (grid[i][j] + 1) % 2;
                }
            }
        }

        //if col has more 0 than 1, greedy flip
        for (int col = 0; col < cols; col++) {
            int balance = 0;
            for (int row = 0; row < rows; row++) {
                if (grid[row][col] == 0)
                    balance--;
                else 
                    balance++;
            }

            if (balance >= 0)
                continue ;
            
            for (int row = 0; row < rows; row++) {
                if (grid[row][col] == 0)
                    grid[row][col] = 1;
                else 
                    grid[row][col] = 0;
            }
        }

        int result = 0;
        for (int row = 0; row < rows; row++) {
            result += binaryToInt(grid[row]);
        }
        return result;
    }
};