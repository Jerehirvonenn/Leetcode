class Solution {
public:
    int minFlips(string target) {
        int result = 0;
        if (target[0] == '1') {
            result++;
        }
        for (int i = 1; i < target.size(); i++) {
            if (target[i] != target[i - 1]) {
                result++;
            }
        }
        return result;
    }
};