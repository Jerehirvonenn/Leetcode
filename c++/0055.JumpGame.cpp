#include <iostream>
#include <vector>

using namespace std;

class Solution
{
	public:
    static bool canJump(vector<int>& nums)
	{
        int	maximum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (i > maximum) {
                return false;
            }
            maximum = max(maximum, i + nums[i]);
        }
        return true;
    }
};

int main(int ac, char **av)
{
    if (ac < 2) {
        cerr << "Usage: " << av[0] << " <num1> <num2> <num3>..." << endl;
        return 1;
    }

    vector<int> nums;
    for (int i = 1; i < ac; i++) {
        nums.push_back(atoi(av[i]));
    }

    bool result = Solution::canJump(nums);
    cout << (result ? "Can reach the last index" : "Cannot reach the last index") << endl;
}

