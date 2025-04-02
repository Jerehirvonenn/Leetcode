#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

/* Calculates the maximum triplet value on indexes i, j, k
 * where i < j < k. with the formula nums[i] - nums[j]) * nums[k]
 * if all triplet values in vector are negative return 0
 *
 * since the biggest result from each index is gained by finding the biggest number
 * to the left of it and biggest to the right of it. we pass throught the vector twice to
 * map biggest in each index. then we do final pass and check biggest result in each
 * index and update result if one was found
 */

class Solution
{
	public:
		long long maximumTripletValue(vector<int>& nums)
		{
			int n = nums.size();
			if (n < 3)
				return 0;

			vector<int> biggestLeft(n, 0);
			int biggest = 0;

			for (int i = 0; i < n; i++) {
				biggest = max(biggest, nums[i]);
				biggestLeft[i] = biggest;
			}

			vector<int> biggestRight(n, 0);
			biggest = 0;

			for (int i = n - 1; i >= 0; i--) {
				biggest = max(biggest, nums[i]);
				biggestRight[i] = biggest;
			}

			long long maxValue = 0;
			for (int j = 1; j < n - 1; j++) {
				maxValue = max(maxValue, (long long)(biggestLeft[j - 1] - nums[j]) * biggestRight[j + 1]);
			}
			return maxValue;
		}
};

int main(int ac, char **av)
{
	if (ac < 4) {
        cerr << "Usage: " << av[0] << " num1 num2 num3 ...\n";
        return 1;
    }

    vector<int> nums(ac - 1);
    for (int i = 1; i < ac; i++) {
		int num;
		stringstream ss(av[i]); 
        if (!(ss >> num)) {
            cerr << "Invalid input: " << av[i] << " is not a number.\n";
            return 1;
        }
        nums.push_back(num);
    }

    Solution solution;
    cout << "Maximum Triplet Value: " << solution.maximumTripletValue(nums) << endl;
}
