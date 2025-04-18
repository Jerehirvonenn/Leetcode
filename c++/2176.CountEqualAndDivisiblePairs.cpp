#include <iostream>
#include <vector>

using namespace std;

class Solution
{
	public:
    static int countPairs(vector<int>& nums, int k)
    {
        int result = 0;
        unordered_map<int, vector<int>> seen;

        for (int i = 0; i < nums.size(); i++)
        {
            int current = nums[i];
            if (seen.count(current))
            {
                for (const int num : seen[current]) {
                    if (i * num % k == 0)
                        result++;
                }
            }
            seen[current].push_back(i);
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
	int result = Solution::countPairs(input, target);
	cout << "Number if pairs where nums[i] == nums[j] and (i * j) is divisible by " << target << " is " << result << endl;
}
