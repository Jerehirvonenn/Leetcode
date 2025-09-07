/*
 * Leetcode 2200 - Find All K-Distant Indices in an Array (Easy)
 *
 * Problem:
 * You are given a 0-indexed integer array `nums` and two integers `key` and `k`.
 * A k-distant index is an index `i` for which there exists at least one index `j`
 * such that |i - j| <= k and nums[j] == key.
 * Return a list of all such indices, sorted in increasing order.
 *
 * Approach:
 * - Use a prefix sum (difference array) technique to efficiently mark ranges.
 * - For every index where nums[i] == key:
 *     - Mark the range [max(0, i - k), i + k] using +1 and -1 in a helper array.
 * - Then compute a prefix sum to determine which indices fall into at least one such range.
 * - Time Complexity: O(n), Space Complexity: O(n + k)
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> add(n + k + 1, 0);
        for (int i = 0; i < n; i++) {
            if (nums[i] == key) {
                int start = max(0, i - k);
                add[start]++;
                add[i + k + 1]--;
            }
        }

        vector<int> result;
        int balance = 0;
        for (int i = 0; i < n; i++) {
            balance += add[i];
            if (balance > 0) {
                result.push_back(i);
            }
        }
        return result;
    }
};

int main(void)
{
    Solution sol;

    vector<int> nums = {3, 4, 9, 1, 3, 9, 0};
    int key = 9;
    int k = 1;

    vector<int> result = sol.findKDistantIndices(nums, key, k);
    cout << "K-distant indices: ";
    for (int idx : result) {
        cout << idx << " ";
    }
    cout << endl;
}
