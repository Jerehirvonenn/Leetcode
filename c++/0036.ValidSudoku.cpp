#include <vector>
#include <iostream>

using namespace std;

class Solution
{
	public:
    static bool isValidSudoku(vector<vector<char>>& board)
    {
        vector<vector<bool>> rows(9, vector<bool>(10, false));
        vector<vector<bool>> cols(9, vector<bool>(10, false));
        vector<vector<bool>> box(9, vector<bool>(10, false));

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] == '.') {
                    continue;
                }
                int current = board[i][j] - '0';
                int boxNum = (i / 3) * 3 + (j / 3);
                if (rows[i][current] ||
                    cols[j][current] ||
                    box[boxNum][current]) {
                        return false;
                }
                rows[i][current] = true;
                cols[j][current] = true;
                box[boxNum][current] = true;
            }
        }
        return true;
    }
};

int main(void)
{
	vector<vector<char>> input = {
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

	if (Solution::isValidSudoku(input)) {
		cout << "Is valid\n";
	}
	else {
		cout << "Is not valid\n";
	}
}
