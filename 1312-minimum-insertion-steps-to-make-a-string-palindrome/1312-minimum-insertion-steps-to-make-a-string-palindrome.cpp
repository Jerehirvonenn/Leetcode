class Solution {
private:
    int n;
public:
    int minInsertions(string s) {
        n = s.size();
        if (n == 1)
            return 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    if (len == 2)
                        dp[i][j] = 2;
                    else
                        dp[i][j] = 2 + dp[i + 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
                }
                //cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
            }
        }
        return n - dp[0][n -1];
    }
};