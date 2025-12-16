class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> freq(26, 0);
        for (const char c : s) {
            freq[c - 'a']++;
        }

        int result = 0;
        for (const char c : t) {
            if (--freq[c - 'a'] >= 0)
                continue ;
            else
                result++;
        }
        return result;
    }
};