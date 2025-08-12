/*
 * Leetcode 1877 - Minimize Maximum Pair Sum in Array (Medium)
 *
 * Problem:
 * The pair sum of a pair (a, b) is equal to a + b.
 * The maximum pair sum is the largest pair sum among all pairs.
 *
 * Given an array nums of even length n, pair up the elements of nums into n / 2 pairs such that:
 * - Each element of nums is in exactly one pair.
 * - The maximum pair sum is minimized.
 *
 * Return the minimized maximum pair sum after optimally pairing the elements.
 *
 * Approach:
 * - Sort the array in ascending order.
 * - Pair the smallest element with the largest, second smallest with second largest, and so on.
 * - For each pair, calculate the sum and track the maximum pair sum.
 * - This greedy approach ensures the minimized maximum pair sum.
 *
 * Time Complexity: O(n log n) due to sorting.
 * Space Complexity: O(1) (in-place sorting, ignoring input storage).
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size() - 1;
        int biggest = 0;
        while (left < right) {
            biggest = max(biggest, nums[left++] + nums[right--]);
        }
        return biggest;
    }
};

int main(void)
{
    Solution solution;
    int n;
    cout << "Enter the number of elements in the array (even number): ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int minMaxPairSum = solution.minPairSum(nums);
    cout << "Minimized maximum pair sum: " << minMaxPairSum << endl;
}
