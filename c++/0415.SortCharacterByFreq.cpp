/*
 * Leetcode 451 - Sort Characters By Frequency (Medium)
 *
 * Given a string s, sort it in decreasing order based on the frequency of the characters
 * The frequency of a character is the number of times it appears in the string
 * 
 * Approach:
 * - First count the frequency of each character in the string using an unordered_map
 * - Then, use a **max-heap** (priority_queue) to store characters with their frequencies
 * - The heap ensures that the most frequent characters are placed at the top
 * - Finally, pop elements from the heap and construct the result string by appending
 *   each character the number of times it appeared
 *
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (const char c : s) {
            freq[c]++;
        }

        priority_queue<pair<int, char>> maxHeap;
        for (auto[c, num] : freq) {
            maxHeap.emplace(num, c);
        }

        string result;
        result.reserve(s.size());
        while (!maxHeap.empty()) {
            auto [num, c] = maxHeap.top();
            maxHeap.pop();
            string tmp(num, c);
            result += tmp;
        }
        return result;
    }
};

int main(void)
{
    string s;
    cout << "Enter the string: ";
    cin >> s;

    Solution solution;
    string result = solution.frequencySort(s);

    cout << "Sorted string by frequency: " << result << endl;
}
