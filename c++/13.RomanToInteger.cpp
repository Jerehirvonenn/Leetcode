#include <iostream>

int	checkValue(std::string s, int i)
{
	switch(s[i]) {
		case 'I': return 1;
		case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
	}
}

class Solution
{
	public:
		int romanToInt(std::string s)
		{
			int	result = 0;
			for (int i = 0; s[i]; i++) {
				int value = checkValue(s, i);
				int next = checkValue(s, i + 1);
				if (next > value) {
					result += next - value;
					i++;
				}
				else
					result += value;
			}
			return result;
		}
};

int main(int ac, char **av)
{
	if (ac < 2)
		return 1;
	Solution solve;
	std::string input = av[1];
	int result = solve.romanToInt(input);
	std::cout << input << " value is " << result << std::endl;
}
