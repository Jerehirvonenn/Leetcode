/*
 * Leetcode 2894 - Divisible and Non-divisible Sums Difference (Easy)
 *
 * Problem:
 * You are given positive integers n and m.
 * Define two integers:
 *   - num1: The sum of all integers in the range [1, n] that are NOT divisible by m.
 *   - num2: The sum of all integers in the range [1, n] that ARE divisible by m.
 * Return the result of num1 - num2.
 *
 * Approach:
 * - Iterate from 1 to n.
 * - If a number is divisible by m, subtract it from the result.
 * - If not, add it to the result.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int differenceOfSums(int n, int m)
    {
        int result = 0;
        for (int i = 1; i <= n; i++) {
            if (i % m == 0) {
                result -= i;
            } else {
                result += i;
            }
        }
        return result;
    }
};

int main(void)
{
    int n, m;
    cout << "Enter n (upper bound): ";
    cin >> n;

    cout << "Enter m (divisor): ";
    cin >> m;

    Solution sol;
    int result = sol.differenceOfSums(n, m);
    cout << "Result (non-divisible sum - divisible sum): " << result << endl;
}
