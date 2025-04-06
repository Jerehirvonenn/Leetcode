#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    public:
    static vector<int> largestDivisibleSubset(vector<int>& nums)
    {
        int n = nums.size();
        if (n == 0)
			return {};

        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1);
        vector<int> prev(n, -1);
        int maxIndex = 0;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i]++;
                    prev[i] = j;
                }
            }
            if (dp[i] > dp[maxIndex]) {
                maxIndex = i;
            }
        }

        vector<int> result;
        while (maxIndex != -1)
        {
            result.push_back(nums[maxIndex]);
            maxIndex = prev[maxIndex];
        }

        reverse(result.begin(), result.end());
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

	auto result = Solution::largestDivisibleSubset(input);
	for (const auto num : result) {
		cout << num << " ";
	}
	cout << endl;
}
