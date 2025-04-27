#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    static int countSubarrays(vector<int>& nums)
    {
        int result = 0;
        for (int i = 0; i < nums.size() - 2; i++){
            if (nums[i + 1] % 2 != 0)
                continue;
            else if (nums[i] + nums[i + 2] == (nums[i + 1] / 2))
                result++;
        }
        return result;
    }
};

int main(int ac, char **av)
{
	if (ac < 2) {
		cout << "Usage: ./a.out <num1> <num2> ... <numN>" << endl;
		return 1;
	}
	ac--;
	av++;

	std::vector<int> input(ac);
	for (int i = 0; i < ac; i++)
		input[i] = atoi(av[i]);

	int result = Solution::countSubarrays(input);
	cout << result << endl;
}
