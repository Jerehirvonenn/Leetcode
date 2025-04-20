#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    static vector<vector<int>> groupThePeople(vector<int>& groupSizes)
    {
        unordered_map<int, vector<int>> tmp;
        vector<vector<int>> result;

        for (int i = 0; i < groupSizes.size(); i++) {
            int current = groupSizes[i];
            tmp[current].push_back(i);
            if (tmp[current].size() == current) {
                result.push_back(tmp[current]);
                tmp[current].clear();
            }
        }
        return result;
    }
};

int main(int ac, char **av)
{
    if (ac < 2) {
        cout << "Usage: " << av[0] << " groupSizes...\n";
        return 1;
    }

    vector<int> groupSizes;
    for (int i = 1; i < ac; ++i) {
        groupSizes.push_back(atoi(av[i]));
    }

    vector<vector<int>> result = Solution::groupThePeople(groupSizes);
    cout << "Grouped people:\n";

    for (const auto& group : result)
	{
        cout << "[ ";
        for (int person : group) {
            cout << person << " ";
        }
        cout << "]\n";
    }
}
