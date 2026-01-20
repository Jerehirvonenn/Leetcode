class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int result = 0;
        for (const char c : s) {
            if (c == 'a') {
                result++;
            } else {
                result--;
            }
        }
        return abs(result);
    }
};