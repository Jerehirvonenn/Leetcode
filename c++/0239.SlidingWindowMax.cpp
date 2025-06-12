/* Leetcode 239 - Sliding Window Maximum (Hard)
 *
 * Problem:
 * Given an array `nums` and an integer `k`, return a list of the maximum values
 * in each sliding window of size `k` moving from left to right.
 *
 * Approach:
 * - Use a deque to store indices of potential maximums in decreasing order.
 * - Remove elements that are out of the current window or smaller than the current.
 * - The front of the deque always contains the index of the current window's maximum.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(k)
 */

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result;
        if (k >= n) {
            result.push_back(*max_element(nums.begin(), nums.end()));
            return result;
        }
        result.reserve(n - k + 1);
        deque<int> dq;

        for (int i = 0; i < n; i++) {
            // Remove expired indices
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Remove indices with smaller values
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);

            // Add max to result once the first window is filled
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        return result;
    }
};

int main(void)
{
    int n, k;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int& num : nums) {
        cin >> num;
    }

    cout << "Enter window size k: ";
    cin >> k;

    Solution sol;
    vector<int> result = sol.maxSlidingWindow(nums, k);

    cout << "Maximums in each sliding window: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
}
