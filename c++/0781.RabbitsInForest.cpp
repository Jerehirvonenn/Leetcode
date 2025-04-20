#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
	public:
	static int numRabbits(vector<int>& answers)
    {
        unordered_map<int,int>  seen;
        int                     result = 0;

        for (int num : answers) {
            if (seen.count(num) == 0) {
                seen[num]++;
                result += num + 1;
            }
            else {
                seen[num]++;
                if (seen[num] > num + 1) {
                    result += num + 1;
                    seen[num] = 1;
                }
            }
        }
        return result;
    }
};

int main(int ac, char **av)
{
    if (ac < 2) {
        cout << "Usage: " << av[0] << " num1 num2 num3 ...\n";
        return 1;
    }

    vector<int> answers;
    for (int i = 1; i < ac; ++i)
        answers.push_back(atoi(av[i]));

    int result = Solution::numRabbits(answers);
    cout << "Minimum number of rabbits: " << result << endl;
}
