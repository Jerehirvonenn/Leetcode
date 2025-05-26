#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        unordered_map<char,int> seen;
        for (int i = 0;  i < s.size(); i++)
        {
            if (++seen[s[i]] == 0)
                seen.erase(s[i]);
            if (--seen[t[i]] == 0)
                seen.erase(t[i]);
        }
        return seen.empty();
    }
};

int main(int ac, char **av)
{
	if (ac != 3)
		return 42;
	Solution solve;
	if (solve.isAnagram(string(av[1]), string(av[2]))) {
		cout << "They are anagrams" << endl;
	}
	else {
		cout << "Not anagrams" << endl;
	}
}
