class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();

        unordered_map<int,int> pairs;
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            char current = s[i];
            if (s[i] == '(') {
                stk.push(i);
                continue ;
            }
            else if (current == ')') {
                pairs[stk.top()] = i;
                pairs[i] = stk.top();
                stk.pop();
            }
        }

        string result;
        result.reserve(n);
        int dir = 1;
        for (int i = 0; i < n; i += dir) {
            char current = s[i];
            if (current == '(' || current == ')') {
                dir = -dir;
                i = pairs[i];
            }
            else {
                result.push_back(current);
            }
        }
        return result;
    }
};