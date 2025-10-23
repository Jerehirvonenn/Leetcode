class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stk;
        for (const char c : s) {
            if (!stk.empty() && stk.top() == '(' && c == ')') {
                stk.pop();
            } else {
                stk.push(c);
            }
        }
        return stk.size();
    }
};