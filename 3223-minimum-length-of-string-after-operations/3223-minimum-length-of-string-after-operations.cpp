class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26, 0);
        int remove = 0;
        for (const char c : s) {
            if (++freq[c - 'a'] >= 3) {
                remove += 2;
                freq[c - 'a'] = 1;
            }
        }
        return s.size() - remove;
    }
};