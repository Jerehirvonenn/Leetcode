class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int freq[101];
        int uniqueNonZero = 0;
        for (const int num : nums) {
            if (num != 0 && ++freq[num] == 1) {
                uniqueNonZero++;
            }
        }
        return uniqueNonZero;
    }
};