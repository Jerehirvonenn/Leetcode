class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length();
        string result;
        result.reserve(n);

        int open = 0;
        for (const char c : s) {
            if (c == '(') {
                if (open++ != 0) {
                    result.push_back(c);
                }
            } else {
                if (--open != 0)
                    result.push_back(c);
            }
        }
        return result;
    }
};