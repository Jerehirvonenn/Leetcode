#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        unordered_set<int> seen(nums.begin(), nums.end());

        int longest = 0;
        for (const int num : nums) {
            if (!seen.count(num - 1))
            {
                int current = 1;
                while (seen.count(num + current)) {
                    current++;
                }
                longest = max(longest, current);
            }
        }
        return longest;
    }
};

int main(void)
{
    Solution sol;

    vector<vector<int>> testCases = {
        {100, 4, 200, 1, 3, 2},
        {0, 3, 7, 2, 5, 8, 4, 6, 0, 1},
		{9, 1, 4, 7, 3, -1, 0, 5, 8, -2, 6},
        {},
        {5},
        {1, 2, 0, 1}
    };

    for (const auto& nums : testCases) {
        cout << "Input: ";
        for (int n : nums) cout << n << " ";
        cout << "\nLongest Consecutive Sequence: "
			 << sol.longestConsecutive(const_cast<vector<int>&>(nums)) << "\n\n";
    }
}
