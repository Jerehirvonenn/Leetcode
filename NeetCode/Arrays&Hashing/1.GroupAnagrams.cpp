#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string,vector<string>> hashM;
        for (const auto &str : strs)
        {
            string current = str;
            sort(current.begin(), current.end());
            hashM[current].push_back(str);
        }

        vector<vector<string>> result;
        for (auto &pair : hashM)
        {
            result.push_back(pair.second);
        }
        return result;
    }
};

int main(int ac, char **av)
{
	if (ac < 2)
		return 42;

	vector<string> input(av + 1, av + ac);
	Solution solve;
	auto result = solve.groupAnagrams(input);

	for (const auto v : result)
	{
		cout << "[ ";
		bool first = true;
		for (const auto s : v)
		{
			if (!first)
			{
				cout << ", ";
			}
			cout << s;
			first = false;
		}
		cout << " ]\n";
	}
}
