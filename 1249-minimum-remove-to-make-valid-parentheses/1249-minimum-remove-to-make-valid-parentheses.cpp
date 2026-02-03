class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ')' && open > 0) {
                open--;
            } else if (s[i] == ')') {
                s[i] = '#';
            } else if (s[i] == '(') {
                open++;
            }
        }

        int closed = 0;
        for (int i = s.size() - 1; i >= 0 && open; i--) {
            if (s[i] == '(' && closed > 0) {
                closed--;
            } else if (s[i] == '(') {
                s[i] = '#';
                open--;
            } else if (s[i] == ')') {
                closed++;
            }
        }

        string result;
        result.reserve(s.size());

        for (const char c : s) {
            if (c != '#')
                result.push_back(c);
        }
        return result;
    }
};