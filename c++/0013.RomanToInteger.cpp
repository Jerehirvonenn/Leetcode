#include <iostream>

int	checkValue(char a)
{
	switch(a) {
		case 'I': return 1;
		case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: throw std::runtime_error("Error: Invalid character");
	}
}

class Solution
{
	public:
		int romanToInt(std::string s)
		{
			int		result = 0;
			int		prev = 0;
			int		adding = 1;
			for (int i = s.size() - 1; i >= 0; i--) {
				int current = checkValue(s[i]);
				if (current == prev && !adding) {
					result -= current;
					adding--;
				}
				else if (prev > current) {
					result -= current;
					adding--;
				}
				else {
					result += current;
					adding = 1;
				}
				if (adding < 0) {
					throw std::runtime_error("Error: Max 1 reducing number in row");
				}
				prev = current;
			}
			return result;
		}
};

int main(int ac, char **av)
{
	if (ac < 2)
		return 1;
	try
	{
		Solution solve;
		std::string input = av[1];
		int result = solve.romanToInt(input);
		std::cout << input << " value is " << result << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
