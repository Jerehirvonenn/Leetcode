/* Leetcode 1769 - Minimum Number of Operations to Move All Balls to Each Box (Medium)
 *
 * Problem:
 * You have n boxes represented by a binary string boxes,
 * where '1' indicates a box contains a ball.
 * In one operation, you can move one ball to an adjacent box.
 * Return an array answer where answer[i] is the minimum number of operations to move all balls to box i.
 *
 * Approach:
 * - Use two passes (left to right and right to left).
 * - Track number of balls seen and cumulative steps needed.
 * - Aggregate steps from both directions for each box.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> result(n, 0);

        int steps = 0;
        int balls = 0;
        for (int i = 0; i < n; i++) {
            result[i] += steps;
            balls += boxes[i] - '0';
            steps += balls;
        }

        steps = 0;
        balls = 0;
        for (int i = n - 1; i >= 0; i--) {
            result[i] += steps;
            balls += boxes[i] - '0';
            steps += balls;
        }
        return result;
    }
};

int main(void)
{
    Solution solution;
    string boxes;
    cout << "Enter the boxes string (0s and 1s): ";
    cin >> boxes;

    vector<int> result = solution.minOperations(boxes);
    cout << "Minimum operations to move all balls to each box:" << endl;
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
}
