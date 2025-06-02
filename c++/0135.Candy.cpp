/*
 * Leetcode 135 - Candy (Hard)
 *
 * Problem:
 * There are n children standing in a line.
 * Each child is assigned a rating value given in the integer array ratings.
 * You are giving candies to these children subject to the following requirements:
 *   - Each child must have at least one candy.
 *   - Children with a higher rating get more candies than their neighbors.
 * Return the minimum number of candies you need to distribute.
 *
 * Approach:
 * - Greedy solution with two passes:
 *   1. Left-to-right: If current rating > previous, give one more candy than previous.
 *   2. Right-to-left: If current rating > next, ensure current has more than next (max of current or next + 1).
 * - Sum up the candies for the result.
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
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        vector<int> candies(size, 1);

        for (int i = 1; i < size; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        int result = 0;
        for (int i = size - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
            result += candies[i + 1];
        }
        return result + candies[0];
    }
};

int main(void)
{
    Solution sol;
    int n;
    cout << "Enter the number of children: ";
    cin >> n;

    vector<int> ratings(n);
    cout << "Enter the ratings of the children:\n";
    for (int i = 0; i < n; ++i) {
        cin >> ratings[i];
    }

    int result = sol.candy(ratings);
    cout << "Minimum candies needed: " << result << endl;
}
