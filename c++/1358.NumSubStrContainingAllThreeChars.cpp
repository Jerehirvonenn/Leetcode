#include <iostream>

class Solution
{
public:
    int numberOfSubstrings(std::string s)
	{
		int			allIncluded = 0;
		int			result = 0;
		int			numLetter[3] = {0, 0, 0};
		int			size = s.size();

		int left = 0;
		for (int right = 0; right < size; right++) {
			char current = s[right];
			if (++numLetter[current % 3] == 1) {
				allIncluded++;
			}

			while (allIncluded == 3) {
				result += size - right;
				char toRemove = s[left];
				if (--numLetter[toRemove % 3] == 0) {
					allIncluded--;
				}
				left++;
			}
		}
		return result;
    }
};

int main(int ac, char **av)
{
	if (ac < 2)
		return 1;

	std::string input = av[1];
	Solution solve;
	int result = solve.numberOfSubstrings(input);

	std::cout << result << std::endl;
}
