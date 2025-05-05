#include <iostream>
#include <vector>

/* Problem Summary:
 * Given a 2 x n board, count the number of ways to tile it using 2x1 dominoes and
 * "L"-shaped trominoes (shapes can be rotated).
 * Each square must be covered, and tilings are considered different if any
 * pair of adjacent cells is covered differently.
 * Return the result modulo 1e9 + 7.
 */

using namespace std;

class Solution {
private:
    const int mod = 1e9 + 7;
public:
    int numTilings(int n)
    {
        vector<long> dp(n + 4);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        for (int i = 4; i <= n; i++) {
            dp[i] = (2 * dp[i - 1] + dp[i - 3]) % mod;
        }
        return dp[n];
    }
};

int main(void)
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    Solution sol;
    int result = sol.numTilings(n);

    cout << "Number of ways to tile a 2x" << n << " board: " << result << endl;
}
