#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
	static bool	canRobKHouses(vector<int> &nums, int k, int middle)
	{
		int count = 0;
		int i = 0;
		int size = nums.size();

		while (i < size)
		{
			if (nums[i] <= middle) {
				count++;
				i += 2;
			}
			else {
				i++;
			}
			if (count >= k)
				return true;
		}
		return false;
	}
public:
    static int		minCapability(vector<int>& nums, int k)
	{
		int		left = 1; //maybe start from min(nums)
		int		right = *max_element(nums.begin(), nums.end());
		int		result = right;

		while (left < right)
		{
			int middle = left + (right - left) / 2;
			if (canRobKHouses(nums, k, middle)) {
				result = middle;
				right = middle;
			}
			else {
				left = middle + 1;
			}
		}
		return result;
    }
};

int main(int ac, char **av)
{
	if (ac < 3)
		return 1;
	ac--;
	av++;

	vector<int> input(ac - 1);
	for (int i = 0; i < ac - 1; i++) {
		input[i] = atoi(av[i]);
	}
	int	k = atoi(av[ac - 1]);

	for (const auto &ele : input) {
			cout << ele << " ";
	}
	cout << "k = " << k << endl;

	int result = Solution::minCapability(input, k);
	cout << result << endl;
}
