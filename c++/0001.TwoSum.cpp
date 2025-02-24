#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
  public:
	vector<int> twoSum(vector<int> &nums, int target)
	{
		unordered_map<int, int> seen; // num we see and index;
		int			  size = nums.size();
		for (int i = 0; i < size; i++) {
			int diff = target - nums[i];
			if (seen.find(diff) != seen.end())
				return {seen[diff], i};
			else
				seen[nums[i]] = i;
		}
		return {-1, -1};
	}
};

int main(void)
{
	std::vector<int> nums = {2, 7, 11, 15};
	int				 target = 13;

	Solution sol;
	vector<int> result = sol.twoSum(nums, target);

	if (result[0] != -1)
		std::cout << "Indexes: " << result[0] << ", " << result[1] << std::endl;
	else
		std::cout << "No solution found." << std::endl;
}
