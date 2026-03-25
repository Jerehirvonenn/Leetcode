class Solution {
private:

public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int r = grid.size();
        if (r == 0)
            return true;
        int c = grid[0].size();

        //horizontal cut
        vector<long long> sumBefore(r);
        long long sum = 0;
        for (int i = 0; i < r; i++) {
            sumBefore[i] = sum;
            sum += accumulate(grid[i].begin(), grid[i].end(), 0LL);
        }

        sum = 0;
        for (int i = r - 1; i >= 0; i--) {
            sum += accumulate(grid[i].begin(), grid[i].end(), 0LL);
            if (sum == sumBefore[i])
                return true;
        }

        //vertical cut
        sumBefore = vector<long long>(c + 1);
        sum = 0;
        for (int i = 0; i < c; i++) {
            sumBefore[i] = sum;
            for (int j = 0; j < r; j++) {
                sum += grid[j][i];
            }
        }

        sum = 0;
        for (int i = c - 1; i >= 0; i--) {
            for (int j = 0; j < r; j++) {
                sum += grid[j][i];
            }
            if (sum == sumBefore[i])
                return true;
        }

        return false;
    }
};