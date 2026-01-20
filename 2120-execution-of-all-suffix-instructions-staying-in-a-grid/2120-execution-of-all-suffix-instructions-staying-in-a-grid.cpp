class Solution {
private:
    int stepsPossible(int idx, int n, int row, int col, string &s) {
        for (int i = 0; i + idx < s.size(); i++) {
            char c = s[i + idx];
            if (c == 'U') {
                row--;
            } else if (c == 'D') {
                row++;
            } else if (c == 'L') {
                col--;
            } else {
                col++;
            }

            if (row < 0 || row >= n || col < 0 || col >= n) {
                return i;
            }
        }
        return s.size() - idx;
    }
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int len = s.size();
        vector<int> result(len, 0);

        for (int i = 0; i < len; i++) {
            result[i] = stepsPossible(i, n, startPos[0], startPos[1], s);
        }
        return result;
    }
};