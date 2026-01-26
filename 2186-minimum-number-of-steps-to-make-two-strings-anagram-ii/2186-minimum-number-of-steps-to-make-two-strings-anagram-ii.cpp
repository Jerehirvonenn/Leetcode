class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        for (const char c : s) {
            freq1[c - 'a']++;
        }
        for (const char c : t) {
            freq2[c - 'a']++;
        }

        int result = 0;
        for (int i = 0; i < 26; i++) {
            result += abs(freq1[i] - freq2[i]);
        }
        return result;
    }
};