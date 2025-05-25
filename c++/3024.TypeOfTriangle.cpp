/*
 * Leetcode 3024 - Type of Triangle (Easy)
 *
 * Problem:
 * You are given a 0-indexed integer array nums of size 3 which can form the sides of a triangle.
 * - A triangle is equilateral if it has all sides of equal length.
 * - A triangle is isosceles if it has exactly two sides of equal length.
 * - A triangle is scalene if all its sides are of different lengths.
 * Return a string representing the type of triangle that can be formed or "none" if it cannot form a triangle.
 *
 * Approach:
 * - First, sort the sides to easily apply the triangle inequality check: a + b > c.
 * - Then classify based on equality of elements.
 *
 * Time Complexity: O(1) - Only 3 elements.
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string triangleType(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        if (nums[0] + nums[1] <= nums[2]) {
            return "none";
        }

        if (nums[0] == nums[1] && nums[1] == nums[2]) {
            return "equilateral";
        }
        else if (nums[0] == nums[1] || nums[1] == nums[2]) {
            return "isosceles";
        } 
        return "scalene";
    }
};

int main(void)
{
    vector<int> nums(3);
    cout << "Enter 3 side lengths: ";
    for (int i = 0; i < 3; ++i) {
        cin >> nums[i];
    }

    cout << "Input sides: ";
    for (int n : nums) {
        cout << n << " ";
    }
    cout << endl;

    Solution sol;
    string result = sol.triangleType(nums);
    cout << "Triangle type: " << result << endl;
}
