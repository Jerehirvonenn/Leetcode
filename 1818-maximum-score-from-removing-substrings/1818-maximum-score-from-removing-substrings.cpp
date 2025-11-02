class Solution {
private:
    int removeAthenB(string a, string &s, int x, int y) {
        stack<char> stk;
        int n = s.size(), result = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == a[1] && !stk.empty() && stk.top() == a[0]) {
                stk.pop();
                result += x;
            } else {
                stk.push(s[i]);
            }
        }

        stack<char> stk2;
        while (!stk.empty()) {
            if (stk.top() == a[1] && !stk2.empty() && stk2.top() == a[0]) {
                stk.pop();
                stk2.pop();
                result += y;
            } else {
                stk2.push(stk.top());
                stk.pop();
            }
        }
        return result;
    }
public:
    int maximumGain(string s, int x, int y) {
        if (x > y) {
            return removeAthenB("ab", s, x, y);
        } else {
            return removeAthenB("ba", s, y, x);
        }
    }
};