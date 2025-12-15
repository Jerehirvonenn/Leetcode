class Solution {
private:
public:
    vector<string> validStrings(int n) {
        vector<string> result;
        result.push_back("");

        for (int i = 0; i < n; i++) {
            vector<string> tmp;
            for (const string s : result) {
                tmp.push_back(s + '1');
                if (s.empty() || s.back() == '1') {
                    tmp.push_back(s + '0');
                }
            }
            result = move(tmp);
        }
        return result;
    }
};