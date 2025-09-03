/*
 * Leetcode 2024 - Maximize the Confusion of an Exam (Medium)
 *
 * Problem:
 * Given a string answerKey of 'T' and 'F', and an integer k,
 * find the maximum number of consecutive identical answers (all 'T' or all 'F')
 * after changing at most k answers.
 *
 * Approach:
 * - Use a sliding window to keep track of counts of 'T' and 'F'.
 * - Expand right pointer and adjust left pointer if min(count_T, count_F) > k.
 * - Maintain the longest valid window length.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int longest = 0;
        int T = 0;
        int F = 0;
        int left = 0;
        for (int right = 0; right < (int)answerKey.size(); right++) {
            if (answerKey[right] == 'T')
                T++;
            else
                F++;
            while (min(F, T) > k) {
                if (answerKey[left] == 'T')
                    T--;
                else
                    F--;
                left++;
            }
            longest = max(longest, right - left + 1);
        }
        return longest;
    }
};

int main(void)
{
    Solution solution;
    string answerKey;
    int k;
    cout << "Enter the answer key (string of T and F): ";
    cin >> answerKey;
    cout << "Enter the maximum number of changes allowed (k): ";
    cin >> k;

    int result = solution.maxConsecutiveAnswers(answerKey, k);
    cout << "Maximum consecutive identical answers after at most "
		 << k << " changes: " << result << endl;
}
