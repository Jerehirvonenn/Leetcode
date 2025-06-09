/*
 * Leetcode 621 - Task Scheduler (Medium)
 *
 * Problem:
 * You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n.
 * Each CPU interval can be idle or allow the completion of one task.
 * Tasks can be completed in any order, but there's a constraint:
 * there has to be a gap of at least n intervals between two tasks with the same label.
 *
 * Return the minimum number of CPU intervals required to complete all tasks.
 *
 * Approach:
 * - Count the frequency of each task (A-Z) using a hash map
 * - Use a max-heap (priority_queue) to always select the task with the highest remaining count
 * - Push performed task into cooldown queue for n time,
 *   and push back to maxHeap when it can execute again
 *
 * Time Complexity: O(N log K), where N = number of tasks, K = number of unique tasks
 * Space Complexity: O(K) for heap and cooldown queue
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n)
    {
        unordered_map<char, int> freq;
        for (const auto task : tasks) {
            freq[task]++;
        }

        priority_queue<int> maxHeap;
        for (auto [_, count] : freq) {
            maxHeap.push(count);
        }

        int time = 0;
        queue<pair<int, int>> cooldown; // {time when finished, tasks remaining}
        while (!maxHeap.empty() || !cooldown.empty()) {
            time++;
            if (!maxHeap.empty()) {
                int remaining = maxHeap.top();
                maxHeap.pop();
                if (--remaining > 0) {
                    cooldown.emplace(time + n, remaining);
                }
            }

            if (!cooldown.empty() && cooldown.front().first == time) {
                maxHeap.push(cooldown.front().second);
                cooldown.pop();
            }
        }
        return time;
    }
};

int main(void)
{
    Solution sol;
    vector<char> tasks;
    string input;
    int n;

    cout << "Enter tasks (as a single uppercase string, e.g. AABBC): ";
    cin >> input;
    for (char c : input) {
        tasks.push_back(c);
    }

    cout << "Enter cooldown interval (n): ";
    cin >> n;

    int result = sol.leastInterval(tasks, n);
    cout << "Minimum CPU intervals needed: " << result << endl;
}
