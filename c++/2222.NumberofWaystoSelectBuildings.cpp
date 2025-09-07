/*
 * Leetcode 2222 - Number of Ways to Select Buildings (Medium)
 *
 * Problem:
 * Given a binary string s representing buildings (0 = office, 1 = restaurant),
 * count the number of ways to select 3 buildings so that no two consecutive
 * selected buildings have the same type.
 *
 * Approach:
 * - Use prefix counts to track how many of the opposite type have appeared before each position.
 * - Use suffix counts to track how many of each type appear after each position.
 * - For each building as the middle selected building, calculate ways combining prefix and suffix.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    long long numberOfWays(string s) {
        int n = s.size();
        vector<long long> prefix(n, 0);

        int office = 0;     //'0'
        int restaurant = 0; //'1'
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                office++;
                prefix[i] = restaurant;
            } else {
                restaurant++;
                prefix[i] = office;
            }
        }

        office = 0;
        restaurant = 0;
        long long result = 0;
        for (int i = n - 1; i > 0; i--) {
            if (s[i] == '0') {
                office++;
                result += restaurant * prefix[i];
            } else {
                restaurant++;
                result += office * prefix[i];
            }
        }
        return result;
    }
};

int main(void)
{
    Solution solution;
    string s;
    cout << "Enter the binary string representing buildings (0=office,1=restaurant): ";
    cin >> s;

    long long ways = solution.numberOfWays(s);
    cout << "Number of valid ways to select buildings: " << ways << endl;
}
