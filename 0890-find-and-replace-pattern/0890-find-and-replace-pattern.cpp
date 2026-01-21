class Solution {
private:
    // normalize strings version
    string  normalizeWord(const string &s) {
        vector<int> seen(26, 0);
        string norm;
        int next = 1;

        for (const char c : s) {
            if (!seen[c - 'a']) {
                seen[c - 'a'] = next++;
            }
            norm += seen[c - 'a'];
        }
        return norm;
    }
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> result;

        string normalP = normalizeWord(pattern);
        for (const string &word : words) {
            if (pattern.length() != word.length())
                continue;
            string normalW = normalizeWord(word);
            if (normalW == normalP)
                result.push_back(word);
        }
        return result;
    }
};