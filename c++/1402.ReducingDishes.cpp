/* Leetcode 1402 - Reducing Dishes (Hard)
 *
 * Problem:
 * A chef has collected data on the satisfaction level of n dishes.
 * Each dish takes 1 unit of time to cook.
 *
 * The like-time coefficient of a dish is defined as:
 *     time[i] * satisfaction[i]
 * where `time[i]` is the time taken to cook that dish including all previous dishes.
 *
 * The chef can cook the dishes in any order and may discard any subset of them.
 * Return the maximum sum of like-time coefficients possible.
 *
 * Example:
 * Input: satisfaction = [-1, -8, 0, 5, -9]
 * Output: 14
 * Explanation: The optimal order is [ -1, 0, 5 ]
 *   (-1 * 1) + (0 * 2) + (5 * 3) = 14
 *
 * Approach:
 * - Sort satisfaction values in ascending order.
 * - Compute total sum and iterate through, skipping sets that reduce overall total.
 * - Use prefix accumulation to maximize the time-weighted satisfaction.
 */

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int total = accumulate(satisfaction.begin(), satisfaction.end(), 0);

        sort(satisfaction.begin(), satisfaction.end());
        int result = 0;
        int added = 0;
        for (const int dish : satisfaction) {
            if (total > 0) {
                result += ++added * dish;
            }
            total -= dish;
        }
        return result;
    }
};

int main() {
    int n;
    cout << "Insert number of dishes: ";
    cin >> n;
    if (n == 0) return 1;

    cout << "Fill the satisfaction vector: ";
    vector<int> satisfaction(n);
    for (int i = 0; i < n; i++) cin >> satisfaction[i];

    Solution sol;
    cout << sol.maxSatisfaction(satisfaction) << "\n";
}

