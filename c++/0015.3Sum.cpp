#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    public:
    static vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> result;  

         sort(nums.begin(), nums.end());

         for (int i = 0; i < nums.size(); i++) {
            if (i != 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    while (nums[left] == nums[left - 1] && left < right) {
                        left++;
                    }
                }
                else if (sum < 0) {
                    left++;
                }
                else {
                    right--;
                }
            }
         }
         return result;
    }
};

int main(int ac ,char **av)
{
	if (ac < 2)
		return 1;

	ac--;
	av++;
	vector<int> candidates(ac, 0);
	for (int i = 0; i < ac; i++) {
		candidates[i] = atoi(av[i]);
	}

	auto result = Solution::threeSum(candidates);

	for (const auto &vec : result)
	{
		for (const auto &ele : vec)
		{
			cout << ele << " ";
		}
		cout << endl;
	}
}
