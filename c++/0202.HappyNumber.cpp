#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
	private:
	int calculateHappy(int n)
	{
        int result = 0;
        while (n > 0) {
            int digit = n % 10;
            result += digit * digit;
            n /= 10;
        }
        return result;
    }

	public:
    bool isHappy(int n)
	{
        unordered_map<int, bool> visited;
        visited[n] = true;

        while (n != 1) {
            n = calculateHappy(n);
            if (visited[n])
                return false;
            visited[n] = true;
        }
        return true;
    }
};

int main(int ac, char **av)
{
    if (ac != 2) {
        cerr << "Usage: " << av[0] << " <number>" << endl;
        return 1;
    }

    int n = atoi(av[1]);
    Solution solution;
    bool result = solution.isHappy(n);
    cout << (result ? "The number is happy" : "The number is not happy") << endl;
}
