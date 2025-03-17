#include <iostream>
#include <vector>
#include <unordered_map>

class Solution
{
	public:
		static bool divideArray(std::vector<int>& nums)
		{
			std::unordered_map<int, int> used;

			for (const auto &num : nums) {
				used[num]++;
			}

			for (const auto &[key, value] : used) {
				if (value % 2 != 0) {
					return false;
				}
			}
			return true;
		}
};

int main(int ac, char **av)
{
	if (ac < 3 || ac % 2 != 1)
		return 1;
	ac--;
	av++;

	std::vector<int> input(ac);
	for (int i = 0; i < ac; i++) {
		input[i] = atoi(av[i]);
	}

	if (Solution::divideArray(input)) {
		std::cout << "True" << std::endl;
	}
	else {
		std::cout << "false" << std::endl;
	}
}
