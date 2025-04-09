#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

class Solution
{
	public:
	static int minOperations(vector<int>& nums, int k)
    {
        bitset<101> exist=0;

        int result = 0;
        exist[k] = 1;
        for (const int num : nums)
		{
            if (num < k)
                return -1;
            else if (!exist[num]) {
                exist[num] = 1;
                result++;
            }
        }
        return result;
    }
};

int main(int ac, char **av)
{
	if (ac < 3) {
		cout << "Usage: " << av[0] << " <num1> <num2> ...<numN> <Target>" << endl;
		return 42;
	}

	vector<int> input(ac - 2);
	for (int i = 1; i < ac - 1; i++)
	{
		int num = atoi(av[i]);
		if (num <= 0 || num > 100)
			return 1;
		input[i - 1] = num;
	}
	int target = atoi(av[ac - 1]);
	if (target <= 0 || target > 100)
		return 1;
	int result = Solution::minOperations(input, target);
	cout << "min actions to make array equal to " << target << " is " << result << endl;
}
