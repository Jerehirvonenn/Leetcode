#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define GREEN "\033[1;32m"
#define RESET "\033[0m "

vector<pair<int, int>> path;

class Solution {
private:
	static bool tryWord(int i, int j, int level, int rows, int cols,
			vector<vector<char>> &board, string &word)
	{
		if (static_cast<unsigned int>(level) == word.size()) {
			return true;
		}
		if (i < 0 || i >= rows || j < 0 || j >= cols || board[i][j] != word[level])
			return false;
		board[i][j] = 0;
		path.emplace_back(i, j);
		if (tryWord(i + 1, j, level + 1, rows, cols, board, word) || 
			tryWord(i, j + 1, level + 1, rows, cols, board, word) ||
			tryWord(i - 1, j, level + 1, rows, cols, board, word) ||
			tryWord(i, j - 1, level + 1, rows, cols, board, word))
			return true;
		board[i][j] = word[level];
		path.pop_back();
		return false;
	}
public:
    static bool exist(vector<vector<char>>& board, string word)
	{
		//optimization, check if board even contain word letters
		unordered_map<int, int> boardFreq;
		unordered_map<int, int> wordFreq;
		//go throught map and check freq
		for (const vector<char> &row : board) {
			for (const char &c : row) {
				boardFreq[c]++;
			}
		}
		//go through word and check if theres not enough letter
		for (const char &c : word) {
			wordFreq[c]++;
			if (wordFreq[c] > boardFreq[c]) {
				return false;
			}
		}
		//if last letter in word is rarer than first reverse the word
		if (boardFreq[word.back()] < boardFreq[word[0]]) {
			reverse(word.begin(), word.end());
		}

		int rows = board.size();
		int cols = board[0].size();
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (board[i][j] == word[0]) {
					if (tryWord(i, j, 0, rows, cols, board, word))
						return true;
				}
			}
		}
		return false;
    }
};

void	printBoard(vector<vector<char>> board)
{
	set<pair<int, int>> pathSet(path.begin(), path.end()); // Store path in a set for fast lookup
	for (unsigned int i = 0; i < board.size(); i++) {
        for (unsigned int j = 0; j < board[0].size(); j++) {
            if (pathSet.count({i, j})) {
                cout << GREEN << board[i][j] << RESET;
            } else {
                cout << board[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main(void)
{
	while (1) {
	vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'},
        {'X', 'J', 'I', 'A'}
    };

	printBoard(board);
	while (!path.empty())
	{
		path.pop_back();
	}
	string search;
	cout << "Word to search: ";
	cin >> search;

	if (Solution::exist(board, search))
		cout << "Found!" << endl;
	else
		cout << "Not found :(" << endl;
	}
}
