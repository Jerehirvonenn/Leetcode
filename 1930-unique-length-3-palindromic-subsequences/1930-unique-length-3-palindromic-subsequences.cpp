class Solution {
private:
    int uniquesBetweenIndexes(int start, int end, string &s) {
        bitset<26> seen;
        int result = 0;
        for (int i = start + 1; i < end; i++) {
            int current = s[i] - 'a';
            if (seen[current])
                continue ;
            result++;
            seen[current].flip();
        }
        return result;
    }
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<pair<int,int>> idx(26, pair<int,int>(-1, -1)); //first and last index of char

        for (int i = 0; i < n; i++) {
            int current = s[i] - 'a';
            if (idx[current].first == -1) { //finding char first time
                idx[current].first = i;
            }
            idx[current].second = i;
        }

        int result = 0;
        for (const auto &[first, last] : idx) {
            if (first == -1 || first == last)
                continue ;
            result += uniquesBetweenIndexes(first, last, s);
        }
        return result;
    }
};