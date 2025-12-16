class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> result;
        string current;

        for (int i = 0; i < target.size(); i++) {
            char last = target[i];
            current += 'a';
            for (char c = 'a'; c <= last; c++) {
                current[i] = c;
                result.push_back(current);
            }
        }
        return result;
    }
};