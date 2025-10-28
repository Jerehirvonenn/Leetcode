class Solution {
private:
    bool canBreak(int freq1[26], int freq2[26]) {
        int balance = 0;
        for (int i = 0; i < 26; i++) {
            balance += freq1[i];
            balance -= freq2[i];
            if (balance < 0) {
                return false ;
            }
        }
        return true ;
    }
public:
    bool checkIfCanBreak(string s1, string s2) {
        int freq1[26] = {0};
        int freq2[26] = {0};
        for (int i = 0; i < s1.size(); i++) {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }
        return (canBreak(freq1, freq2) || canBreak(freq2, freq1));
    }
};