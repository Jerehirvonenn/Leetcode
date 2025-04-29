#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k)
    {
        int biggest = *max_element(nums.begin(), nums.end());
        const unsigned int size = nums.size();

        size_t result = 0;
        int currentK = 0;
        int left = 0;
        for (int right = 0; right < size; right++)
        {
            if (nums[right] ==  biggest) {
                currentK++;
            }
            while (currentK >= k)
            {
                if (nums[left] == biggest) {
                    currentK--;
                }
                result += size - right;
                left++;
            }
        }
        return result;
    }
};

int main(void)
{
    Solution sol;

    vector<pair<vector<int>, int>> testCases = {
        {{1, 3, 2, 3, 3}, 2},
        {{1, 1, 1, 1, 1}, 1},
        {{1, 2, 3, 4, 5}, 1},
        {{5, 5, 5, 5, 5}, 3},
        {{2, 2, 1, 2, 2}, 3}
    };

    for (size_t i = 0; i < testCases.size(); ++i)
	{
        vector<int> nums = testCases[i].first;
        int k = testCases[i].second;
        long long result = sol.countSubarrays(nums, k);
        cout << "Test case " << i + 1 << ": Result = " << result << endl;
    }
}
