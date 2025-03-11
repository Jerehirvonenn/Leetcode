#include <iostream>

/* Function to calculate num of substring that contain atleast 1 of each a, b and c
 * numLetter to keep track of each and if all of them are 1 >=
 * 		we trigger allIncluded for fast lookup
 * since we looking for atleast 1, num of substring is current + each char not used yet
 * 		example:  a b c c c substrs : abc, abcc, abccc
 */
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
