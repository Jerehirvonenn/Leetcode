/*
 * Leetcode 561 - Array Partition (Easy)
 *
 * Problem:
 * Given an array `nums` of `2n` integers, group them into `n` pairs
 * to maximize the sum of `min(a_i, b_i)` for all pairs.
 *
 * Approach:
 * - Sort the array in non-decreasing order.
 * - After sorting, the optimal pairs are adjacent elements `(nums[i], nums[i+1])`.
 * - The minimum of each pair will be the element at the even index.
 * - Sum all the elements at the even indices to get the maximized sum.
 *
 * Time Complexity: O(N log N) due to sorting.
 * Space Complexity: O(1) (or O(log N) depending on sort implementation).
 */

#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& n) {
        sort(n.begin(), n.end());
        int r = 0;
        for(int i = 0; i < n.size(); i += 2) {r += n[i];}
        return r;
    }
};

int main(void)
{
    Solution solution;
    
    // Example 1
    vector<int> nums1 = {1, 4, 3, 2};
    cout << "Input: {1, 4, 3, 2}" << endl;
    int sum1 = solution.arrayPairSum(nums1);
    cout << "Maximized sum: " << sum1 << endl; // Expected: 4

    cout << "--------------------" << endl;

    // Example 2
    vector<int> nums2 = {6, 2, 6, 5, 1, 2};
    cout << "Input: {6, 2, 6, 5, 1, 2}" << endl;
    int sum2 = solution.arrayPairSum(nums2);
    cout << "Maximized sum: " << sum2 << endl; // Expected: 9
}
