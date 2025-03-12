#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    int binarySearch(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int middle = (left + (right - left) / 2);
            if (nums[middle] >= target) {
                right = middle - 1;
            }
            else {
                left = middle + 1;
            }
        }
        return left;
    }
public:
    int maximumCount(vector<int>& nums)
    {
        int firstNegative = binarySearch(nums, 0);
        int firstPositive = nums.size() - binarySearch(nums, 1);
        return max(firstNegative, firstPositive);
    }
};
int main(int ac, char **av)
{
	if (ac < 2)
		return 1;
	ac--;
	av++;

	vector<int> input(ac);
	for (int i = 0; i < ac; i++) {
		input[i] = atoi(av[i]);
	}

	Solution solve;
	int result = solve.maximumCount(input);
	cout << result << endl;
}
