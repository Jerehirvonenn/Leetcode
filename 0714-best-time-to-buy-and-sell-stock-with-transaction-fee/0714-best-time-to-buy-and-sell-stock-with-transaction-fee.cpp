class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int bought = INT_MIN;
        int sold = 0;
        for (const int price : prices) {
            bought = max(bought, sold - price - fee);
            sold = max(sold, bought + price);
        }
        return sold;
    }
};