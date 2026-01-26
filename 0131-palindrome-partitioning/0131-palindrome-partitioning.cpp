class Solution {
private:
    int n = 0;
    bool    isPalindrome(int left, int right, string &s) {
        while (left < right) {
            if (s[left++] != s[right--])
                return false;
        }
        return true;
    }

    void    dfs(vector<string> &current, vector<vector<string>> &result, int start, string &s) {
        if (start >= n) {
            result.push_back(current);
        }

        for (int i = start; i < n; i++) {
            if (isPalindrome(start, i, s)) {
                current.push_back(s.substr(start, (i - start + 1)));
                dfs(current, result, i + 1, s);
                current.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        n = s.size();
        vector<vector<string>> result;
        vector<string> current;

        dfs(current, result, 0, s);

        return result;
    }
};