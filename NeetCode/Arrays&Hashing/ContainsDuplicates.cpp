#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
    bool hasDuplicate(const string &s)
    {
        unordered_set<int> seen;
        for (const int c : s){
            if (!seen.insert(c).second) {
                return true;
            }
        }
        return false;
    }
};

int main(int ac, char **av)
{
	if (ac != 2)
		return 42;
	Solution solve;
	if (solve.hasDuplicate(string(av[1]))) {
		cout << "Contains duplicates" << endl;
	}
	else {
		cout << "Contains no duplicates" << endl;
	}
}
