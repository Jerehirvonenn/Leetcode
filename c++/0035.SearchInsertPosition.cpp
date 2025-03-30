#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int searchInsert(vector<int>& nums, int target)
	{
		int left = 0;
		int right = nums.size();

		while (left < right)
		{
			int middle = left + (right - left) / 2;
			if (nums[middle] == target) {
				return middle;
			}
			else if (target > nums[middle]) {
				left = middle + 1;
			}
			else {
				right = middle;
			}
		}
		return left;
    }
};

int main(void)
{
	vector<int> nums = {1, 3, 5, 6};
	int target = 2;

	int result = Solution::searchInsert(nums, target);
	cout << result << endl;
}
