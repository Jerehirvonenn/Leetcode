#include <iostream>
#include <vector>

/* Problem Summary:
 * Given a 2 x n board, count the number of ways to tile it using 2x1 dominoes and
 * "L"-shaped trominoes (shapes can be rotated).
 * Each square must be covered, and tilings are considered different if any
 * pair of adjacent cells is covered differently.
 * Return the result modulo 1e9 + 7.
 * */

using namespace std;

class Solution {
private:
const long mod = 1e9 + 7;
long    recursion(const int n, int level, bool even)
{
    if (level > n) {
        return 0;
    }
    else if (level == n) {
        return even;
    }
    if(even) {
        return (recursion(n, level + 1, true) +
            recursion(n, level + 2, true) +
            recursion(n, level + 2, false) * 2l) % mod;
    }
    else {
        return (recursion(n, level + 1, false) +
                recursion(n, level + 1, true)) % mod;
    }
}
public:
    int numTilings(int n)
    {
        return recursion(n, 0, true);    
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

    return 0;
}

