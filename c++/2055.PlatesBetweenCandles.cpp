/*
 * Leetcode 2055 - Plates Between Candles (Medium)
 *
 * Problem:
 * Given a string s of '*' (plates) and '|' (candles) and queries [left, right],
 * return the number of plates between candles in the substring s[left...right].
 * A plate is between candles if there is at least one candle to
 * its left and right within the substring.
 *
 * Approach:
 * - Precompute next candle index from left to right.
 * - Precompute last candle index from right to left.
 * - Precompute prefix sums of plates.
 * - For each query, find nearest candles inside the range and calculate plates in between.
 *
 * Time Complexity: O(m + q), where m = length of s, q = number of queries
 * Space Complexity: O(m)
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int m = s.size();
        vector<int> result;
        result.reserve(queries.size());
        vector<int> nextCandle(m, -1);
        vector<int> lastCandle(m, -1);
        vector<int> totalPlates(m, 0);

        int next = -1;
        for (int i = m - 1; i >= 0; i--) {
            if (s[i] == '|')
                next = i;
            nextCandle[i] = next;
        }

        next = -1;
        int total = 0;
        for (int i = 0; i < m; i++) {
            if (s[i] == '|')
                next = i;
            else
                total++;
            totalPlates[i] = total;
            lastCandle[i] = next;
        }

        for (const auto &current : queries) {
            int start = nextCandle[current[0]];
            int end = lastCandle[current[1]];
            if (start != -1 && end != -1 && start < end) {
                result.push_back(totalPlates[end] - totalPlates[start]);
            }
			else {
                result.push_back(0);
            }
        }
        return result;
    }
};

int main(void)
{
    Solution solution;
    int q;
    string s;
    cout << "Enter the string of plates (*) and candles (|): ";
    cin >> s;
    cout << "Enter number of queries: ";
    cin >> q;

    vector<vector<int>> queries(q, vector<int>(2));
    cout << "Enter each query (left right):" << endl;
    for (int i = 0; i < q; ++i) {
        cin >> queries[i][0] >> queries[i][1];
    }

    vector<int> answers = solution.platesBetweenCandles(s, queries);
    cout << "Plates between candles for each query:" << endl;
    for (int ans : answers) {
        cout << ans << " ";
    }
    cout << endl;
}
