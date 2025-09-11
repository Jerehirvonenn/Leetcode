/* Leetcode 2616 - Minimize the Maximum Difference of Pairs (Medium)
 *
 * Problem:
 * Given an array of integers `nums` and an integer `p`, form `p` pairs of indices (i, j)
 * such that each index is used at most once, and the maximum absolute difference
 * among those pairs is minimized.
 *
 * Approach:
 * - Sort the array to simplify adjacent pairing.
 * - Use binary search on the answer (max allowed difference).
 * - For each mid, greedily form pairs with difference <= mid.
 * - If we can form at least `p` such pairs, try a smaller difference.
 * - Else, increase the difference.
 *
 * Time Complexity: O(n log n + n log(max(nums)))
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    int n = 0;
    bool    canMakeNPairs(int target, int p, int n, vector<int> &nums) {
        int pairs = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] <= target) {
                if (++pairs >= p)
                    return true;
                i++;
            }
        }
        return pairs >= p;
    }
public:
    int     minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0;
        int right = nums[n - 1] - nums[0];

        while (left < right) {
            int middle = left + (right - left) / 2;
            if (canMakeNPairs(middle, p, n, nums)) {
                right = middle;
            }
            else {
                left = middle + 1;
            }
        }
        return left;
    }
};

int main(void)
{
    Solution sol;

    vector<int> nums1 = {10, 1, 2, 7, 1, 3};
    int p1 = 2;
    cout << "Minimize Max for nums1: " << sol.minimizeMax(nums1, p1) << endl;

    vector<int> nums2 = {1, 3, 6, 19, 20};
    int p2 = 2;
    cout << "Minimize Max for nums2: " << sol.minimizeMax(nums2, p2) << endl;

    vector<int> nums3 = {4, 2, 1, 2};
    int p3 = 1;
    cout << "Minimize Max for nums3: " << sol.minimizeMax(nums3, p3) << endl;
}
