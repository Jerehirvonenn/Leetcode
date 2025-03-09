#include <iostream>
#include <vector>

using namespace std;

class Solution
{
	private:
	static void	findCombination(int start, int k, int target,
			vector<vector<int>> &result, vector<int> &current)
	{
		if (current.size() >= static_cast<unsigned int>(k)) {
			if (target == 0) {
				result.push_back(current);
			}
			return; 
		}

		for (int i = start; i <= 9; i++) {
			current.push_back(i);
			findCombination(i + 1, k, target - i, result, current);
			current.pop_back();
		}
	}
	public:
	static vector<vector<int>> combinationSum3(int k, int n)
	{
		vector<vector<int>>	result;
		vector<int>			current;

		findCombination(1, k, n, result, current);

		return result;
    }
};

int main(int ac, char **av)
{
	if (ac < 3)
		return 1;
	int	size = atoi(av[1]);
	int	target = atoi(av[2]);

	auto result = Solution::combinationSum3(size, target);

	for (const auto &set : result) {
		for (const auto &num : set) {
			cout << num << " ";
		}
		cout << endl;
	}
}
