/*
 * Leetcode 860 - Lemonade Change (Easy)
 *
 * Problem:
 * Each lemonade costs $5. Customers pay with $5, $10, or $20 bills.
 * You must give correct change with no initial cash.
 *
 * Given a vector of bills (in order of arrival), return true if it's
 * possible to give change to every customer, otherwise return false.
 *
 * Approach:
 * - Track the number of $5 and $10 bills.
 * - For each bill:
 *     - $5: No change needed, increase count of $5.
 *     - $10: Need to give $5 change. Check availability.
 *     - $20: Prefer giving one $10 + one $5. If not possible, give three $5.
 *       If neither is possible, return false.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills)
    {
        int five = 0;
        int ten = 0;
        for (const int bill : bills)
        {
            if (bill == 5) {
                five++;
            }
            else if (bill == 10) {
                if (five == 0)
					return false;
                five--;
                ten++;
            }
            else if (bill == 20) {
                if (ten > 0 && five > 0) {
                    five--;
                    ten--;
                }
                else if (five >= 3) {
                    five -= 3;
                }
                else {
                    return false;
                }
            }
			else {
				cerr << "Invalid bill value: " << bill << endl;
				return false;
			}
        }
        return true;
    }
};

int main(void)
{
    int n;
    cout << "Enter number of customers: ";
    cin >> n;

    vector<int> bills(n);
    cout << "Enter the bills (5, 10, or 20): ";
    for (int i = 0; i < n; i++) {
        cin >> bills[i];
    }

    Solution solution;
    bool result = solution.lemonadeChange(bills);
    cout << "Can provide correct change to all customers? "
         << (result ? "Yes" : "No") << endl;
}
