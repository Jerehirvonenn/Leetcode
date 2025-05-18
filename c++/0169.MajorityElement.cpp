#include <vector>
#include <iostream>

using namespace std;

class Solution
{
	public:
    static int majorityElement(vector<int>& nums)
    {
        unordered_map<int, int> candidates;
        int needed = nums.size() / 2 + 1;

        for (const int num : nums) {
            if (++candidates[num] >= needed)
                return num;
        }
        return -1;
    }
};

int main(int ac ,char **av)
{
	if (ac < 2)
		return 1;

	ac--;
	av++;
	vector<int> candidates(ac, 0);
	for (int i = 0; i < ac; i++) {
		candidates[i] = atoi(av[i]);
	}

	auto result = Solution::majorityElement(candidates);
	cout << result << endl;
}
