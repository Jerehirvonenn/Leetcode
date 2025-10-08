/* Leetcode 3264 - Final Array State After K Multiplication Operations I (Easy)
 *
 * Problem:
 * You are given an integer array nums, an integer k, and an integer multiplier.
 * Perform k operations. In each operation:
 * - Find the minimum value x in nums. If multiple, pick the one appearing first.
 * - Replace x with x * multiplier.
 *
 * Return the final array state.
 *
 * Approach:
 * - Use a min-heap that stores (value, index) pairs.
 * - Pop the smallest value k times, multiply it, and push back.
 * - At the end, write all final values back to their original indices.
 *
 * Time Complexity: O((n + k) log n)
 * Space Complexity: O(n)
 */

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multi) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        for (int i = 0; i < nums.size(); i++) {
            minHeap.emplace(nums[i], i);
        }

        for (int i = 0; i < k; i++) {
            auto [val, index] = minHeap.top();
            minHeap.pop();

            val *= multi;
            minHeap.emplace(val, index);
        }

        while (!minHeap.empty()) {
            auto [val, index] = minHeap.top();
            minHeap.pop();
            nums[index] = val;
        }
        return nums;
    }
};

int main(void)
{
    Solution sol;
    vector<int> nums = {1, 2, 3};
    int k = 3;
    int multiplier = 2;

    cout << "Orig  array: ";
    for (int val : nums) {
        cout << val << " ";
    }
    cout << endl;
    vector<int> result = sol.getFinalState(nums, k, multiplier);

    cout << "Final array: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
}
