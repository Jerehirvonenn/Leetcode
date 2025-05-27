#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
	public:
    static vector<int> majorityElement(vector<int>& nums)
    {
        unordered_map<int, int> candidates;
        vector<int> result;

        int needed = (nums.size() / 3) + 1;

        for (const int num : nums) {
            if (++candidates[num] == needed) {
                result.push_back(num);
            }
        }
        return result;
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

	for (const auto elem : result) {
		cout << elem << " ";
	}
	cout << endl;
}
