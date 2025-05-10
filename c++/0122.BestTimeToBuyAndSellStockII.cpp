/*
 * Leetcode 122 - Best Time to Buy and Sell Stock II
 *
 * Problem:
 * Given an array of prices, buy and sell as many times as you want to maximize profit.
 * You must sell before you can buy again.
 *
 * Greedy
 * - Sum all upward price differences: profit += prices[i] - prices[i-1] if increasing.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>
#include <sstream>
#include <limits.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int bought = INT_MAX;

        for (int i = 0; i < prices.size() - 1; i++) {
            int result = prices[i + 1] - prices[i];
            if (result > 0) {
                profit += result;
            }
        }
        return profit;
    }
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <num1> <nums2 ..." << endl;
        return 1;
    }

    vector<int> prices;
    for (int i = 1; i < argc; i++) {
        prices.push_back(atoi(argv[i]));
    }

    Solution solution;
    int result = solution.maxProfit(prices);
    cout << "Maximum Profit: " << result << endl;
}

