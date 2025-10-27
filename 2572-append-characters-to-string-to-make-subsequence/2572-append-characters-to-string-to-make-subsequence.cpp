class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = s.size();
        int m = t.size();
        int matches = 0;
        for (int i = 0, j = 0; i < n && j < m; i++) {
            if (s[i] == t[j]) {
                matches++;
                j++;
            }
        }   
        return m - matches;
    }
};