/*
1493. Longest Subarray of 1's After Deleting One Element
----------------------------------------------------------
You are given a binary array nums (only 0s and 1s).
You must delete exactly one element from the array.

Return the length of the longest non-empty subarray that contains only 1's 
after performing the deletion.

Approach:
- Use a sliding window with two pointers (left and right).
- Track the number of zeroes in the current window.
- Shrink the window from the left if there is more than one zero.
- For every valid window (with at most one zero), update the max length.
- The result is the length of the window minus one (since we must delete one element).
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zeroes = 0;
        int biggest = 0;
        int left = 0;
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) {
                zeroes++;
            }
            while (zeroes > 1) {
                if (nums[left++] == 0) {
                    zeroes--;
                }
            }
            biggest = max(biggest, right - left);
        }
        return biggest;
    }
};

int main(void)
{
    int n;
    cout << "Enter number of elements in the binary array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " elements (0 or 1): ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    Solution sol;
    int result = sol.longestSubarray(nums);
    cout << "Longest subarray of 1's after deleting one element: " << result << endl;
}
