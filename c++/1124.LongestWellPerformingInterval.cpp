/*
 * Leetcode 1124 - Longest Well-Performing Interval (Medium)
 *
 * Problem:
 * Given an array hours where hours[i] is the number of hours worked on the i-th day,
 * a day is tiring if hours[i] > 8.
 * A well-performing interval is a contiguous interval with more tiring days than non-tiring days.
 * Return the length of the longest well-performing interval.
 *
 * Approach:
 * - Convert the problem into prefix sums with +1 for tiring days and -1 otherwise.
 * - Use a hashmap to store the earliest index of each prefix sum.
 * - If prefix sum > 0 at any index, entire prefix up to that index is valid.
 * - Otherwise, check if prefix sum - 1 occurred earlier to find a longer valid subarray.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();

        unordered_map<int,int> firstSeen;
        int score = 0;
        int longest = 0;
        for (int i = 0; i < n; i++) {
            score += hours[i] > 8 ? 1 : -1;
            if (score > 0) {
                longest = i + 1;
            }
            else if (firstSeen.count(score - 1)) {
                longest = max(longest, i - firstSeen[score - 1]);
            }
            if (!firstSeen.count(score)) {
                firstSeen[score] = i;
            }
        }
        return longest;
    }
};

int main() {
    Solution sol;
    vector<int> hours;
    int n;
    cout << "Enter number of days: ";
    cin >> n;
    cout << "Enter hours worked per day: ";
    for (int i = 0; i < n; i++) {
        int h; cin >> h;
        hours.push_back(h);
    }
    int result = sol.longestWPI(hours);
    cout << "Longest Well-Performing Interval length: " << result << endl;
}
