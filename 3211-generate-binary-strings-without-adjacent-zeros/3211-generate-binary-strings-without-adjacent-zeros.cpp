class Solution {
private:
    void    buildSubStrs(vector<string> &result, string &s, int n) {
        if (s.length() >= n) {
            result.push_back(s);
            return ;
        }

        if (s.empty() || s.back() == '1') {
            s += '0';
            buildSubStrs(result, s, n);
            s.pop_back();
        }
        s += '1';
        buildSubStrs(result, s, n);
        s.pop_back();
    }
public:
    vector<string> validStrings(int n) {
        vector<string> result;
        string current = "";
        buildSubStrs(result, current, n);
        return result;
    }
};