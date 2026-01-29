class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> penaltyIfClosed(n, 0);

        int penalty = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (customers[i] == 'Y')
                penalty++;
            penaltyIfClosed[i] = penalty;
            cout << penalty << endl;
        }

        int best = INT_MAX;
        int result = -1;
        penalty = 0;
        for (int i = 0; i < n; i++) {
            if (penalty + penaltyIfClosed[i] < best) {
                result = i;
                best = penalty + penaltyIfClosed[i];
            }
            if (customers[i] == 'N')
                penalty++;
        }
        if (penalty < best)
            return n;
        return result;
    }
};