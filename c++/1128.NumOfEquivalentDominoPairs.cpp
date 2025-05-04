#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
	//custom hashing function for complex types like pair
    struct pair_hash {
        size_t operator()(const pair<int, int> &p) const {
            return hash<int>()(p.first) * 31 + hash<int>()(p.second);
        }
    };
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int result = 0;
        unordered_map<pair<int, int>, int, pair_hash> freq;
        for (auto &pair : dominoes) {
            if (pair[0] > pair[1]) {
                swap(pair[0], pair[1]);
            }
            int current = ++freq[{pair[0], pair[1]}];
            result += current - 1;
        }
        return result;
    }
};

int main(void)
{
    Solution sol;

    vector<vector<int>> test1 = {{1,2},{2,1},{3,4},{5,6}};
    cout << "Test 1: " << sol.numEquivDominoPairs(test1) << " (Expected: 1)" << endl;

    vector<vector<int>> test2 = {{1,2},{1,2},{1,1},{1,2},{2,2}};
    cout << "Test 2: " << sol.numEquivDominoPairs(test2) << " (Expected: 3)" << endl;

    vector<vector<int>> test3 = {{1,1},{1,1},{1,1}};
    cout << "Test 3: " << sol.numEquivDominoPairs(test3) << " (Expected: 3)" << endl;

    vector<vector<int>> test4 = {};
    cout << "Test 4: " << sol.numEquivDominoPairs(test4) << " (Expected: 0)" << endl;
}
