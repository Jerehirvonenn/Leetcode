#include <vector>
#include <iostream>

using namespace std;

class Solution
{
	public:
    static string reverseWords(string s)
    {
        int size = s.size();
        string result;

        int left = size - 1;

        bool first = true;
        while (left >= 0)
        {
            while (left >= 0 && s[left] == ' ')
                left--;
            if (left < 0)
                break;

            int right = left;
            while (left > 0 && s[left - 1] != ' ')
                left--;

            if (!first)
                result += " ";
            result += s.substr(left, right - left + 1);
            left--;
            first = false;
        }
        return result;
    }
};

int main(int ac, char **av)
{
	if (ac < 2) {
		cout << "Usage: " << av[0] << " 'Reverse To String'" << endl;
		return 42;
	}

	cout << "Word order flipped: " << Solution::reverseWords(av[1]) << endl;
}
