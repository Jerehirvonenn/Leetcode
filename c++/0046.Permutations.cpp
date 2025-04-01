#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
	static void	createPerm(int level, vector<bool> &used, vector<vector<int>> &result,
			vector<int> &current, int &len, vector<int> &nums)
	{
		if (level == len) {
			result.push_back(current);
			return ;
		}

		for (int i = 0; i < len; i++) {
			if (!used[i]) {
				used[i] = true;
				current[level] = nums[i];
				createPerm(level + 1, used, result, current, len, nums);
				used[i] = false;
			}
		}
	}
public:
	static vector<vector<int>> permute(vector<int>& nums)
	{
		int len = nums.size();
		int maxSize = 1;
		for (int i = len; i > 1; i--) {
			maxSize *= i;
		}
		cout << maxSize << endl;

		vector<vector<int>> result;
		result.reserve(maxSize);
		vector<int>			current(len);
		vector<bool>		used(len, 0);

		createPerm(0, used, result, current, len, nums);

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

	auto result = Solution::permute(input);
	for (const auto& row : result) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}
