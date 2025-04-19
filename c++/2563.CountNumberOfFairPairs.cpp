#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	private:
    static long long atLeast(vector<int> &nums, int limit)
    {
        long long result = 0;
        int left = 0;
        int right = nums.size() - 1;
        while (left < right)
        {
            if (nums[left] + nums[right] <= limit) {
                result += right - left;
                left++;
            }
            else {
                right--;
            }
        }
        return result;
    }
public:
    static long long countFairPairs(vector<int>& nums, int lower, int upper)
    {
        sort(nums.begin(), nums.end());
		return (atLeast(nums, upper) - atLeast(nums, lower - 1));
    }
};

int main(void)
{
    vector<int> nums = {1, 2, 3, 4, 5};
    int lower = 3;
    int upper = 6;

    long long result = Solution::countFairPairs(nums, lower, upper);
    cout << "number of fair pairs: " << result << endl;
}
