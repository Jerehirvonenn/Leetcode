class Solution {
private:
    bool    patternMatches(const string &word, const string &pattern) {
        if (word.length() != pattern.length())
            return false;

        vector<int> p2w(26, 0);
        vector<int> w2p(26, 0);

        for (int i = 0; i < word.size(); i++) {
            char w = word[i];
            char p = pattern[i];

            if (p2w[p - 'a'] && p2w[p - 'a'] != w)
                return false;
            if (w2p[w - 'a'] && w2p[w - 'a'] != p)
                return false;

            p2w[p - 'a'] = w;
            w2p[w - 'a'] = p;
        }
        return true;
    }
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> result;

        for (const string &word : words) {
            if (patternMatches(word, pattern)) {
                result.push_back(word);
            }
        }
        return result;
    }
};