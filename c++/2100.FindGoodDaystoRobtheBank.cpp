/*
 * Leetcode 2100 - Find Good Days to Rob the Bank (Medium)
 *
 * Problem:
 * Given an array security of guards on duty each day and an integer time,
 * find all days i such that:
 * - There are at least `time` days before and after i,
 * - The guards count in the `time` days before i is non-increasing,
 * - The guards count in the `time` days after i is non-decreasing.
 *
 * Approach:
 * - Track non-decreasing streaks from right to left.
 * - Track non-increasing streaks from left to right.
 * - Collect days satisfying both conditions.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <iostream>
#include <vector>
#include <numeric>  // for iota
using namespace std;

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        if (n == 1 && time != 0) {
            return {};
        }
        if (time == 0) {
            vector<int> allDays(n);
            iota(allDays.begin(), allDays.end(), 0);
            return allDays;
        }

        vector<bool> goodDay(n, false);
        int streak = 1;

        // Check for non-decreasing streak from right to left
        for (int i = n - 2; i >= 0; i--) {
            if (security[i] <= security[i + 1]) {
                streak++;
            } else {
                streak = 1;
            }
            if (streak >= time + 1) {  // needs to cover time days after including current
                goodDay[i] = true;
            }
        }

        streak = 1;
        vector<int> result;
        result.reserve(n);

        // Check for non-increasing streak from left to right and combine
        for (int i = 1; i < n; i++) {
            if (security[i] <= security[i - 1]) {
                streak++;
            } else {
                streak = 1;
            }

            if (i >= time && i + time < n && streak >= time + 1 && goodDay[i]) {
                result.push_back(i);
            }
        }
        return result;
    }
};

int main(void)
{
    Solution solution;
    int n, time;
    cout << "Enter number of days: ";
    cin >> n;
    vector<int> security(n);
    cout << "Enter guards on duty each day: ";
    for (int i = 0; i < n; ++i) {
        cin >> security[i];
    }
    cout << "Enter time parameter: ";
    cin >> time;

    vector<int> goodDays = solution.goodDaysToRobBank(security, time);
    cout << "Good days to rob the bank: ";
    for (int day : goodDays) {
        cout << day << " ";
    }
    cout << endl;
}
