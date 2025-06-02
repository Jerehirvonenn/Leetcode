#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution
{
public:
    static int longestPalindrome(string s)
    {
        unordered_map<char, int> freq;
        int result = 0;
        int size = s.size();
        for (int i = 0; i < size; i++)
        {
            char current = s[i];
            if (++freq[current] % 2 == 0) {
                result += 2;
            }
        }
        if (size == result) {
            return result;
        } else {
            return result + 1;
        }
    }
};

int main(int ac, char **av)
{
    if (ac != 2) {
        cout << "Usage: " << av[0] << " <string>\n";
        return 1;
    }

    string input = av[1];
    int length = Solution::longestPalindrome(input);
    cout << "Longest palindrome length: " << length << endl;
}
