#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
	static void	findBoards(int n, int col, vector<vector<string>> &result, vector<string> &board,
			vector<bool> &rowCheck, vector<bool> &upCheck, vector<bool> &downCheck)
	{
		if (col >= n) {
			result.push_back(board);
			return ;
		}

		for (int i = 0; i < n; i++) {
			if (!rowCheck[i] && !upCheck[n - i + col - 1]
					&& !downCheck[i + col]) {
				rowCheck[i] = true;
				upCheck[n - i + col - 1] = true;
				downCheck[i + col] = true;
				board[i][col] = 'Q';
				
				findBoards(n, col + 1, result, board, rowCheck, upCheck, downCheck);

				rowCheck[i] = false;
				upCheck[n - i + col - 1] = false;
				downCheck[i + col] = false;
				board[i][col] = '.';
			}
		}
	}
public:
    static vector<vector<string>> solveNQueens(int n)
	{
		vector<vector<string>>	result;
		vector<string>			board(n);
		vector<bool>			rowCheck(n, false);
		vector<bool>			upCheck(n * 2 - 1, false);
		vector<bool>			downCheck(n * 2 - 1, false);

		for (int i = 0; i < n; i++) {
			string row(n, '.');
			board[i] = row;
		}

		findBoards(n, 0, result, board, rowCheck, upCheck, downCheck);
		return result;
    }
};

int main(int ac, char **av)
{
	int N;
	if (ac < 2)
		N = 8;
	else
		N = atoi(av[1]);

	vector<vector<string>> result = Solution::solveNQueens(N);

	for (const auto &board : result)
	{
		for (const auto &row : board)
		{
			cout << row << endl;
		}
		cout << endl;
	}
	cout << "Total solutions: " << result.size() << endl;
}
