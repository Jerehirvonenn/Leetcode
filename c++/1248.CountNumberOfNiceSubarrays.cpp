/* Source: 1248. Count Number of Nice Subarrays
 * Difficulty: Medium
 *
 * Problem:
 * Given an array of integers `nums` and an integer `k`, 
 * return the number of continuous subarrays that contain exactly `k` odd numbers.
 *
 * Approach:
 * Sliding window with two pointers. Count how many subarrays end at each `right` index
 * where exactly `k` odds are in the window. Track how many even numbers are 
 * directly before the leftmost odd in a valid window to compute contribution.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k)
	{
        int n = nums.size();
        int left = 0;
        int odds = 0;
        int result = 0;
        int add = 0;
        for (int right = 0; right < n; right++)
		{
            if (nums[right] % 2 == 1) {
                odds++;
                add = 0;
            }
            else {
                result += add;
            }
            while (odds == k) {
                result++;
                if (nums[left++] % 2 == 1) {
                    odds--;
                }
                add++;
            }
        }
        return result;
    }
};

int main(void)
{
    Solution sol;
    vector<int> nums;
    int k, n;

    cout << "Enter the size of the array: ";
    cin >> n;

    cout << "Enter the array elements: ";
    nums.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << "Enter the value of k: ";
    cin >> k;
    int result = sol.numberOfSubarrays(nums, k);
    cout << "Number of nice subarrays: " << result << endl;
}
