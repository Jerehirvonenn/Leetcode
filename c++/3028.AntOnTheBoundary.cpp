/*
 * Leetcode 3028 - Ant on the Boundary (Easy)
 *
 * Problem:
 * An ant starts at position 0 on a number line. Given an array of non-zero integers `nums`,
 * the ant moves left (nums[i] < 0) or right (nums[i] > 0) by abs(nums[i]) units per step.
 *
 * After each full move, check if the ant returns to position 0 (the boundary).
 * Return the number of times the ant returns to the boundary throughout the walk.
 *
 * Approach:
 * - Track the current position `pos`.
 * - After each move, if `pos == 0`, increment result.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int pos = 0;
        int result = 0;
        for (const int num : nums) {
            pos += num;
            if (pos == 0) {
                result++;
            }
        }
        return result;
    }
};

int main(void)
{
    int n;
    cout << "Enter number of moves: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the move values (non-zero integers): ";
    for (int i = 0; i < n; i++) cin >> nums[i];

    Solution sol;
    int result = sol.returnToBoundaryCount(nums);
    cout << "Number of times the ant returns to the boundary: " << result << endl;
}
