/*
Source: 2379. Minimum Recolors to Get K Consecutive Black Blocks
Difficulty: Easy

Problem:
You are given a 0-indexed string `blocks` of length `n`, where blocks[i] is either 'W' or 'B',
representing white and black blocks, respectively. You are also given an integer `k`,
which is the desired number of consecutive black blocks.

In one operation, you can recolor a white block into a black one.

Goal:
Return the minimum number of operations needed so that there is at least one occurrence
of `k` consecutive black blocks.

Approach:
- Use a sliding window of size `k`.
- Count the number of white blocks ('W') in the first window.
- Slide the window across the string:
    - Add the new block on the right to the white count if it's white.
    - Subtract the block exiting the left if it's white.
    - Track the minimum number of white blocks in any window of size `k`.
- This represents the minimum number of recolors needed.
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k)
    {
        int n = blocks.size();
        int white = 0;

        for (int i = 0; i < k && i < n; i++)
            if (blocks[i] == 'W')
                white++;

        int result = white;
        for (int i = k; i < n; i++) {
            if (blocks[i] == 'W') {
                white++;
            }
            if (blocks[i - k] == 'W') {
                white--;
            }
            result = min(result, white);
        }
        return result;
    }
};

int main(void)
{
    string blocks;
    int k;

    cout << "Enter the blocks string (only 'B' and 'W'): ";
    cin >> blocks;

    cout << "Enter the value of k: ";
    cin >> k;

    Solution sol;
    int result = sol.minimumRecolors(blocks, k);
    cout << "Minimum recolors needed: " << result << endl;
}
