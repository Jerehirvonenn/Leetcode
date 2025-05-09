/*
 * Leetcode 1046 - Last Stone Weight (Easy)
 *
 * You're given a list of stone weights:
 * - Each turn, pick the two heaviest stones and smash them together
 * - If they weigh the same, both are destroyed
 * - If they're different, the heavier one loses weight equal to the lighter one's weight
 * - Repeat until one or no stones are left
 *
 * Approach:
 * - We use a max-heap (priority_queue in C++) to always access the two biggest stones
 * - Insert all stones into the heap
 * - While more than one stone remains:
 *     - Pop the two heaviest
 *     - If they're different, push the difference back into the heap
 * - At the end, return the weight of the last remaining stone (or 0 if none)
 *
 * Time Complexity: O(n log n) due to heap operations.
 * Space Complexity: O(n) for the heap.
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones)
    {
        priority_queue<int> maxHeap;
        for(const int current : stones) {
            maxHeap.push(current);
        }

        while (maxHeap.size() > 1)
        {
            int stoneY = maxHeap.top(); maxHeap.pop();
            int stoneX = maxHeap.top(); maxHeap.pop();
            if (stoneY != stoneX) {
                maxHeap.push(stoneY - stoneX);
            }
        }
        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};

int main(void)
{
    int n;
    cout << "Enter number of stones: ";
    cin >> n;

    vector<int> stones(n);
    cout << "Enter stone weights: ";
    for (int i = 0; i < n; ++i) {
        cin >> stones[i];
    }

    Solution solution;
    int result = solution.lastStoneWeight(stones);
    cout << "Last remaining stone weight: " << result << endl;
}
