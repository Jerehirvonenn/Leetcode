class Solution {
private:
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    string sortVowels(string s) {
        vector<int> vowels(256, 0);
        int smallest = INT_MAX;
        for (const char c : s) {
            if (isVowel(c)) {
                smallest = min(smallest, static_cast<int>(c));
                vowels[c]++;
            }
        }
        if (smallest == INT_MAX)
            return s;

        for (int i = 0; i < s.size(); i++) {
            if (!isVowel(s[i]))
                continue;

            while (vowels[smallest] <= 0)
                smallest++;
            s[i] = smallest;
            vowels[smallest]--;
        }
        return s;
    }
};