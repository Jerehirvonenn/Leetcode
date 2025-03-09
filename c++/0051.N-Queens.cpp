#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

class Solution
{
private:
	static void	findBoards(int n, int col, vector<vector<string>> &result, vector<string> &board,
			bitset<50>  &rowCheck, bitset<100> &upCheck, bitset<100> &downCheck)
	{
		if (col >= n) {
			result.push_back(board);
			return ;
		}

		for (int i = 0; i < n; i++) {
			if (!rowCheck[i] && !upCheck[n - i + col - 1]
					&& !downCheck[i + col]) {
				auto &cell = board[i][col];
				rowCheck[i] = true;
				upCheck[n - i + col - 1] = true;
				downCheck[i + col] = true;
				cell = 'Q';

				findBoards(n, col + 1, result, board, rowCheck, upCheck, downCheck);

				rowCheck[i] = false;
				upCheck[n - i + col - 1] = false;
				downCheck[i + col] = false;
				cell = '.';
			}
		}
	}
public:
    static vector<vector<string>> solveNQueens(int n)
	{
		vector<vector<string>>	result;
		vector<string>			board(n);
		bitset<50>				rowCheck;
		bitset<100>				upCheck;
		bitset<100>				downCheck;

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

	/*
	for (const auto &board : result)
	{
		for (const auto &row : board)
		{
			cout << row << endl;
		}
		cout << endl;
	}*/
	cout << "Total solutions: " << result.size() << endl;
}
