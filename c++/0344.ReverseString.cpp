/*
 * Leetcode 344 - Reverse String (Easy)
 *
 * Problem:
 * Given an array of characters s, reverse the string in-place with O(1) extra memory.
 *
 * Approach:
 * - Use two pointers from start and end, swap and move towards the center until they meet.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            swap(s[left++], s[right--]);
        }
    }
};

int main() {
    Solution solution;
    string input;
    cout << "Enter the string to reverse: ";
    getline(cin, input);

    vector<char> s(input.begin(), input.end());
    solution.reverseString(s);

    cout << "Reversed string: ";
    for (char c : s) {
        cout << c;
    }
    cout << endl;
}
