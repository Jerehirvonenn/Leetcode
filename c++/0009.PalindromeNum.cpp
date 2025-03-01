#include <iostream>

using namespace std;

class Solution
{
  public:
	bool isPalindrome(int x)
	{
		if (x < 0 || (x % 10 == 0 && x != 0))
		{
			return false;
		}
		long num = (long)x;
		long reverse = 0;
		while (num)
		{
			int digit = num % 10;
			reverse = (reverse * 10) + digit;
			num /= 10;
		}
		return (reverse == (long)x);
	}
};

int main(int ac, char **av)
{
	if (ac != 2)
	{
		cout << "Usage: ./a.out <int>\n";
		return 1;
	}
	try
	{
		int num = stoi(av[1]);
		Solution solve;
		if (solve.isPalindrome(num))
			cout << num << " is Palindrome" << endl;
		else
			cout << num << " iso not Palindrome" << endl;
	}
	catch(exception &e)
	{
		cerr << "Error: " << e.what() << endl;
	}
}
