class Solution {
public:
    int minDeletion(string s, int k) {
        vector<int> freq(26, 0);
        int unique = 0;
        for (const char c : s) {
            if (++freq[c - 'a'] == 1) {
                unique++;
            }
        }
        if (unique <= k) {
            return 0;
        }
        sort(freq.begin(), freq.end());

        int result = 0;
        k = unique - k;
        for (const int amount : freq) {
            if (amount == 0) {
                continue ;
            }
            result += amount;
            if (--k == 0) {
                break;
            }
        }
        return result;
    }
};