class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0, smallest = INT_MAX, negatives;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                int num = matrix[i][j];
                if (num < 0) {
                    num = -num;
                    negatives++;
                }
                sum += num;
                smallest = min(static_cast<long long>(num), smallest);
            }
        }
        if (negatives % 2 == 0) {
            return sum;
        } else {
            return sum - (2 * smallest);
        }
    }
};