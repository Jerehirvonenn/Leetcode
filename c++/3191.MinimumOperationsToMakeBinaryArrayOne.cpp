#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    static int minOperations(vector<int>& nums)
    {
        int result = 0;
        int size = nums.size();
        for (int i = 0; i < size - 2; i++) {
            if (nums[i] == 0) {
                nums[i] ^= 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                result++;
            }
        }
        if (nums[size - 1] == 0 || nums[size - 2] == 0) {
            return -1;
        }
        return result;
    }
};

int main(int ac, char **av)
{
	if (ac < 2) {
		cout << "provide array as input example 1 0 1 1 0 0" << endl;
		return 1;
	}
	ac--;
	av++;

	std::vector<int> input(ac);
	for (int i = 0; i < ac; i++) {
		input[i] = atoi(av[i]);
		if (input[i] != 0 && input[i] != 1) {
			cout << "Must contain only 0 or 1" << endl;
			return 2;
		}
	}

	int result = Solution::minOperations(input);
	cout << result << endl;
}
