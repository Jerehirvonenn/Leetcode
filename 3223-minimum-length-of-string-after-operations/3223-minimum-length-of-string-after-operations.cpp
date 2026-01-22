class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char, int> freq;
        int remove = 0;
        for (const char c : s) {
            if (++freq[c] >= 3) {
                remove += 2;
                freq[c] = 1;
            }
        }
        return s.size() - remove;
    }
};