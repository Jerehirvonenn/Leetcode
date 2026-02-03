class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.size() < k)
            return false;
        vector<int> freq(26, 0);
        for (const char c : s) {
            freq[c - 'a']++;
        }

        int odds = 0;
        for (const int num : freq) {
            if (num % 2 != 0)
                odds++;
        }
        return odds <= k;
    }
};