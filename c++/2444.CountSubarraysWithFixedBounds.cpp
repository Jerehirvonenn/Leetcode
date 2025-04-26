#include <iostream>
#include <vector>

using namespace std;

class Solution
{
	public:
        long long countSubarrays(vector<int>& nums, int minK, int maxK)
		{
        	long count = 0, start = -1, minIndex = -1, maxIndex = -1;
        	for (int i = 0; i < nums.size(); i++)
            {
            	if (nums[i] < minK || nums[i] > maxK) {
                    start = i;
                    continue;
                }
            	if (nums[i] == maxK)
                    maxIndex = i;
           		if (nums[i] == minK)
                    minIndex = i;
            	if (minIndex != -1 && maxIndex != -1) {
                    int valid = min(minIndex, maxIndex) - start;
                    if (valid > 0) 
                        count += valid;
                }
        	}
            return count;
		}
};

int main(int ac, char **av)
{
	if (ac < 4) {
		cout << "Usage: " << av[0] << " <num1> <num2> ...<numN>" << endl;
		return 42;
	}

	vector<int> input(ac - 3);
	for (int i = 1; i < ac - 3; i++)
		input[i - 1] = atoi(av[i]);
	int minK = atoi(av[ac - 2]);
	int maxK = atoi(av[ac - 1]);

	Solution solve;
	long long result = solve.countSubarrays(input, minK, maxK);
	cout << "Number of subarrays with fixed bounds min :" << minK << " max: " << maxK << " is "
		<< result << endl;
}
