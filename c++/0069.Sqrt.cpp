#include <iostream>

class Solution
{
	public:
    static int mySqrt(int x)
	{
		if (x == 0 || x == 1)
			return x;

		int left = 0;
		int right = x / 2;
		while (left < right)
		{
			int middle = left + (right - left) / 2;
			long long result = static_cast<long long>(middle) * static_cast<long long>(middle);
			if (result == x)
				return middle;
			else if (result > x)
				right = middle;
			else
				left = middle + 1;
		}
		if (static_cast<long long>(left) * static_cast<long long>(left) > x)
			return left - 1;
		return left;
    }
};

int main(int ac, char **av)
{
	if (ac < 2)
		return 1;
	int input = atoi(av[1]);
	int result = Solution::mySqrt(input);
	std::cout << result << std::endl;
}
