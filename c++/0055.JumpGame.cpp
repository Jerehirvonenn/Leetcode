#include <iostream>
#include <vector>

using namespace std;

class Solution
{
	public:
    bool canJump(vector<int>& nums) {
        int maximum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (i > maximum) {
                return false;
            }
            maximum = max(maximum, i + nums[i]);
        }
        return true;
    }
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <space-separated list of numbers>" << endl;
        return 1;
    }

    vector<int> nums;
    for (int i = 1; i < argc; i++) {
        nums.push_back(atoi(argv[i]));
    }

    Solution solution;
    bool result = solution.canJump(nums);
    cout << (result ? "Can reach the last index" : "Cannot reach the last index") << endl;
}

