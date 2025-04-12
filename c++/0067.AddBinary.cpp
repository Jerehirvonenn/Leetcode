#include <iostream>
#include <string>

class Solution {
public:
	std::string addBinary(std::string a, std::string b)
	{
		int			i = a.size() - 1;
		int			j = b.size() - 1;
		int			carry = 0;
		int			maxSize = std::max(a.size(), b.size()) + 1;;
		std::string	result(maxSize, '0');

		maxSize--;
		while (i >= 0 || j >= 0 || carry)
		{
			int current = carry;
			if (i >= 0) {
				current += a[i--] - '0';
			}
			if (j >= 0) {
				current += b[j--] - '0';
			}
			result[maxSize--] = (current % 2) + '0';
			carry = (current >= 2) ? 1 : 0;
		}
		return result[0] == '0' ? result.substr(1) : result;
    }
};

int main(int ac, char **av)
{
	if (ac < 3)
		return 1;

	try
	{
		std::string a = av[1];
		std::string b = av[2];

		Solution solve;
		std::string result = solve.addBinary(a, b);
		std::cout << result << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
