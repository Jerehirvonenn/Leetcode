class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int bestLand = INT_MAX;
        int bestWater = INT_MAX;

        for (int i = 0; i < n; i++) {
            bestLand = min(bestLand, landStartTime[i] + landDuration[i]);
        }

        for (int i = 0; i < m; i++) {
            bestWater = min(bestWater, waterStartTime[i] + waterDuration[i]);
        }

        int bestCombo = INT_MAX;
         for (int i = 0; i < m; i++) {
            int start = max(bestLand, waterStartTime[i]);
            bestCombo = min(start + waterDuration[i], bestCombo);
        }

        for (int i = 0; i < n; i++) {
            int start = max(bestWater, landStartTime[i]);
            bestCombo = min(start + landDuration[i], bestCombo);
        }
        return bestCombo;
    }
};