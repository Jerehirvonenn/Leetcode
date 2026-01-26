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

    void    dfs(vector<string> &current, vector<vector<string>> &result, vector<vector<bool>> &isPal ,int start, string &s) {
        if (start >= n) {
            result.push_back(current);
            return ;
        }

        for (int i = start; i < n; i++) {
            if (isPal[start][i]) {
                current.push_back(s.substr(start, (i - start + 1)));
                dfs(current, result, isPal, i + 1, s);
                current.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        n = s.size();
        vector<vector<string>> result;
        vector<vector<bool>> isPal(n, vector<bool> (n, false));
        vector<string> current;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                isPal[i][j] = isPalindrome(i, j, s);
            }
        }

        dfs(current, result, isPal, 0, s);

        return result;
    }
};