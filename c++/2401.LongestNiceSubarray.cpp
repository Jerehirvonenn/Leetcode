#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    static int longestNiceSubarray(vector<int>& nums)
    {
        int used = 0;
        int left = 0;
        int result = 0;

        for (int right = 0; right < nums.size(); right++) {
            while ((used & nums[right]) != 0) {
                used ^= nums[left++];
            }
            used |= nums[right];
            result = max(right - left + 1, result);
        }
        return result;
    }
};

int main(int ac, char **av)
{
	if (ac < 2)
		return 1;
	ac--;
	av++;

	std::vector<int> input(ac);
	for (int i = 0; i < ac; i++) {
		input[i] = atoi(av[i]);
	}

	int result = Solution::longestNiceSubarray(input);
	cout << result << endl;
}
