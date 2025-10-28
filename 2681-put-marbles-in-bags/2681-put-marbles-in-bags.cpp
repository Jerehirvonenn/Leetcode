class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        if (k == 1) {
            return 0;
        }
        int n = weights.size();
        vector<long long> splitCost(n - 1, 0);
        for (int i = 0; i < n - 1; i++) {
            splitCost[i] = weights[i] + weights[i + 1];
        }

        sort(splitCost.begin(), splitCost.end());

        long long small = 0, big = 0, cuts = k - 1;
        for (int i = 0, j = splitCost.size() - 1; i < cuts; i++, j--) {
            small += splitCost[i];
            big += splitCost[j];
        }
        return big - small;
    }
};