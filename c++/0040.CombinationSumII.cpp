#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
	static void	getSum(int start, int target, vector<int> &current,
			vector<vector<int>> &result, vector<int> &nums)
	{
		if (target == 0) {
			result.push_back(current);
			return ;
		}

		for (int i = start; i < nums.size(); i++) {
			if (target - nums[i] < 0) {
				return;
			}
            if (i > start && nums[i] == nums[i- 1]) {
                continue ;
            }

			current.push_back(nums[i]);
			getSum(i + 1, target - nums[i], current, result, nums);
			current.pop_back();
		}
	}
public:
    static vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
	{
		sort(candidates.begin(), candidates.end());
		vector<vector<int>>	result;
		vector<int>			current;
        result.reserve(100);
        current.reserve(30);

		if (target < candidates[0])
			return result;
		getSum(0, target, current, result, candidates);

		return result;
    }
};

int main(int ac, char **av)
{
	if (ac < 3)
		return 1;

	ac--;
	av++;
	vector<int> candidates(ac - 1, 0);
	for (int i = 0; i < ac - 1; i++) {
		candidates[i] = atoi(av[i]);
	}
	int target = atoi(av[ac - 1]);

	auto result = Solution::combinationSum2(candidates, target);

	for (const auto &vec : result)
	{
		for (const auto &ele : vec)
		{
			cout << ele << " ";
		}
		cout << endl;
	}
}
