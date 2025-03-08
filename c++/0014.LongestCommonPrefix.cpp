#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

// ANSI color codes
#define GREEN "\033[32m"
#define RESET "\033[0m"

class Solution
{
	public:
		static string longestCommonPrefix(vector<string>& strs)
		{
			string prefix = strs[0];
			int result = prefix.size();
			for (unsigned int i = 1; i < strs.size(); i++) {
				int j = 0;
				while (prefix[j] && strs[i][j] && prefix[j] == strs[i][j]) {
					j++;
				}
				if (j == 0) {
					return "";
				}
				result = j < result ? j : result;
			}
			return prefix.substr(0, result);
		}
};

void	printWithHighlight(vector<string> &input, string &prefix)
{
	cout << "Longest Prefix for strings: ";
	for (const string &s : input) {
		cout << GREEN << s.substr(0, prefix.size()) << RESET
			<< s.substr(prefix.size()) << " ";
	}
	cout << "is " << GREEN << prefix << RESET << endl;
}

int	main(int ac, char **av)
{
	if (ac < 2)
		return 1;
	vector<string> input;
	for (int i = 1; av[i]; i++)
		input.push_back(av[i]);
	string result = Solution::longestCommonPrefix(input);
	printWithHighlight(input, result);
}
