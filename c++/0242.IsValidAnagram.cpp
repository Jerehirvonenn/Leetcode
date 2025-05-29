#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        unordered_map<char, int> pop;

        for (const char chr : s) {
            pop[chr]++;
        }

        for (const char chr : t) {
            if (--pop[chr] < 0) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <string1> <string2>" << endl;
        return 1;
    }

    string s = argv[1];
    string t = argv[2];

    Solution solution;
    bool result = solution.isAnagram(s, t);
    cout << (result ? "The strings are anagrams" : "The strings are not anagrams") << endl;
    
    return 0;
}

