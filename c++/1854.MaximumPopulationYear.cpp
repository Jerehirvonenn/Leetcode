/*
 * Leetcode 1854 - Maximum Population Year (Easy)
 *
 * Problem:
 * Given a 2D integer array logs where logs[i] = [birthi, deathi] represents birth and death years of the ith person.
 * Population of year x is the number of people alive in year x.
 * A person is counted in year x if x is in [birthi, deathi - 1].
 * Return the earliest year with the maximum population.
 *
 * Approach:
 * - Use a difference array technique for years from 1950 to 2050.
 * - Increment population at birth year, decrement at death year.
 * - Compute prefix sums to get population for each year.
 * - Track the year with maximum population.
 *
 * Time Complexity: O(n + 101)
 * Space Complexity: O(101)
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    const int offset = 1950;
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> pop(101, 0);
        for (const auto& log : logs) {
            pop[log[0] - offset]++;
            pop[log[1] - offset]--;
        }

        int curPop = 0;
        int maxPop = 0;
        int result = 0;
        for (int i = 0; i < 101; i++) {
            curPop += pop[i];
            if (curPop > maxPop) {
                maxPop = curPop;
                result = i + offset;
            }
        }
        return result;
    }
};

int main(void)
{
    Solution solution;
    int n;
    cout << "Enter number of logs: ";
    cin >> n;

    vector<vector<int>> logs(n, vector<int>(2));
    cout << "Enter birth and death years for each person:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> logs[i][0] >> logs[i][1];
    }

    int year = solution.maximumPopulation(logs);
    cout << "Earliest year with maximum population: " << year << endl;
}
