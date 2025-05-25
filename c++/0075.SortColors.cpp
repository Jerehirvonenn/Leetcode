/*
 * Leetcode 75 - Sort Colors (Medium)
 *
 * Problem:
 * Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects
 * of the same color are adjacent, with the colors in the order red, white, and blue.
 *
 * Use integers 0 (red), 1 (white), and 2 (blue) to represent the colors.
 * Do not use the library's sort function.
 *
 * Approach:
 * - Use the Dutch National Flag algorithm (3-pointer method):
 *   - left: next position for 0
 *   - right: next position for 2
 *   - i: current index
 * - Swap 0s to the front, 2s to the back, and leave 1s in place.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums)
    {
        int left = 0;
        int right = nums.size() - 1;
        int i = 0;
        while (i <= right) {
            if (nums[i] == 0) {
                swap(nums[left++], nums[i++]);
            }
            else if (nums[i] == 2) {
                swap(nums[i], nums[right--]);
            }
            else {
                i++;
            }
        }
    }
};

int main(void)
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements (0, 1, 2 only): ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << "Original array: ";
    for (int x : nums) {
        cout << x << " ";
    }
    cout << endl;

    Solution sol;
    sol.sortColors(nums);
    cout << "Sorted array: ";
    for (int x : nums) {
        cout << x << " ";
    }
    cout << endl;
}
