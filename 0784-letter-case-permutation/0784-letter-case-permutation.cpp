class Solution {
private:
    void    recurse(vector<string> &result, string s, int level) {
        if (level == s.size()) {
            result.push_back(s);
            return ;
        }

        recurse(result, s, level + 1);
        if (s[level] < 'A')
            return ;
        s[level] = s[level] ^ 32;
        recurse(result, s, level + 1);
    }
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> result;
        recurse(result, s, 0);
        return result;
    }
};