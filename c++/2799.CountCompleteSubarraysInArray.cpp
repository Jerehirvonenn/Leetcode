#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int countCompleteSubarrays(vector<int>& nums)
    {
        unordered_map<int, int>	freq;
        unordered_set<int>		seen;
        int						dist = 0;

        for (int num : nums) {
            if (seen.insert(num).second)
                dist++;
        }

        int left = 0, current = 0, result = 0;
        for (int right = 0; right < nums.size(); right++) {
            if (++freq[nums[right]] == 1) {
                current++;
            }
            while (current >= dist)
			{
                result += nums.size() - right;
                if (--freq[nums[left]] == 0) {
                    current--;
                }
                left++;
            }
        }
        return result;
    }
};

int main(void)
{
    Solution sol;
    vector<int> nums = {1898, 370, 822, 1659, 1360, 128, 370, 360, 261, 1898};

    int result = sol.countCompleteSubarrays(nums);
    cout << "Number of complete subarrays: " << result << endl;
}
