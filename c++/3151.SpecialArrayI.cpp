#include <iostream>
#include <vector>

class Solution
{
public:
    static bool isArraySpecial(std::vector<int>& nums)
    {
        int prev = nums[0] % 2;
        for (int i = 1; i < nums.size(); i++) {
            int current = nums[i] % 2;
            if (prev == current) {
                return false;
            }
            prev = current;
        }
        return true;
    }
};

int main(int ac, char **av)
{
	if (ac < 2)
		return 1;
	ac--;
	av++;

	std::vector<int> input(ac);
	for (int i = 0; i < ac; i++) {
		input[i] = atoi(av[i]);
	}

	if (Solution::isArraySpecial(input)) {
			std::cout << "True" << std::endl;
	}
	else {
		std::cout << "false" << std::endl;
	}
}
