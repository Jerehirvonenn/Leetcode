#include <iostream>

using namespace std;

class Solution {
	private:
	static void	checkPalindrome(int left, int right, string &s, int &maxLen, int &start) {
		while (left >= 0 && right < s.size() && s[left] == s[right]) {
			if (right - left + 1 > maxLen) {
				start = left;
				maxLen = right - left + 1;
			}
			left--;
			right++;
		}
	}

	public:
    static string longestPalindrome(string s) {
		int size = s.size();
		int	maxLen = 0;
		int start = 0;
		for (int i = 0; i < size; i++) {
			checkPalindrome(i, i, s, maxLen, start);
			checkPalindrome(i, i + 1, s, maxLen, start);
		}
		return s.substr(start, maxLen);
	}
};

int main(int ac, char **av)
{
	if (ac < 2)
		return 1;

	string input = av[1];
	string result = Solution::longestPalindrome(input);
	cout << result << endl;
}
