/*
 * Leetcode 2389 - Longest Subsequence With Limited Sum (Easy)
 *
 * Problem:
 * Given an integer array nums and an integer array queries, for each query[i],
 * return the maximum length of a subsequence of nums such that the sum of the
 * subsequence is less than or equal to query[i].
 *
 * A subsequence is a sequence that can be derived by deleting some or no elements
 * without changing the order of the remaining elements.
 *
 * Approach:
 * - Sort the nums array to always pick the smallest values first (greedy).
 * - Build prefix sums of nums to quickly compute the total for smallest `k` elements.
 * - For each query, use upper_bound to find how many elements can be included
 *   without exceeding the query value.
 *
 * Time Complexity: O(n log n + m log n)
 *   - O(n log n) for sorting and prefix sum
 *   - O(m log n) for binary search on each query
 *
 * Space Complexity: O(1) extra (excluding output)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int m = queries.size();
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> result(m, 0);
        for (int i = 1; i < n; i++) {
            nums[i] += nums[i - 1];
        }

        for (int i = 0; i < m; i++) {
            auto it = upper_bound(nums.begin(), nums.end(), queries[i]);
            result[i] = distance(nums.begin(), it);
        }
        return result;
    }
};

int main(void)
{
    int n, m;
    cout << "Enter number of elements in nums: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter elements of nums: ";
    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << "Enter number of queries: ";
    cin >> m;
    vector<int> queries(m);
    cout << "Enter elements of queries: ";
    for (int i = 0; i < m; i++) cin >> queries[i];

    Solution sol;
    vector<int> result = sol.answerQueries(nums, queries);
    cout << "Answer: ";
    for (int r : result) cout << r << " ";
    cout << endl;
}
