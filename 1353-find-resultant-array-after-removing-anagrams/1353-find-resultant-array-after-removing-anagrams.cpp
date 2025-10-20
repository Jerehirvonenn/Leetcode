class Solution {
private:
    bool isAnagram(string s1, string s2) {
        if (s1.length() != s2.length()) {
            return false;
        }
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        return s1 == s2;
    }
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        if (n < 1) {
            return {};
        }

        vector<string> result;
        result.reserve(n);
        result.push_back(words[0]);
        for (int i = 1; i < n; i++) {
            if (!isAnagram(words[i], words[i - 1])) {
                result.push_back(words[i]);
            }
        }
        return result;
    }
};