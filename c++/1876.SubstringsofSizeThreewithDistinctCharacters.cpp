/*
    1876. Substrings of Size Three with Distinct Characters

    A string is good if there are no repeated characters.
    Given a string s, return the number of good substrings of length three in s.

    Approach:
    - Brute force and check that all three chars are unique since substr
	 size 3 is small enought to do so
*/
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.size();
        if (n < 3) {
            return 0;
        }
        int result = 0;
        for (int i = 0; i < n - 2; i++) {
            if (s[i] != s[i + 1] && s[i + 1] != s[i + 2] && s[i] != s[i + 2]) {
                result++;
            }
        }
        return result;
    }
};

int main(void)
{
    string s;
    cout << "Enter a string: ";
    cin >> s;

    Solution sol;
    int res = sol.countGoodSubstrings(s);
    cout << "Number of good substrings of length 3: " << res << endl;
}
