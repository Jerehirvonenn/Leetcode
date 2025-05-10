/*
 * Leetcode 121 - Best Time to Buy and Sell Stock
 *
 * Problem:
 * Given an array of stock prices, determine the maximum profit
 * from a single buy and sell transaction (buy before sell).
 *
 * Approach:
 * Use a dynamic programming mindset:
 * - Track the minimum price seen so far (best day to buy).
 * - Track the maximum profit that could be made by selling on each day.
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int biggestProfit = 0;
        int smallest = INT_MAX;

        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] <= smallest) {
                smallest = prices[i];
                continue;
            } else {
                int profit = prices[i] - smallest;
                if (profit > biggestProfit) {
                    biggestProfit = profit;
                }
            }
        }
        return biggestProfit;
    }
};

int main(int ac, char **av)
{
    if (ac < 2) {
        cerr << "Usage: " << av[0] << " <num1> <num2> ..." << endl;
        return 1;
    }

    vector<int> prices;
    for (int i = 1; i < ac; i++)
        prices.push_back(atoi(av[i]));

    Solution solution;
    int result = solution.maxProfit(prices);
    cout << "Maximum Profit: " << result << endl;
}
