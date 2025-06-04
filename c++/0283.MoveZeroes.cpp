/*
 * Leetcode 283 - Move Zeroes (Easy)
 *
 * Problem:
 * Given an integer array nums, move all 0's to the end of it while maintaining
 * the relative order of the non-zero elements.
 *
 * Constraints:
 * - Must perform the operation in-place
 * - Should not use extra space (no copy of the array)
 *
 * Approach:
 * - Use a two-pointer technique.
 * - Traverse the array and move all non-zero elements to the front using an `insert` pointer.
 * - After placing all non-zero elements, fill the remaining elements with zero.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums)
    {
        int size = nums.size();
        int insert = 0;
        for (int i = 0; i < size; i++) {
            if (nums[i] != 0) {
                nums[insert++] = nums[i];
            }
        }
        while (insert < size) {
            nums[insert++] = 0;
        }
    }
};

int main(void)
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    sol.moveZeroes(nums);

    cout << "Resulting array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}
