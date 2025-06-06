/*
 * Leetcode 2434 - Using a Robot to Print the Lexicographically Smallest String (Medium)
 *
 * Problem:
 * You are given a string `s` and a robot that holds an initially empty string `t`.
 * The robot can perform two operations repeatedly:
 *  1. Remove the first character from `s` and append it to `t`
 *  2. Remove the last character from `t` and write it to the paper (output)
 * 
 * Return the lexicographically smallest string that can be written to the paper
 * after performing the operations any number of times until both `s` and `t` are empty.
 *
 * Approach:
 * - Use a frequency counter to track remaining characters in `s`
 * - Maintain a stack `t` to simulate the robot's string
 * - At each step:
 *    - Push next character from `s` to `t`
 *    - Pop from `t` to the result while the top of `t` is less than or equal
 *      to the current smallest character still left in `s`
 * - After `s` is empty, pop all remaining characters in `t`
 *
 * Time Complexity: O(N * 26) → effectively linear, worst-case bounded by 26 * N
 * Space Complexity: O(N) for the stack and result string
 */

#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
private:
    int updateLooking(const vector<int> &freq)
    {
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0)
                return i;
        }
        return 25; //dummy return
    }
public:
    string robotWithString(string s)
    {
        vector<int> freq(26, 0);
        for (const char c : s) {
            freq[c - 'a']++;
        }

        int smallest = 0;
        stack<char> t;
        string result;
        result.reserve(s.size());
        for (const char c : s)
        {
            t.push(c);
            freq[c - 'a']--;
            smallest = updateLooking(freq);
            while (!t.empty() && t.top() <= smallest + 'a') {
                result.push_back(t.top());
                t.pop();
            }
        }
        while (!t.empty()) {
            result.push_back(t.top());
            t.pop();
        }
        return result;
    }
};

int main(void)
{
    string input;
    cout << "Enter string s: ";
    cin >> input;

    Solution sol;
    string result = sol.robotWithString(input);
    cout << "Lexicographically smallest result: " << result << endl;
}
