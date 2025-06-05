/*
 * Leetcode 1061 - Lexicographically Smallest Equivalent String (Medium)
 *
 * Problem:
 * You're given two strings s1 and s2 of equal length. Characters s1[i] and s2[i] are equivalent.
 * This equivalence relation is transitive, symmetric, and reflexive.
 * Given a string baseStr, return a new string where each character is replaced
 * with the lexicographically smallest equivalent character from its equivalence class.
 *
 * Example:
 * s1 = "abc", s2 = "cde" → a==c, b==d, c==e (so a==c==e, b==d)
 * baseStr = "eed" → result = "abb"
 *
 * Approach:
 * - Use a `groups` array to assign group IDs to characters a-z.
 * - Merge equivalence groups using
 * - For each character in baseStr, find the lex smallest character in its group
 *
 * Time Complexity: O(26 * N), where N is length of s1/s2
 * Space Complexity: O(1), only 26-char storage
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    int index = 0;

    void groupChars(int a, int b, vector<int> &groups) {
        int groupA = groups[a];
        int groupB = groups[b];
        if (groupA == -1 && groupB == -1) {
            groups[a] = index;
            groups[b] = index;
            index++;
        }
        else if (groupA != -1 && groupB != -1) {
            int minGroup = min(groupA, groupB);
            int maxGroup = max(groupA, groupB);
            for (int i = 0; i < 26; i++)
                if (groups[i] == maxGroup)
                    groups[i] = minGroup;
        }
        else {
            int group = (groupA == -1) ? groupB : groupA;
            groups[a] = group;
            groups[b] = group;
        }
    }

    char lowestFromGroup(char a, vector<int> &groups) {
        int group = groups[a - 'a'];
        if (group == -1) return a;
        for (int i = 0; i < 26; i++) {
            if (groups[i] == group)
                return i + 'a';
        }
        return a;
    }

public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> groups(26, -1);
        for (int i = 0; i < s1.size(); i++) {
            groupChars(s1[i] - 'a', s2[i] - 'a', groups);
        }
        for (int i = 0; i < baseStr.size(); i++) {
            baseStr[i] = lowestFromGroup(baseStr[i], groups);
        }
        return baseStr;
    }
};

int main(void)
{
    string s1, s2, baseStr;
    cout << "Enter string s1: ";
    cin >> s1;
    cout << "Enter string s2: ";
    cin >> s2;
    cout << "Enter baseStr: ";
    cin >> baseStr;

    Solution sol;
    string result = sol.smallestEquivalentString(s1, s2, baseStr);

    cout << "Lexicographically smallest equivalent string: " << result << endl;
}
