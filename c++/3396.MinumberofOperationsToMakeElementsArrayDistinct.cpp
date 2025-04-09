#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>

using namespace std;

class Solution
{
	public:
    static int minimumOperations(vector<int>& nums)
	{
        unordered_map<int, int> intCount;

        int duplicates = 0;
        int size = 0;
        for (const int num : nums)
		{
            if (++intCount[num] > 1) {
                duplicates++;
            }
            size++;
        }

        int result = 0;
        while (duplicates && size >= 3)
		{
            int start = result * 3;
            for (int i = 0; i < 3 && (start + i) < nums.size(); ++i) {
                if (--intCount[nums[start + i]] >= 1) {
                    duplicates--;
                }
            }
            result++;
            size -= 3;
        }
        if (duplicates) {
            return result + 1;
        }
        return result;
    }
};

int main(int ac, char **av)
{
    if (ac < 2) {
        cerr << "Usage: " << av[0] << " num1 num2 num3 ..." << endl;
        return 1;
    }

    vector<int> nums;
    for (int i = 1; i < ac; ++i) {
        nums.push_back(atoi(av[i]));
    }

    int result = Solution::minimumOperations(nums);
    cout << "Minimum operations: " << result << endl;
}

