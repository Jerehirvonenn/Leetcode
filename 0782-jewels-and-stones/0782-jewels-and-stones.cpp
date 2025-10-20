class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> jewel;
        for (const char c : jewels) {
            jewel.insert(c);
        }

        int result = 0;
        for (const char c : stones) {
            if (jewel.count(c)) {
                result++;
            }
        }
        return result;
    }
};