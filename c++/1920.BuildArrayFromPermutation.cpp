/*
 * Leetcode 1920 - Build Array from Permutation
 * 
 * Problem:
 * Given a zero-based permutation array 'nums', construct a new array 'ans' such that:
 *     ans[i] = nums[nums[i]]
 * 
 * Constraints:
 *  'nums' is a permutation of integers from 0 to nums.length - 1
 *   All values are unique
 * 
 * Optimized Solution:
 *   encoding both old and new values into nums[i] using:
 *     nums[i] = nums[i] + (nums[nums[i]] % n) * n
 *   Then retrieve final values with:
 *     nums[i] /= n
 * - Time Complexity: O(n)
 * - Space Complexity: O(1) (modifying input in-place)
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int mod = 1024;
public:
	//in place O(1) space
    vector<int> buildArray(vector<int>& nums)
    {
        int size = nums.size();
        mod = size;
        for (int i = 0; i < size; i++) {
            nums[i] = nums[i] + ((nums[nums[i]] % mod) * mod);
        }
        for (int i = 0; i < size; i++) {
            nums[i] /= mod;
        }
        return nums;
    }
	//O(n) time O(n) space
	vector<int> buildArray2(vector<int>& nums)
    {
        int size = nums.size();
        vector<int> result(size, 0);

        for (int i = 0; i < size; i++)
            result[i] = nums[nums[i]];
        return result;
    }
};

int main(void)
{
    Solution sol;
    vector<vector<int>> testCases = {{4, 0, 1, 2, 3},
									{0, 2, 1, 5, 3, 4},
									{5, 4, 3, 2, 1, 0},
									{1, 2, 0},
									{}};

	int i = 1;
	for (auto nums : testCases) {
		cout << "test " << i++ << ": ";
		for (const auto num : nums)
			cout << num << " ";
		cout << "--> ";
		sol.buildArray(nums);
		for (const auto num : nums)
			cout << num << " ";
		cout << "\n";
	}
}
