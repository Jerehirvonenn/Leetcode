class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(tasks.begin(), tasks.end(), greater<int>());
        sort(processorTime.begin(), processorTime.end()); 
        int result = 0;
        for (int i = 0, j = 0; i < processorTime.size(); i++, j += 4) {
            result = max(result, processorTime[i] + tasks[j]);
        }
        return result;
    }
};