#include <iostream>
#include <vector>

using namespace std;

class Solution
{
	private:
	static void    generateSets(int &result, int level, int size, int current, vector<int> &nums)
    {
        if (level == size) {
            result += current;
            return;
        }
        //skip current
        generateSets(result, level + 1, size, current, nums);
        //include current in subset
        generateSets(result, level + 1, size, current ^ nums[level], nums);
    }

	public:
    static int     subsetXORSum(vector<int>& nums)
    {
        int result = 0;
        int size = nums.size();

        generateSets(result, 0, size, 0, nums);
        return result;
    }
};

int main(int ac, char **av)
{
	if (ac < 2) {
		cout << "Usage: " << av[0] << " <nums1> <num2> <num3> ..." << endl;
		return 42;
	}

	vector<int> nums(ac - 1);
	for (int i = 1; i < ac; i++) {
		nums[i - 1] = stoi(av[i]);
	}

	int result = Solution::subsetXORSum(nums);
	cout << "XOR sum of numbers is " << result << endl;
}
