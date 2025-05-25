/* Leetcode 2131 - Longest Palindrome by Concatenating Two Letter Words (Medium)
 *
 * Problem:
 * You are given an array of strings words. Each element of words consists of two lowercase English letters.
 * Create the longest possible palindrome by selecting some elements from words and concatenating them in any order.
 * Each element can be selected at most once.
 * Return the length of the longest palindrome that you can create.
 * If it is impossible to create any palindrome, return 0.
 * A palindrome is a string that reads the same forward and backward.
 *
 * Approach:
 * - Use an unordered_map to count the frequency of each word.
 * - For each word:
 *   - If it is a palindrome (e.g., "aa"), pair as many as possible and consider at most one odd occurrence for the center.
 *   - If it has a mirror (e.g., "ab" and "ba"), pair up to the minimum count of the two.
 *   - Avoid double-counting by zeroing both frequencies after pairing.
 *
 * Time Complexity: O(n), where n is the number of words.
 * Space Complexity: O(n), for the frequency map.
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestPalindrome(vector<string>& words)
	{
        unordered_map<string, int> freq;
        for (const string &cur : words) {
            freq[cur]++;
        }

        int result = 0;
        int addMiddle = 0;
        for (auto &[word, count] : freq) {
            string match = string() + word[1] + word[0];

            if (word == match) {
                result += (count / 2) * 4;
                if (count % 2 == 1) {
                    addMiddle = 2;
                }
            } else if (freq.count(match)) {
                int pairCount = min(freq[word], freq[match]);
                result += pairCount * 4;
                freq[match] = 0;
                freq[word] = 0;
            }
        }
        return result + addMiddle;
    }
};

int main(int ac, char **av)
{
    if (ac < 2) {
        cout << "Usage: ./a.out ab ba aa ..." << endl;
        return 1;
	}

	vector<string> words;
    for (int i = 1; i < ac; i++) {
		string s = av[i];
        if (s.length() == 2) {
            words.push_back(s);
        } else {
            cerr << "Skipping invalid input (not 2 chars): " << s << endl;
        }
    }

    Solution sol;
    int result = sol.longestPalindrome(words);
    cout << "Longest palindrome length: " << result << endl;
}
