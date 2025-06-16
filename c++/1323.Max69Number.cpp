/*
 * Leetcode 1323 - Maximum 69 Number (Easy)
 *
 * Problem:
 * You are given a positive integer num consisting only of digits 6 and 9.
 * Return the maximum number you can get by changing **at most one digit** 
 * (change 6 to 9, or 9 to 6).
 *
 * Approach:
 * - Convert the number to a string for easy digit manipulation.
 * - Traverse the string and change the first occurrence of '6' to '9'.
 * - Convert the string back to an integer and return it.
 *
 * Time Complexity: O(n), where n is the number of digits
 * Space Complexity: O(n), due to string storage
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int maximum69Number(int num) {
        string number = to_string(num);
        for (int i = 0; i < number.size(); i++) {
            if (number[i] == '6') {
                number[i] = '9';
                break;
            }
        }
        return stoi(number);
    }
};

int main(void)
{
    Solution sol;
    int num;
    cout << "Enter a number (only digits 6 and 9): ";
    cin >> num;

    int result = sol.maximum69Number(num);
    cout << "Maximum number after one change: " << result << endl;
}
