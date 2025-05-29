/*
 * Leetcode 347 - Top K Frequent Elements (Medium)
 *
 * Given an array of integers and an integer k, return the k most frequent elements.
 * You can return the result in any order.
 *
 * Approach:
 * - First, count how often each number appears using an unordered_map.
 * - Then, use a min-heap to keep the top k elements:
 *   -- Each heap element is a pair of (frequency, number).
 *   -- If the heap exceeds size k, remove the smallest frequency.
 * - Finally, extract the numbers from the heap and return them as the result.
 *
 * Time Complexity: O(n log k)
 * Space Complexity: O(n)
 */

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

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minHeap;
        for (const auto [num, val] : freq) {
            minHeap.emplace(val, num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        vector<int> result;
        result.reserve(k);
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return result;
    }
};

int main(void)
{
    int n, k;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    cout << "Enter k: ";
    cin >> k;

    Solution sol;
    vector<int> result = sol.topKFrequent(nums, k);
    cout << "Top " << k << " frequent elements: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
}
