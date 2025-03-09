#include <iostream>
#include <vector>

using namespace std;

/*
 * probably too much "optimaization" for such
 * small amount of possibilites
 */

class Solution
{
	private:
	static const vector<int> maxPossibleSum;

	static void	findCombination(int level, int start, int k, int target,
			vector<vector<int>> &result, vector<int> &current)
	{
		if (level >= k) {
			if (target == 0) {
				result.push_back(current);
			}
			return; 
		}
		if (target <= 0 || target > maxPossibleSum[k - level]) {
			return ;
		}
		for (int i = start; i <= 10 - k + level; i++) {
			if (i > target) {
				return ;
			}
			current.push_back(i);
			findCombination(level + 1, i + 1, k, target - i, result, current);
			current.pop_back();
		}
	}
	public:
	static vector<vector<int>> combinationSum3(int k, int n)
	{
		vector<vector<int>>	result;
		vector<int>			current;

		findCombination(0, 1, k, n, result, current);

		return result;
    }
};

//maxpossible value ot achieve for remaining slots
const vector<int> Solution::maxPossibleSum = {
	0,
    9,
    17,
    24,
    30,
    35,
    39,
    42,
    44,
    45
};

int main(int ac, char **av)
{
	if (ac < 3)
		return 1;
	int	size = atoi(av[1]);
	int	target = atoi(av[2]);
	cout << "size is " << size << " and target " << target << endl;

	auto result = Solution::combinationSum3(size, target);

	for (const auto &set : result) {
		for (const auto &num : set) {
			cout << num << " ";
		}
		cout << endl;
	}
}
