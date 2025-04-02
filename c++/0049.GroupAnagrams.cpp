#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
	public:
    vector<vector<string>> groupAnagrams(const vector<string>& strs)
	{
        unordered_map<string, vector<string>> anagrams;

        for (const string& str : strs) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            anagrams[sortedStr].push_back(str);
        }

        vector<vector<string>> result;
        result.reserve(anagrams.size());
        for (auto& entry : anagrams) {
            result.push_back(std::move(entry.second));
        }
        return result;
    }
};

int main(int ac, char **av)
{
    if (ac < 2) {
        cout << "Usage: ./program word1 word2 word3 ..." << endl;
        return 1;
    }
    
    vector<string> words(av + 1, av + ac);
    Solution solution;
    vector<vector<string>> groupedAnagrams = solution.groupAnagrams(words);
    
    cout << "Grouped Anagrams:" << endl;
    for (const auto& group : groupedAnagrams)
	{
        cout << "[ ";
        for (const auto& word : group) {
            cout << word << " ";
        }
        cout << "]" << endl;
    }
}
