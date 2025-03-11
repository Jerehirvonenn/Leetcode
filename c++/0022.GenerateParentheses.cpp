#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
	static void	generate(int n, int open, int closed,
			vector<string> &result, string &current)
	{
		if (current.size() == n * 2) {
			result.push_back(current);
		}

		if (open) {
			current.push_back('(');
			generate(n, open - 1, closed + 1, result, current);
			current.pop_back();
		}
		if (closed) {
			current.push_back(')');
			generate(n, open, closed - 1, result, current);
			current.pop_back();
		}
	}
public:
    static vector<string> generateParenthesis(int n)
	{
		vector<string>	result;
		string 			current = "";

		generate(n, n, 0, result, current);

		return result;
    }
};

int main(int ac, char **av)
{
	if (ac < 2)
		return 1;

	int num = atoi(av[1]);
	auto result = Solution::generateParenthesis(num);
	for (const auto &ele : result) {
		cout << ele << endl;
	}
}
