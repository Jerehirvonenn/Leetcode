class Solution {
private:
    int beautyScore(vector<int> &freq) {
        int biggest = 0;
        int smallest = INT_MAX;
        for (int i = 0; i < 26; i++) {
            int current = freq[i];
            if (current != 0) {
                biggest = max(biggest, current);
                smallest = min(smallest, current);
            }
        }
        return biggest - smallest;
    }
public:
    int beautySum(string s) {
        int result = 0;

        for (int i = 0; i < s.size(); i++) {
            vector<int> freq(26, 0);
            for (int j = i; j < s.size(); j++) {
                freq[s[j] - 'a']++;
                result += beautyScore(freq);
            }
        }
        return result;
    }
};