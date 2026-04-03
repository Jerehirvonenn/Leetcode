class Solution {
private:
    const long long MOD = 1'000'000'007;
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<long long>> biggest(n, vector<long long>(m, 0));
        vector<vector<long long>> smallest(n, vector<long long>(m, 0));

        smallest[0][0] = grid[0][0];
        biggest[0][0] = grid[0][0];
        for (int i = 1; i < m; i++) {
            biggest[0][i] = biggest[0][i - 1] * grid[0][i];
            smallest[0][i] = smallest[0][i - 1] * grid[0][i];
        }
         for (int i = 1; i < n; i++) {
            biggest[i][0] = biggest[i - 1][0] * grid[i][0];
            smallest[i][0] = smallest[i- 1][0] * grid[i][0];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                int current = grid[i][j];

                long long c1 = current * biggest[i - 1][j];
                long long c2 = current * smallest[i - 1][j];
                long long c3 = current * biggest[i][j - 1];
                long long c4 = current * smallest[i][j - 1];

                smallest[i][j] = min({c1, c2, c3, c4});
                biggest[i][j] = max({c1, c2, c3, c4});
            }
        }

        long long ans = biggest[n - 1][m - 1];
        if (ans < 0)
            return -1;
        return ans % MOD;
    }
};