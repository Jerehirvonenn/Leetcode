#include <stdio.h>
#include <stdbool.h>

const int	size = 9;

bool isValidSudoku(char board[9][9])
{
	bool row[9][9] = {false};
	bool col[9][9] = {false};
	bool grid[9][9] = {false};

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (board[i][j] == '.')
				continue;
			int num = board[i][j] - '0';
			if (row[i][num])
				return false;
			row[i][num] = true;
			if (col[j][num])
				return false;
			col[j][num] = true;
			int gridToCheck = ((i / 3) * 3)  + (j / 3);
			if (grid[gridToCheck][num])
				return false;
			grid[gridToCheck][num] = true;
		}
	}
	return true;
}

int main()
{
    char board[9][9] = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '9', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'9', '6', '.', '.', '.', '.', '5', '.', '.'},
        {'2', '.', '7', '.', '.', '.', '.', '.', '8'},
        {'3', '.', '.', '.', '4', '.', '.', '.', '9'}
    };
    if (isValidSudoku(board)) {
        printf("Valid Sudoku\n");
    } else {
        printf("Invalid Sudoku\n");
    }

    return 0;
}
