class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int totalApples = accumulate(apple.begin(), apple.end(), 0);
        sort(capacity.begin(), capacity.end(), greater<int>());

        for (int i = 0; i < capacity.size(); i++) {
            totalApples -= capacity[i];
            if (totalApples <= 0) {
                return i + 1;
            }
        }
        return -1;
    }
};