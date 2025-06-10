/*
 * Leetcode 746 - Min Cost Climbing Stairs
 *
 * Problem:
 * Given an array <cost> where cost[i] is the cost of stepping on the i-th stair,
 * you can start at either step 0 or step 1 and move up one or two steps at a time
 * Return the minimum cost to reach just beyond the last step
 *
 * Approach:
 * dynamic programming to compute the minimum cost to reach each step
 * At each step i, you can come from either i-1 or i-2:
 *     dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2])
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost)
    {
        int size = cost.size();
        vector<int> dp(size + 1);
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i <= size; i++) {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp.back();
    }
};

int main(void)
{
    Solution sol;
    int n;
    cout << "Enter number of steps: ";
    cin >> n;

    vector<int> cost(n);
    cout << "Enter the cost for each step:\n";
    for (int i = 0; i < n; ++i) {
        cin >> cost[i];
    }

    int result = sol.minCostClimbingStairs(cost);
    cout << "Minimum cost to reach the top: " << result << endl;
}
