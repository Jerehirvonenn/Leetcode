#include <iostream>

using namespace std;

// ANSI color codes
#define GREEN "\033[32m"
#define RESET "\033[0m"

class Solution {
public:
    static int strStr(string haystack, string needle)
	{
		size_t index = haystack.find(needle);
		if (index != string::npos)
			return index;
		return -1;
    }
};

int main(int ac, char **av)
{
	if (ac < 3)
		return 1;
	string haystack = av[1];
	string needle = av[2];
	int result = Solution::strStr(haystack, needle);

	if (result == -1) {
		cout << needle << " not found in " << haystack << endl;
		return 2;
	}
	cout << "Found " << GREEN << needle << RESET;
	cout << " in " << haystack.substr(0, result) << GREEN
		<< haystack.substr(result, needle.size()) << RESET
		<< haystack.substr(result + needle.size()) << endl;
}
