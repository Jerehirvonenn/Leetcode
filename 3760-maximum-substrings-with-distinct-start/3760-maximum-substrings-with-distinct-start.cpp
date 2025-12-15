class Solution {
public:
    int maxDistinct(string s) {
        unordered_set<char> seen;
        int result = 0;
        for (const char c : s) {
            if (!seen.count(c)) {
                result++;
            }
            seen.insert(c);
        }
        return result;
    }
};