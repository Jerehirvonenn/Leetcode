class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int biggest = *max_element(costs.begin(), costs.end());
        vector<int> costCount(biggest + 1, 0);

        for (const int cost : costs) {
            costCount[cost]++;
        }

        int result = 0;
        for (int i = 0; i <= biggest; i++) {
            while (coins >= i && costCount[i]--) {
                result++;
                coins -= i;
            }
        }
        return result;
    }
};