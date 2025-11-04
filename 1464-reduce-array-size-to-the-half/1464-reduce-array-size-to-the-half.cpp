class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int ,int> freq;
        for (const int num : arr) {
            freq[num]++;
        }

        vector<int> amounts;
        for (const auto &[key, value] : freq) {
            amounts.push_back(value);
        }
        sort(amounts.begin(), amounts.end(), greater<int>());

        int total = arr.size();
        int remaining = total;
        int result = 0;
        for (const int amount : amounts) {
            remaining -= amount;
            result++;
            if (remaining <= total / 2) {
                break;
            }
        }
        return result;
    }
};