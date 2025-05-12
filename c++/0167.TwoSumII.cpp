#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
	public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> seen;

        for (int i = 0; i < numbers.size(); i++)
        {
            if (seen.count(target - numbers[i])) {
                return {seen[target - numbers[i]] + 1, i + 1};
            }
            seen[numbers[i]] = i;
        }
        return {-1};
    }
};

int main(int ac, char **av)
{
    if (ac < 4) {
        cout << "Usage: " << av[0] << " num1 num2 ... | target" << endl;
        return 1;
    }

    vector<int> numbers;
    int target = 0;
    bool parsingTarget = false;

    for (int i = 1; i < ac; ++i) {
        string arg = av[i];
        if (arg == "|") {
            parsingTarget = true;
            continue;
        }

        try {
            int val = stoi(arg);
            if (parsingTarget)
                target = val;
            else
                numbers.push_back(val);
        }
		catch (exception& e) {
            cerr << "Invalid input: " << arg << endl;
            return 2;
        }
    }

    Solution sol;
    vector<int> result = sol.twoSum(numbers, target);

    if (result.size() == 2)
        cout << "Indices: " << result[0] - 1 << ", " << result[1] - 1 << endl;
    else
        cout << "No two numbers found that sum to " << target << endl;
}
