class Solution {
private:
    using StudentData = pair<int, int>;

    struct ComparePercentage {
    bool operator()(const StudentData& a, const StudentData& b) const {
        double gain_a = (static_cast<double>(a.first + 1) / (a.second + 1)) - 
                            (static_cast<double>(a.first) / a.second);
        double gain_b = (static_cast<double>(b.first + 1) / (b.second + 1)) -
                            (static_cast<double>(b.first) / b.second);
        return gain_a < gain_b;
    }
};
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<StudentData, vector<StudentData>, ComparePercentage> maxHeap;
        for (auto clas : classes) {
            maxHeap.push(make_pair(clas[0], clas[1]));
        }

        while (extraStudents--) {
            auto worstClass = maxHeap.top();
            maxHeap.pop();

            worstClass.first++;
            worstClass.second++;
            maxHeap.push(worstClass);
        }

        double totalRatio = 0.0;
        while (!maxHeap.empty()) {
            StudentData current = maxHeap.top();
            maxHeap.pop();
            totalRatio += static_cast<double>(current.first) / current.second;
        }
        return totalRatio / classes.size();
    }
};