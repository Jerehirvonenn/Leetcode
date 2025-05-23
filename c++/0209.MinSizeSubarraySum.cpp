#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
	public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int smallest = INT_MAX;
        int left = 0;
        int sum = 0;
        for (int right = 0; right < nums.size(); right++)
        {
            sum += nums[right];
            while (sum >= target)
            {
                smallest = min(smallest, right - left + 1);
                sum -= nums[left++];
            }
        }
        return smallest == INT_MAX ? 0 : smallest;
    }
};

int main(int ac, char **av)
{
    if (ac < 4) {
        cerr << "Usage: " << av[0] << " num1 num2 ... | target" << endl;
        return 1;
    }

    vector<int> nums;
    int target = 0;
    bool parsingTarget = false;
    for (int i = 1; i < ac; ++i)
	{
        string arg = av[i];
        if (arg == "|") {
            parsingTarget = true;
            continue;
        }

        try {
            int val = stoi(arg);
            if (parsingTarget)
                target = val;
            else
                nums.push_back(val);
        }
		catch (exception& e) {
            cerr << "Invalid input: " << arg << endl;
            return 1;
        }
    }

    Solution sol;
    int result = sol.minSubArrayLen(target, nums);
    cout << "Minimum subarray length with sum ≥ " << target << " is: " << result << endl;
}
