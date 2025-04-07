#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

class Solution
{
	public:
    static bool canPartition(vector<int>& nums)
    {
        int total = 0;
        int size = nums.size();

        for (int i = 0; i < size; i++) {
            total += nums[i];
        }
        if (total % 2 != 0) {
            return false;
        }

        bitset<10001> canMake(1);
        for (const int num : nums) {
            canMake |= canMake << num;
            if (canMake[total / 2])
                return true;
        }
        return false;
    }
};

int main(void)
{
    vector<vector<int>> testCases =
	{ {1, 5, 11, 5},
      {1, 2, 3, 5},
      {2, 2, 1, 1},
      {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 100}
    };

    for (size_t i = 0; i < testCases.size(); ++i)
	{
        cout << "Test case " << i + 1 << ": ";
        for (int num : testCases[i]) cout << num << " ";
        bool result = Solution::canPartition(testCases[i]);
        cout << "\nCan be partitioned into two equal subsets? " 
             << (result ? "true" : "false") << "\n\n";
    }
}

