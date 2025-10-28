class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int odd = 0;
        int even = 0;
        for (const int num : position) {
            if (num % 2 == 0) {
                odd++;
            } else {
                even++;
            }
        }
        return min(odd, even);
    }
};