/*
 * Leetcode 643 - Maximum Average Subarray I (Easy)
 *
 * Problem:
 * Given an integer array nums and an integer k, find a contiguous subarray 
 * of length k that has the maximum average value and return that value.
 * Any answer with a calculation error less than 1e-5 will be accepted.
 *
 * Approach:
 * - Use a sliding window of size k
 * - Start by computing the sum of the first k elements
 * - Slide the window through the array:
 *     - Track the maximum sum seen
 * - Return the max sum divided by k as the average
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
    double findMaxAverage(vector<int>& nums, int k)
    {
        double sum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        double biggest = sum;
        for (int i = k; i < nums.size(); i++) {
            sum -= nums[i - k];
            sum += nums[i];
            biggest = max(biggest, sum);
        }
        return biggest / k;
    }
};

int main(void)
{
    int n, k;
    cout << "Enter size of array and value of k: ";
    cin >> n >> k;

    vector<int> nums(n);
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    double result = sol.findMaxAverage(nums, k);
    cout.precision(10);
    cout << "Maximum average subarray of length " << k << " is: " << result << endl;
}
