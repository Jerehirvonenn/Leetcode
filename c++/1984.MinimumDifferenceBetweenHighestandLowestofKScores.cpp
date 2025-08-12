/*
    1984. Minimum Difference Between Highest and Lowest of K Scores
    Solved
    Easy

    Topics: Sorting, Sliding Window

    You are given an integer array nums and an integer k.
    Pick scores of any k students so the difference between highest and lowest is minimized.

    Return the minimum possible difference.

    Approach:
    - Sort the array
    - Use a sliding window of size k and compute min(nums[i + k - 1] - nums[i])
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int result = INT_MAX;
        for (int i = 0; i <= nums.size() - k; i++) {
            result = min(result, nums[i + k - 1] - nums[i]);
        }
        return result;
    }
};

int main(void)
{
    int n, k;
    cout << "Enter number of students: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter scores: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter k: ";
    cin >> k;

    Solution sol;
    int result = sol.minimumDifference(nums, k);
    cout << "Minimum possible difference: " << result << endl;
}
