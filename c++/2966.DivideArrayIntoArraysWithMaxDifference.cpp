/*
 * Leetcode 2966 - Divide Array Into Arrays With Max Difference (Medium)
 *
 * Problem:
 * Given an integer array nums of size n where n is a multiple of 3 and a positive integer k,
 * divide nums into n / 3 groups of 3 elements such that the maximum difference in any group is <= k.
 * If such a division is possible, return any valid grouping. Otherwise, return an empty array.
 *
 * Example:
 * Input: nums = [1,3,4,8,7,9], k = 3
 * Output: [[1,3,4],[7,8,9]]
 *
 * Approach:
 * - Sort the array
 * - Greedily form groups of 3 consecutive elements
 * - For each group, check if the max - min <= k
 * - If any group fails the condition, return an empty array
 * - Else, return the list of valid triplets
 *
 * Time Complexity: O(n log n) — sorting
 * Space Complexity: O(1) only return value
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); i += 3) {
            if (nums[i + 2] - nums[i] > k) {
                return {};
            }
            result.push_back({nums[i], nums[i + 1], nums[i + 2]});
        }
        return result;
    }
};

int main(void)
{
    Solution sol;
    vector<int> nums = {1,3,4,8,7,9,3,5,1};
    int k = 2;

    vector<vector<int>> result = sol.divideArray(nums, k);
    if (result.empty()) {
        cout << "[]\n";
    }
	else {
        cout << "[\n";
        for (const auto& group : result)
		{
            cout << "  [";
            for (size_t i = 0; i < group.size(); i++) {
                cout << group[i];
                if (i != group.size() - 1)
					cout << ", ";
            }
            cout << "]\n";
        }
        cout << "]\n";
    }
}
