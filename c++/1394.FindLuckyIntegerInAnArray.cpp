/*
 * Leetcode 1394 - Find Lucky Integer in an Array (Easy)
 *
 * Problem:
 * Given an array of integers arr, a lucky integer is an integer whose
 * frequency in the array equals its value.
 * Return the largest lucky integer in the array. If no lucky integer exists, return -1.
 *
 * Approach:
 * - Use an unordered_map to count the frequency of each integer.
 * - Iterate through the map to find the largest integer whose frequency equals its value.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> count;
        int result = -1;
        for (const int num : arr) {
            count[num]++;
        }
        for (auto cur : count) {
            if (cur.first == cur.second) {
                result = max(result, cur.first);
            }
        }
        return result;
    }
};

int main(void)
{
    Solution solution;
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int lucky = solution.findLucky(arr);
    cout << "Largest lucky integer: " << lucky << endl;
}
