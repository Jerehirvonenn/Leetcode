/*
 * Leetcode 3355 - Zero Array Transformation I (Medium)
 *
 * Problem:
 * You are given an integer array nums of length n and a 2D array queries, where queries[i] = [li, ri].
 * For each queries[i]:
 *   - Select a subset of indices within the range [li, ri] in nums.
 *   - Decrement the values at the selected indices by 1.
 * Return true if it is possible to transform nums into a Zero Array after processing all the queries,
 * otherwise return false.
 *
 * Approach:
 * - Use a difference array (prefix sum) to efficiently track how many times each index can be decremented.
 * - Iterate over the nums array and check if any element is greater than the total allowed decrements at that index.
 *
 * Time Complexity: O(n + q)
 * Space Complexity: O(n)
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries)
    {
        int size = nums.size();
        vector<int> deductable(size + 1, 0);
        
        for (const vector<int> &current : queries) {
            deductable[current[0]]++;
            deductable[current[1] + 1]--;
        }

        int total = 0;
        for (int i = 0; i < size; i++) {
            total += deductable[i];
            if (nums[i] > total) {
                return false;
            }
        }
        return true;
    }
};

int main(void)
{
    int n, q;
    cout << "Enter size of array and number of queries: ";
    cin >> n >> q;

    vector<int> nums(n);
    cout << "Enter " << n << " elements of the array:\n";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    vector<vector<int>> queries(q, vector<int>(2));
    cout << "Enter " << q << " queries (each with 2 indices li and ri):\n";
    for (int i = 0; i < q; ++i) {
        cin >> queries[i][0] >> queries[i][1];
    }

    cout << "\nOriginal array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << "\n";

    Solution sol;
    bool result = sol.isZeroArray(nums, queries);

    cout << "Can be transformed to zero array? " << (result ? "Yes" : "No") << endl;
}
