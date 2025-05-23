#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    string encode(vector<string>& strs)
    {
        stringstream result;
        for (const string &str : strs) {
            result << str.size() << "#";
            result << str;
        }
        return result.str();
    }

    vector<string> decode(string s)
    {
        vector<string> result;
        int i = 0;
        while (i < s.size())
        {
            int start = i;
            while (s[i] != '#') {
                i++;
            }
            int size = stoi(s.substr(start, i - start));
            i++;
            result.push_back(s.substr(i, size));
            i += size;
        }
        return result;
    }
};

int main(void)
{
    Solution solution;

    vector<string> original = {"apple", "banana", "grape", "", "pear#with#hash"};
    cout << "Original strings:\n";
    for (const string& str : original) {
        cout << "- " << str << '\n';
    }

    string encoded = solution.encode(original);
    cout << "\nEncoded string:\n" << encoded << '\n';

    vector<string> decoded = solution.decode(encoded);
    cout << "\nDecoded strings:\n";
    for (const string& str : decoded) {
        cout << "- " << str << '\n';
    }
}
