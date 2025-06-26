/*
 * Leetcode 528 - Random Pick with Weight (Medium)
 *
 * Problem:
 * You are given a 0-indexed array of positive integers w where w[i] describes the weight of the i-th index.
 * Implement the function pickIndex(), which randomly picks an index in the range [0, w.length - 1]
 * and returns it. The probability of picking index i is w[i] / sum(w).
 *
 * Example:
 *   Input: w = [1, 3]
 *   Output: pickIndex() should return 0 with probability 1/4 and 1 with probability 3/4.
 *
 * Approach:
 * - Build a prefix sum array to represent the weight distribution cumulatively.
 * - Generate a random number in range [1, total weight].
 * - Use binary search (lower_bound) to find the corresponding index.
 *
 * Time Complexity:
 * - Constructor: O(n)
 * - pickIndex(): O(log n)
 *
 * Space Complexity: O(n)
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<int> prefix;
    int total;
public:
    Solution(vector<int>& w) {
        total = 0;
        for (int weight : w) {
            total += weight;
            prefix.push_back(total);
        }
        srand(time(0));
    }

    int pickIndex() {
        int rng = rand() % total + 1;
        int left = 0, right = prefix.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (prefix[mid] < rng)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};

int main(void)
{
    vector<int> weights = {1, 3, 5, 3, 1};
    Solution obj(weights);

    cout << "Random picks: ";
    for (int i = 0; i < 5; i++)
        cout << obj.pickIndex() << " ";
    cout << endl;
}
