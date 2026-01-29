class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.size();
        int m = spaces.size();
        string result(m + n, ' ');

        int i = 0; //s
        int j = 0; //spaces
        int current = 0;
        while (current < m + n && i < n) {
            if (j < m && i == spaces[j]) {
                j++;
                current++;
                continue ;
            }
            result[current++] = s[i++];
        }
        return result;
    }
};