#include <iostream>
#include <vector>

using namespace std;

class Solution
{
	private:
		static bool	canRepairAll(long long time, vector<int> &ranks, int cars)
		{
			int carsRepaired = 0;

			for (const auto mechanic : ranks) {
				carsRepaired += sqrt(time / mechanic);
				if (carsRepaired >= cars) {
					return true;
				}
			}
			return false;
		}
	public:
		static long long repairCars(vector<int> &ranks, int cars)
		{
			long long left = 1;
			long long right = static_cast<long long>(*max_element(ranks.begin(),
						ranks.end())) * cars * cars;
			long long result = right;
			while (left < right)
			{
				long long middle = left + (right - left) / 2;
				if (canRepairAll(middle, ranks, cars)) {
					right = middle;
					result = right;
				}
				else {
					left = middle + 1;
				}
			}
			return result;
		}
};

int main(int ac, char ** av)
{
	if (ac < 3)
		return 1;
	ac--;
	av++;

	vector<int> input(ac - 1);
	for (int i = 0; i < ac - 1; i++) {
		input[i] = atoi(av[i]);
		cout << input[i] << " ";
	}
	int cars = atoi(av[ac - 1]);
	cout << "Cars " << cars << endl;

	long long result = Solution::repairCars(input, cars);
	cout << result << endl;
}
