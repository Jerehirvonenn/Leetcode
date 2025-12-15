class Solution {
public:
    int maxDistinct(string s) {
        vector<int> seen(26, 0);
        int result = 0;
        for (const char c : s) {
            if (!seen[c - 'a']) {
                result++;
            }
            seen[c - 'a']++;
        }
        return result;
    }
};