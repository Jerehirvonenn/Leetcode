/*
 * Leetcode 238 - Product of Array Except Self (Medium)
 *
 * Problem:
 * Given an integer array nums, return an array answer such that answer[i]
 * is equal to the product of all the elements of nums except nums[i].
 *
 * You must solve it without using division and in O(n) time.
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
 *
 * Approach:
 * - First pass: Compute prefix product for each index (excluding current).
 * - Second pass (in reverse): Multiply each index with running suffix product.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 1);
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            prefix[i] *= suffix;
            suffix *= nums[i];
        }
        return prefix;
    }
};

int main(void)
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
		cin >> nums[i];

    Solution sol;
    vector<int> result = sol.productExceptSelf(nums);

    cout << "Product of array except self: ";
    for (int val : result)
		cout << val << " ";
    cout << endl;
}
