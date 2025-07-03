/*
 * 713. Subarray Product Less Than K (Medium)
 *
 * Given an array of integers nums and an integer k, return the number of
 * contiguous subarrays where the product of all the elements in the subarray
 * is strictly less than k.
 *
 * Approach:
 * - Sliding window to maintain the product of elements in the current window.
 * - If product exceeds or equals k, shrink the window from the left.
 * - Add (right - left + 1) to the result for each step, representing the number
 *   of valid subarrays ending at 'right'.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) {
            return 0;
        }
        int result = 0;
        int left = 0;
        int windowProduct = 1;
        for (int right = 0; right < nums.size(); right++) {
            windowProduct *= nums[right];
            while (windowProduct >= k) {
                windowProduct /= nums[left++];
            }
            result += right - left + 1;
        }
        return result;
    }
};

int main(void)
{
    int n, k;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    cout << "Enter the integer k: ";
    cin >> k;

    vector<int> nums(n);
    cout << "Enter " << n << " elements separated by space:\n";
    for (int& x : nums) {
        cin >> x;
    }

    Solution sol;
    int result = sol.numSubarrayProductLessThanK(nums, k);
    cout << "Number of subarrays with product less than " << k << " is: " << result << "\n";
}
