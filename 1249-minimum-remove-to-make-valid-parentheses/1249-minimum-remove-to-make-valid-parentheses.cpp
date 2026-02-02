class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open = 0;
        for (int i = 0; i < s.size(); i++) {
            cout << i << " " << open << endl;
            if (s[i] == ')' && open > 0) {
                open--;
            } else if (s[i] == ')') {
                s.erase(i, 1);
                i--;
            } else if (s[i] == '(') {
                open++;
            }
        }

        if (open == 0) {
            return s;
        }

        int closed = 0;
        for (int i = s.size(); i >= 0; i--) {
            if (s[i] == '(' && closed > 0) {
                closed--;
            } else if (s[i] == '(') {
                s.erase(i, 1);
            } else if (s[i] == ')') {
                closed++;
            }
        }
        return s;
    }
};