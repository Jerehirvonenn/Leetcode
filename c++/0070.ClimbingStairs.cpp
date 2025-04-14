#include <iostream>

class Solution
{
	public:
    static int climbStairs(int n)
	{
		if (n == 1 || n == 2 || n == 3) {
			return n;
		}

		int current = 3;
		int prev = 2;
		int total = 0;
		for (int i = 3; i < n; i++) {
			total = prev + current;
			prev = current;
			current = total;
		}
		return total;
    }
};

int main(int ac, char **av)
{
	if (ac < 2)
		return 1;
	int stairs = atoi(av[1]);
	int result = Solution::climbStairs(stairs);
	std::cout << result << std::endl;
}
