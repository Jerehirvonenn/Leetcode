/*
 * Leetcode 905 - Sort Array By Parity (Easy)
 *
 * Problem:
 * Given an integer array nums, move all the even integers at the beginning of the array
 * followed by all the odd integers.
 * Return any array that satisfies this condition.
 *
 * Approach:
 * - Use two pointers: one starting from the beginning (`even`) and one from the end (`odd`).
 * - Traverse the array:
 *   - If current element is even, swap it to the `even` position and increment `even`.
 *   - If current element is odd, swap it to the `odd` position and decrement `odd`.
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
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int even = 0;
        int odd = n - 1;
        for (int i = 0; i <= odd; i++) {
            if (nums[i] % 2 == 0)
                swap(nums[i], nums[even++]);
            else {
                swap(nums[i], nums[odd--]);
                i--;
            }
        }
        return nums;
    }
};

int main(void)
{
    Solution solution;
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the array elements:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    vector<int> result = solution.sortArrayByParity(nums);
    cout << "Array after sorting by parity:" << endl;
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
}
