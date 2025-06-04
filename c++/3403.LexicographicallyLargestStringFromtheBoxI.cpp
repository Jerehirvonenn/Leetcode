/*
 * Leetcode 3403 - Find the Lexicographically Largest String From the Box I (Medium)
 *
 * Problem:
 * Given a string `word` and an integer `numFriends`, split the string into exactly
 * `numFriends` non-empty parts in all possible valid ways. In each valid split,
 * all the resulting parts are placed into a box. After all unique splits are completed,
 * return the lexicographically largest string from the box.
 *
 * Approach:
 * - Slide a window of length (size - numFriends + 1) across the word.
 * - At each position, compare the substring to the current maximum.
 * - Return the lexicographically largest such substring.
 *
 * Time Complexity: O(N * L), where N is the length of the word and L is the substring length
 * Space Complexity: O(1) extra (excluding result)
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string answerString(string word, int numFriends) 
    {
        if (numFriends == 1) {
            return word;
        }
        int size = word.size();
        string result = "";
        for (int i = 0; i <= size - (size - numFriends + 1); i++) {
            string compare = word.substr(i, size - numFriends + 1);
            if (compare > result) {
                result = compare;
            }
        }   
        return result;
    }
};

int main(void)
{
    string word;
    int numFriends;

    cout << "Enter the string: ";
    cin >> word;

    cout << "Enter the number of friends: ";
    cin >> numFriends;

    Solution sol;
    string largest = sol.answerString(word, numFriends);

    cout << "Lexicographically largest string from the box: " << largest << endl;
}
