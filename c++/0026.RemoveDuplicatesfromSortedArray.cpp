#include <iostream>
#include <vector>

using namespace std;

class Solution
{
	public:
		static int removeDuplicates(vector<int>& nums)
		{
			int left = 0;
			for (unsigned int right = 1; right < nums.size(); right++)
			{
				if (nums[left] != nums[right]) {
					nums[++left] = nums[right];
				}
			}
			return left + 1;
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
		vector<int> nums;
		nums.reserve(ac);
		for (int i = 0; i < ac; i++) {
			nums.push_back(stoi(av[i]));
		}
		int result = Solution::removeDuplicates(nums);
		cout << "Vector after: ";
		for (unsigned int i = 0; i < result; i++) {
			cout << nums[i];
		}
		cout << endl;
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}
}
