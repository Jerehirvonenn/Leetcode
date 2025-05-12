#include <iostream>

using namespace std;

class Solution
{
	public:
    static bool isPalindrome(string s)
    {
        int left = 0; 
        int right = s.size() - 1;
        while (left < right) {
            if (!isalnum(s[left])) {
                left++;
                continue;
            }
            else if (!isalnum(s[right])) {
                right--;
                continue;
            }
            if (tolower(s[left++]) != tolower(s[right--])) {
                return false;
            }
        }
        return true;
    }
};

int main(int ac, char **av)
{
	if (ac < 2)
		return 1;

	string input = av[1];
	if (Solution::isPalindrome(input)) {
		cout << "Is valid Palindrome\n";
	}
	else {
		cout << "Is not valid Palindrome\n";
	}
}
