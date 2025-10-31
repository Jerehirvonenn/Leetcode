class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int freq[26] = {0};
        for (const char c : s) {
            freq[c - 'a']++;
        }

        int prime = 25; // z
        int secondary = 24; //y
        int repeat = 0;
        string result = "";
        while (prime >= 0) {
            if (freq[prime] == 0) {
                repeat = 0;
                prime--;
            } else if (repeat < repeatLimit) {
                result += prime + 'a';
                freq[prime]--;
                repeat++;
            } else {
                secondary = min(secondary, prime - 1);
                while (secondary >= 0 && freq[secondary] == 0) {
                    secondary--;
                }
                if (secondary < 0) {
                    break;
                }
                result += secondary + 'a';
                freq[secondary]--;
                repeat = 0;
            }
        }
        return result;
    }
};