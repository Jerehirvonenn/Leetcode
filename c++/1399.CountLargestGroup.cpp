#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
private:
    int digitSum(int num)
    {
        int result = 0;
        while (num)
        {
            result += num % 10;
            num /= 10;
        }
        return result;
    }
public:
    int countLargestGroup(int n)
    {
        unordered_map<int, int> groups;
        int biggest = 0;
        int result = 0;
        for (int num = 1; num <= n; num++)
        {
            int current = digitSum(num);
            biggest = max(biggest, ++groups[current]);
        }
        for (auto &pair : groups) {
            if (pair.second == biggest)
                result++;
        }
        return result;
    }
};

int main(int ac, char **av)
{
	if (ac != 2) {
		cout << "Usage: ./a.out <num>" << endl;
		return 42;
	}

	try
	{
		int n = atoi(av[1]);
		Solution solution;
		int result = solution.countLargestGroup(n);
		cout << "Number of largest groups for n = " << n << " is: " << result << endl;
	}
	catch(...)
	{
		cout << "Invalid number" << endl;
		return 42;
	}
}
