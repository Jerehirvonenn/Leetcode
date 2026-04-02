class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        int n = s1.length();

        for (int i = 0; i < n; i++) {
            if (s1[i] == s2[i])
                continue;
            
            if (i >= n - 2)
                return false;

            if (s1[i] == s2[i + 2] && s2[i] == s1[i + 2])
                swap(s1[i], s1[i + 2]);
            else
                return false;
        }
        return true;
    }
};