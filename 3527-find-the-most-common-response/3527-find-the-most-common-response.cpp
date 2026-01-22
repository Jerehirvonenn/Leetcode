class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        unordered_map<string,int> freq;

        for (const auto &list : responses) {
            unordered_set<string> unique;
            for (const string &s : list) {
                unique.insert(s);
            }

            for (const string &s : unique) {
                freq[s]++;
            }
        }

        int biggest = 0;
        string result;
        for (const auto &[key,value] : freq) {
            if (value == biggest) {
                result = min(result, key);
            }
            else if (value > biggest) {
                biggest = value;
                result = key;
            }
        }
        return result;
    }
};