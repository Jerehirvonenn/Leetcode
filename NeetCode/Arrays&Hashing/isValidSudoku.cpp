#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        int n = board.size();
        vector<vector<bool>> rowCheck(9, vector<bool>(9, false));
        vector<vector<bool>> colCheck(9, vector<bool>(9, false));
        vector<vector<bool>> boxCheck(9, vector<bool>(9, false));

        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (board[row][col] == '.') {
                    continue;
                }
                int current = board[row][col] - '1';
                int boxIndex = (row / 3) * 3 + (col / 3);
                if (rowCheck[row][current] ||
					colCheck[col][current] ||
					boxCheck[boxIndex][current]) {
                    return false;
                }
                rowCheck[row][current] = true;
                colCheck[col][current] = true;
                boxCheck[boxIndex][current] = true;
            }
        }
        return true;
    }
};

int main(void)
{
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    Solution solver;
    bool isValid = solver.isValidSudoku(board);
    cout << (isValid ? "Valid Sudoku" : "Invalid Sudoku") << endl;
}

