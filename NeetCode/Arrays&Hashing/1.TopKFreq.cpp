#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int, int> freq;
        for (const int num : nums) {
            freq[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        for (auto pair : freq) {
            minHeap.emplace(pair.second, pair.first);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return result;
    }
};

int main(void)
{
    Solution solution;

    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    vector<int> result = solution.topKFrequent(nums, k);

    cout << "Top " << k << " frequent elements: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
}
