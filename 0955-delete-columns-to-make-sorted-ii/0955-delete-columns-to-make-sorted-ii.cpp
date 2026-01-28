class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int rows = strs.size();
        if (rows == 0)
            return 0;
        int cols = strs[0].size();

        int deletes = 0;
        vector<bool> sorted(rows, false);
        for (int col = 0; col < cols; col++) {
            vector<bool> tmp = sorted;
            bool del = false;
            for (int row = 0; row < rows - 1; row++) {
                if (tmp[row])
                    continue ;
                if (strs[row][col] > strs[row + 1][col]) {
                    del = true;
                    break ;
                }
                else if (strs[row][col] != strs[row + 1][col]){
                    tmp[row] = true;
                }
            }
            if (del) {
                deletes++;
            }
            else {
                sorted = tmp;
            }
        }
        return deletes;
    }
};