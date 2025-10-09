/*
 * Leetcode 3443 - Maximum Manhattan Distance After K Changes (Medium)
 *
 * Problem:
 * You are given a string `s` consisting of directions 'N', 'S', 'E', 'W'.
 * Starting at the origin (0, 0), follow the directions in order to move on an infinite grid.
 * You can change at most `k` of the directions to any other direction.
 * 
 * The Manhattan distance between (x, y) and (0, 0) is |x| + |y|.
 * Find the maximum Manhattan distance from the origin that can be achieved
 * at any point while following the directions (after up to k changes).
 *
 * Approach:
 * - Try all 4 possible directional preferences: NE, NW, SE, SW
 * - For each pair, simulate the walk:
 *   - Favor directions matching the pair (count them as beneficial)
 *   - Use up to `k` changes to turn other directions into favored ones
 *   - Track the net movement score using a greedy max-accumulation method
 * - Return the maximum score across all 4 direction pairs
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxDistance(string s, int k) {
        int result = 0;
        char dir[4][2] = {{'N', 'E'}, {'N', 'W'}, {'S', 'E'}, {'S', 'W'}};
        for(auto d: dir) {
            int tmp = k;
            int currentMax = 0;
            for (int i = 0; i < s.size(); i++)
			{
                if (s[i] == d[0] || s[i] == d[1]) {
                    if (tmp-- <= 0)
                        currentMax--;
                    else
                        currentMax++;
                }
                else
                    currentMax++;
                result = max(result, currentMax);
            }
        }
        return result;
    }
};

int main(void) {
    string s;
    int k;
    cout << "Enter string of directions (only N, S, E, W): ";
    cin >> s;

    for (char c : s) {
        if (c != 'N' && c != 'S' && c != 'E' && c != 'W') {
            cout << "Invalid input. Only characters N, S, E, and W are allowed.\n";
            return 1;
        }
    }

    cout << "Enter maximum number of changes (k): ";
    cin >> k;

    Solution sol;
    int maxDist = sol.maxDistance(s, k);
    cout << "Maximum Manhattan Distance: " << maxDist << endl;
}
