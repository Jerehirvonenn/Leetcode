class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();

        vector<bool> found(3, false);
        for (int i = 0; i < n; i++) {
            if (triplets[i][0] > target[0] || triplets[i][1] > target[1] || triplets[i][2] > target[2])
                continue ;
            for (int j = 0; j < target.size(); j++) {
                if (triplets[i][j] == target[j])
                    found[j] = true;
            }
            if (found[0] && found[1] && found[2])
                return true;
        }
        return false;
    }
};