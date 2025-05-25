/*
 * Leetcode 2942 - Find Words Containing Character (Easy)
 *
 * Problem:
 * You are given a 0-indexed array of strings `words` and a character `x`.
 * Return an array of indices representing the words that contain the character `x`.
 * Note that the returned array may be in any order.
 *
 * Approach:
 * - Iterate through the `words` array with index.
 * - For each word, check if it contains character `x` using `find(x)`.
 * - If it does, add the index to the result vector.
 *
 * Time Complexity: O(n * m), where n = number of words and m = average length of each word.
 * Space Complexity: O(k), where k = number of matching indices.
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> result;
        for (int i = 0; i < words.size(); i++) {
            if (words[i].find(x) != string::npos) {
                result.push_back(i);
            }
        }
        return result;
    }
};

int main(int ac, char **av)
{
    if (ac < 3) {
        cout << "Usage: ./a.out x word1 word2 word3 ..." << endl;
        return 1;
    }

    char x = av[1][0];
    vector<string> words;
    for (int i = 2; i < ac; ++i) {
        words.push_back(av[i]);
    }

    Solution sol;
    vector<int> result = sol.findWordsContaining(words, x);

    cout << "Indices of words containing '" << x << "': ";
    for (int idx : result) {
        cout << idx << " ";
    }
    cout << endl;
}
