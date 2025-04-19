#include <iostream>
#include <vector>

using namespace std;

class Solution
{
	public:
    static int removeElement(vector<int>& nums, int val)
	{
		int left = 0;
		for (unsigned int right = 0; right < nums.size(); right++) {
			if (nums[right] != val)
				nums[left++] = nums[right];
		}
		return left;
    }
};

int main(int ac, char **av)
{
	if (ac < 2)
		return 1;
	ac--;
	av++;
	try
	{
		int	target = 3;
		vector<int> nums;
		nums.reserve(ac);
		for (int i = 0; i < ac; i++)
			nums.push_back(stoi(av[i]));
		int result = Solution::removeElement(nums, target);
		cout << "Vector after: ";
		for (unsigned int i = 0; i < result; i++)
			cout << nums[i];
		cout << endl;
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}
}
