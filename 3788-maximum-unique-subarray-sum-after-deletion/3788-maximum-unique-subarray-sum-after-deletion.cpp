class Solution {
public:
    int maxSum(vector<int>& nums) {
        int result = 0;
        unordered_map<int,int> freq;

        bool added = false;
        int biggestNegative = INT_MIN;
        for (const int num : nums) {
            if (num <= 0) {
                biggestNegative = max(biggestNegative, num);
                continue ;
            }
            if (freq[num]++ == 0) {
                added = true;
                result += num;
            }
        }
        return added ? result : biggestNegative ;
    }
};