/*
 * LeetCode 632 - Smallest Range Covering Elements from K Lists (Hard)
 *
 * Problem:
 * Given k sorted lists of integers, find the smallest range [a, b] that
 * includes at least one number from each of the k lists.
 *
 * Definition of smaller range:
 * Range [a, b] is smaller than [c, d] if:
 *   - (b - a) < (d - c), or
 *   - (b - a) == (d - c) and a < c
 *
 * Approach:
 * - Use a min-heap (priority queue) to always track the smallest current element
 *   among the heads of the k lists.
 * - Keep track of the current maximum element in the window to compute the range.
 * - Initially push the first element of each list into the min-heap.
 * - Repeatedly pop the minimum element from the heap:
 *     - Update the smallest range if current max - min is better.
 *     - If the popped element’s list has more elements, push the next element
 *       into the heap and update current max.
 *     - If any list is exhausted, stop.
 */

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>

using namespace std;

class Solution {
private:
    using ELEM = tuple<int,int,int>; //value, list index, index in list
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        priority_queue<ELEM, vector<ELEM>, greater<ELEM>> minHeap;
        vector<int> sizes(n, 0);

        int maxVal = INT_MIN;
        for (int i = 0; i < n; i++) {
            sizes[i] = nums[i].size();
            minHeap.emplace(nums[i][0], i, 0);
            maxVal = max(maxVal, nums[i][0]);
        }

        auto topEle = minHeap.top();
        int rangeStart = get<0>(topEle);
        int rangeEnd = maxVal;
        while (1) {
            auto [val, listIndex, index] = minHeap.top();
            minHeap.pop();

            int rangeSize = maxVal - val;
            int bestSize = rangeEnd - rangeStart;
            if (rangeSize < bestSize ||
               (rangeSize == bestSize && val < rangeStart)) {
                rangeStart = val;
                rangeEnd = maxVal;
            }
            
            if (index + 1 >= sizes[listIndex]) {
                break;
            }
            int newVal = nums[listIndex][index + 1];
            minHeap.emplace(newVal, listIndex, index + 1);
            maxVal = max(maxVal, newVal);
        }
        return {rangeStart, rangeEnd};
    }
};

int main(void)
{
    int k;
    cout << "Enter number of lists: ";
    cin >> k;
    vector<vector<int>> nums(k);

    for (int i = 0; i < k; i++) {
        int size;
        cout << "Enter size of list " << i+1 << ": ";
        cin >> size;
        nums[i].resize(size);
        cout << "Enter elements of list " << i+1 << " in sorted order: ";
        for (int j = 0; j < size; j++) {
            cin >> nums[i][j];
        }
    }

    Solution sol;
    vector<int> result = sol.smallestRange(nums);
    cout << "Smallest range covering elements from each list: [" 
         << result[0] << ", " << result[1] << "]\n";
}
