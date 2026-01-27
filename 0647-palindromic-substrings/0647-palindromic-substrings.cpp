class Solution {
private:
    int n;

    int isPalindromic(int left, int right, string &s) {
        return 0;
    }
public:
    int countSubstrings(string s) {
        n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = 0; i <n; i++) {
            dp[i][i] = true;
        }

        int result = n;
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                    if (s[i] == s[i + len - 1] && (len <= 2 || dp[i + 1][i + len - 2])) {
                        result++;
                        dp[i][i + len - 1] = true;
                    }
            }
        }
        return result;
    }
};