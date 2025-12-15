class Solution {
private:
public:
    vector<string> validStrings(int n) {
        vector<string> result;
        if (n == 0)
            return result;
        result.push_back("1");
        result.push_back("0");

        for (int i = 1; i < n; i++) {
            vector<string> tmp;
            for (const string s : result) {
                tmp.push_back(s + '1');
                if (s.back() == '1') {
                    tmp.push_back(s + '0');
                }
            }
            result = move(tmp);
        }
        return result;
    }
};