#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
	static void	createPerm(int level, vector<int> &current, vector<vector<int>> &result, 
			const int &n, const int &k, int start)
	{
		if (level == k) {
			result.push_back(current);
			return ;
		}
		for (int i = start; i <= n; i++) {
			current[level] = i;
			createPerm(level + 1, current, result, n, k, i + 1);
		}
	}
public:
    static vector<vector<int>> combine(int n, int k)
	{
		vector<vector<int>>	result;
		vector<int>			current(k);

		createPerm(0, current, result, n, k, 1);
		return result;
    }
};

int main(int ac, char **av)
{
	if (ac < 3)
		return 1;

	int n = atoi(av[1]);
	int k = atoi(av[2]);

	vector<vector<int>> result = Solution::combine(n , k);
	for (const auto& row : result)
	{
		for (int num : row)
            std::cout << num << " ";
		std::cout << std::endl;
	}
}
