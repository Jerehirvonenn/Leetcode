class Solution {
public:
    string stringHash(string s, int k) {
        int n = s.size();
        string result;
        result.reserve(n / k);

        int hashValue = 0;
        for (int i = 0; i < n; i++) {
            if (i != 0 && i % k == 0) {
                result += static_cast<char>((hashValue % 26) + 'a');
                hashValue = 0;
            }
            hashValue += s[i] - 'a';
        }
        result += static_cast<char>((hashValue % 26) + 'a');
        return result;
    }
};