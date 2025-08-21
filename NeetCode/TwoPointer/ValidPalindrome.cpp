#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s)
    {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            if (!isalnum(s[left]))
                left++;
            else if (!isalnum(s[right]))
                right--;
            else {
                if (tolower(s[left]) != tolower(s[right]))
                    return false;
                left++;
                right--;
            }
        }
        return true;
    }
};

int main() {
    string s;
    getline(cin, s);
    Solution sol;

    if (sol.isPalindrome(s))
        cout << "true\n";
    else
        cout << "false\n";
}
