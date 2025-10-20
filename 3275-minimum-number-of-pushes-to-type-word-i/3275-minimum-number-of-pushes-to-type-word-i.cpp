class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for (const char c : word) {
            freq[c - 'a']++;
        }

        sort (freq.begin(), freq.end());
        int used = 0;
        int result = 0;
        for (int i = 0; i < freq.size(); i++) {
            if (freq[i] == 0) {
                continue ;
            }

            result += (used / 8 + 1) * freq[i];
            used++;
        }
        return result;
    }
};