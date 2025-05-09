/**
 * Leetcode 767 - Reorganize String (Medium)
 *
 * Problem:
 * Given a string s, rearrange the characters so that no two adjacent characters are the same.
 * If it is not possible, return an empty string.
 *
 * Examples:
 * Input:  "aab"   → Output: "aba"
 * Input:  "aaab"  → Output: ""
 *
 * Approach:
 * - Count frequency of each character.
 * - Use a max-heap (priority_queue) to always pick the two most frequent characters.
 * - Append them to the result string to ensure no adjacent characters are the same.
 * - If a character still has remaining occurrences, push it back into the heap.
 * - Handle the final character separately (if any).
 *
 * Time Complexity:  O(n log k), where n = length of input, k = unique characters
 * Space Complexity: O(k)
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <iomanip>

using namespace std;

class Solution {
public:
    string reorganizeString(const string &s)
    {
        int size = s.size();
        unordered_map<char, int> freq;
        for (char ch : s) {
            freq[ch]++;
        }

        priority_queue<pair<int, char>> maxHeap;
        for (const auto &[ch, count] : freq) {
            maxHeap.emplace(count, ch);
        }

        string result;
        result.reserve(size);
        while (maxHeap.size() >= 2)
        {
            auto [count1, ch1] = maxHeap.top();
			maxHeap.pop();
            auto [count2, ch2] = maxHeap.top();
			maxHeap.pop();

            result += ch1;
            result += ch2;
            if (--count1 > 0)
				maxHeap.emplace(count1, ch1);
            if (--count2 > 0)
				maxHeap.emplace(count2, ch2);
        }

        if (!maxHeap.empty()) {
            auto [count, ch] = maxHeap.top();
            if (count > 1)
				return "";
            result += ch;
        }
        return result;
    }
};

int main(int ac, char **av)
{
    if (ac < 2) {
        cout << "Usage: " << av[0] << " [string1] [string2] ..." << endl;
        return 1;
    }

	Solution sol;
    int maxLen = 0;
    for (int i = 1; i < ac; ++i) {
        maxLen = max(maxLen, static_cast<int>(strlen(av[i])));
    }

    cout << left << setw(maxLen + 10) << "Input" << "Output" << endl;
    cout << string(maxLen + 20, '-') << endl;

    for (int i = 1; i < ac; ++i) {
        string input = av[i];
        string output = sol.reorganizeString(input);
        cout << left << setw(maxLen + 10) << ("\"" + input + "\"") << "\"" << output << "\"" << endl;
    }
}
