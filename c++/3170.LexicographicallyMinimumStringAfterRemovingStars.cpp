/*
 * Leetcode 3170 - Lexicographically Minimum String After Removing Stars (Medium)
 *
 * Problem:
 * You are given a string `s` that may contain any number of '*' characters.
 * While there is a '*', remove the *leftmost* '*' and the *smallest* non-'*' character to its left.
 * If there are several smallest characters, you may delete any of them.
 * Return the lexicographically smallest string remaining after all '*' have been removed.
 *
 * Approach:
 * - Use a min-heap (priority_queue) to track non-'*' characters with their original indices.
 * - When a '*' is found, pop the smallest valid character from the heap
 *   and mark both it and the '*' for removal.
 * - After processing the string, build the final result by skipping marked characters.
 *
 * Time Complexity: O(N log N) due to heap operations for each non-'*' character
 * Space Complexity: O(N) for heap and removal markers
 */

#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

class Solution {
private:
    struct Compare {
        bool operator()(const pair<char, int>& a, const pair<char, int>& b) const
		{
            if (a.first != b.first)
                return a.first > b.first;
            return a.second < b.second;
        }
    };

public:
    string clearStars(string s)
    {
        int size = s.size();
        priority_queue<pair<char, int>, vector<pair<char, int>>, Compare> minHeap;
        vector<bool> toRemove(size, false);

        for (int i = 0; i < size; i++)
		{
            if (s[i] == '*')
			{
                if (!minHeap.empty()) {
                    auto current = minHeap.top();
                    minHeap.pop();
                    toRemove[current.second] = true;
                }
                toRemove[i] = true;
            }
			else {
                minHeap.push({s[i], i});
            }
        }

        string result;
        result.reserve(size);
        for (int i = 0; i < size; i++) {
            if (!toRemove[i])
                result += s[i];
        }
        return result;
    }
};

int main(void)
{
    string s;
    cout << "Enter string with '*' characters: ";
    cin >> s;

    Solution sol;
    string result = sol.clearStars(s);
    cout << "Resulting string: " << result << endl;
}
