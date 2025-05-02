#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    static string pushDominoes(string dominoes)
	{
        char prev = '.';
        int streak = 0;
        int prevL = 0;
        for (int i = 0; i < dominoes.size(); i++) {
            const char current = dominoes[i];
            if (current == '.') {
                if (prev == 'R') {
                    dominoes[i] = 'R';
                    streak++;
                }
            }
            else if (current == 'R') {
                prev = 'R';
                streak = 0;
            }
            else if (current == 'L') {
                if (prev == 'R') {
                    int half = streak / 2;
                    for (int j = 1; j <= half; ++j) {
                        dominoes[i - j] = 'L';
                    }
                    if (streak % 2 == 1) {
                        dominoes[i - half - 1] = '.';
                    }
                } else {
                    for (int j = prevL; j < i; ++j) {
                        dominoes[j] = 'L';
                    }
                }
                prev = 'L';
                prevL = i + 1;
                streak = 0;
            }
        }
        return dominoes;    
    }
};

int main(int ac, char **av)
{
    if (ac < 2) {
        cout << "Usage: " << av[0] << " <dominoes_string>\n";
        return 42;
    }

    string input = av[1];
	for (const char c : input) {
		if (c != '.' && c != 'L' && c != 'R') {
			cout << "Only '.' 'R' 'L' allowed\n";
			return 42;
		}
	}
    string result = Solution::pushDominoes(input);
    cout << result << "\n";
}
