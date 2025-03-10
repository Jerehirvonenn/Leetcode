#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static string convert(string s, int numRows)
	{
		if (numRows == 1 || !*s)
			return s;
		vector<string>	result(numRows, "");

		int	direction = -1;
		int	current = 0;
		for (unsigned int i = 0; i < s.size(); i++)
		{
			result[current] += s[i];
			if (current == 0 || current == numRows - 1)
				direction *= -1;
			current += direction;
		}

		string join = "";
		for (const string &ele : result) {
			join.append(ele); 
		}
		return join;
    }
};

int main(int ac, char **av)
{
	if (ac < 3)
		return 1;

	string input = av[1];
	int row = atoi(av[2]);

	string result = Solution::convert(input, row);
	cout << result << endl;
}
