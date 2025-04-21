#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
	static void	getSubsets(int level, vector<vector<int>> &result,
			vector<int> &current, vector<int> &nums)
	{
		if (level == nums.size()) {
			result.push_back(current);
			return ;
		}

		getSubsets(nums.size(), result, current, nums);

		for (int i = level; i < nums.size(); i++) {
			current.push_back(nums[i]);
			getSubsets(i + 1, result, current, nums);
			current.pop_back();
		}
	}
public:
    static vector<vector<int>> subsets(vector<int>& nums)
	{
		vector<vector<int>>	result;
		result.reserve(pow(2, nums.size()));
		vector<int>			current({});
		current.reserve(nums.size());

		getSubsets(0, result, current, nums);

		return result;
    }
};

int main(int ac, char **av)
{
	if (ac < 2)
		return 1;
	ac--;
	av++;

	vector<int> input;
	for (int i = 0; i < ac; i++) {
		input.push_back(atoi(av[i]));
	}
	auto result = Solution::subsets(input);

	for (const auto &set : result) {
		for (const auto &num : set) {
			cout << num << " ";
		}
		cout << endl;
	}
}
