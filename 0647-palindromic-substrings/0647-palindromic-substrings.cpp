class Solution {
private:
    int n;

    int isPalindromic(int left, int right, string &s) {
        int pals = 0;
        while (left >= 0 && right < n && s[left--] == s[right++]) {
            pals++;
        }
        return pals;
    }
public:
    int countSubstrings(string s) {
        n = s.size();
        int result = 0;

        for (int i = 0; i < n; i++) {
            result += isPalindromic(i, i, s);
            result += isPalindromic(i, i + 1, s);
        }
        return result;
    }
};