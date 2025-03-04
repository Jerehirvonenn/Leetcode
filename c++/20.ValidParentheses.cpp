#include <iostream>
#include <stack>
#include <regex>

bool	isOpen(char a)
{
	return (a == '(' || a == '[' || a == '{');
}

bool	isClosed(char a)
{
	return (a == ')' || a == ']' || a == '}');
}

bool	isPair(char a, char b)
{
	switch(a)
	{
		case('{') : return (b == '}');
		case('[') : return (b == ']');
		case('(') : return (b == ')');
		default : return false;
	}
}

class Solution
{
	public:
		bool isValid(std::string s)
		{
			std::stack<char> stack;
			for (unsigned int i = 0; i < s.size(); i++) {
				if (isOpen(s[i])) {
					stack.push(s[i]);
				}
				else if (isClosed(s[i])) {
					if (stack.empty()) {
						return false;
					}
					char a = stack.top();
					stack.pop();
					if (!isPair(a, s[i]))
						return false;
				}
				else {
					throw std::runtime_error("Invalid character");
				}
			}
			return (stack.empty());
		}
};

int main(int ac, char **av)
{
	if (ac < 2)
		return 1;
	try
	{
		std::regex pattern(R"(^[\(\)\{\}\[\]]{0,}$)");
		std::string input = av[1];

		if (!std::regex_match(input, pattern)) {
			std::cout << "Only include (){}[]" << std::endl;
			return 2;
		}
		Solution solve;
		if (solve.isValid(input))
			std::cout << input << " is valid" << std::endl;
		else
			std::cout << input << " is not valid" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
