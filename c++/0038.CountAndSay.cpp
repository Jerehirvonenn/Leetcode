#include <iostream>

using namespace std;

class Solution
{
	public:
    static string countAndSay(int n)
    {
        if (n == 1) {
            return "1";
        }

        string result = "1";
        for (int i = 2; i <= n; i++)
        {
            string current = "";
            int count = 1;
            for (int j = 1; j < result.size(); j++)
            {
                if (result[j] == result[j - 1]) {
                    count++;
                }
                else {
                    current.append(to_string(count) + result[j - 1]);
                    count = 1;
                }
            }
            current.append(to_string(count) + result[result.size() - 1]);
            result = current;
        }
        return result;
    }
};

int main(int ac, char **av)
{
	if (ac != 2)
		return 42;

	int n = atoi(av[1]);
	string result = Solution::countAndSay(n);
	cout << result << endl;
}
