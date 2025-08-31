/*
 * Leetcode 1991 - Find the Middle Index in Array (Easy)
 *
 * Problem:
 * Given a 0-indexed integer array nums, find the leftmost middleIndex
 * (i.e., the smallest amongst all the possible ones).
 *
 * A middleIndex is an index where:
 *     nums[0] + nums[1] + ... + nums[middleIndex - 1] == nums[middleIndex + 1] +
 *     nums[middleIndex + 2] + ... + nums[nums.length - 1].
 *
 * Notes:
 * - If middleIndex == 0, the left side sum is considered to be 0.
 * - If middleIndex == nums.length - 1, the right side sum is considered to be 0.
 *
 * Return the leftmost middleIndex that satisfies the condition, or -1 if there is no such index.
 *
 * Approach:
 * - Use prefix sum to store left sums.
 * - Traverse from left to right to fill prefix sums.
 * - Then traverse from right to left, tracking right sum dynamically.
 * - If at any index, left sum equals right sum, record the index.
 * - Continue to find the *leftmost* such index by traversing right to left.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 0);

        int sum = 0;
        for (int i = 0; i < n; i++) {
            prefix[i] = sum;
            sum += nums[i];
        }

        sum = 0;
        int result = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (sum == prefix[i]) {
                result = i;
            }
            sum += nums[i];
        }
        return result;
    }
};

int main(void)
{
    Solution solution;
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the array elements:";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int index = solution.findMiddleIndex(nums);
    cout << "Middle Index: " << index << endl;
}
