/*
 * Leetcode 1732 - Find the Highest Altitude (Easy)
 *
 * Problem:
 * A biker starts at altitude 0 and is given an array gain where gain[i] is the net gain
 * in altitude between point i and point i + 1. Return the highest altitude the biker reaches.
 *
 * Example:
 * Input: gain = [-5, 1, 5, 0, -7]
 * Output: 6
 * Explanation: The altitudes are [0, -5, -4, 1, 1, -6]. The highest is 6.
 *
 * Approach:
 * - Start with current altitude 0.
 * - Iterate through the gain array, maintaining a running sum of altitude.
 * - Update the highest altitude seen so far.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int highest = 0;
        int current = 0;
        for (const int num : gain) {
            current += num;
            highest = max(highest, current);
        }
        return highest;
    }
};

int main(void)
{
    int n;
    cout << "Enter number of gain elements: ";
    cin >> n;

    vector<int> gain(n);
    cout << "Enter gain values: ";
    for (int i = 0; i < n; i++) {
        cin >> gain[i];
    }

    Solution sol;
    int result = sol.largestAltitude(gain);
    cout << "Highest altitude: " << result << endl;
}
