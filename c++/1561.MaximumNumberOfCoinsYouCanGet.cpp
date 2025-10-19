/*
 * Leetcode 1561 - Maximum Number of Coins You Can Get (Medium)
 *
 * Problem:
 * There are 3n piles of coins. In each step, you choose 3 piles. Alice picks
 * the largest, you pick the second largest, and Bob picks the smallest.
 * Return the maximum number of coins you can get.
 *
 * Approach:
 * - To maximize your coins, you should always pick the second-largest pile
 * from a triplet, making Alice's pile as large as possible and Bob's as small
 * - Sort the entire `piles` array.
 * - The optimal strategy is to form triplets using the two largest available
 * piles and the single smallest available pile.
 * - This means you will always get the pile at index `n-2`, `n-4`, etc.,
 * while Alice gets `n-1`, `n-3`, ... and Bob gets `0`, `1`, ...
 * - Iterate `n/3` times, adding the second-to-last available element to your
 * total in each step.
 */

#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        sort(piles.begin(), piles.end());
        int picks = n / 3;
        int result = 0;
        for (int i = n - 2; i >= 0 && picks--; i -= 2) {
            result += piles[i];
        }
        return result;
    }
};

int main(void)
{
    Solution solution;

    // Example 1
    vector<int> piles1 = {2, 4, 1, 2, 7, 8};
    cout << "Input: {2, 4, 1, 2, 7, 8}" << endl;
    int coins1 = solution.maxCoins(piles1);
    cout << "Maximum coins you can get: " << coins1 << endl; // Expected: 9

    cout << "--------------------" << endl;

    // Example 2
    vector<int> piles2 = {2, 4, 5};
    cout << "Input: {2, 4, 5}" << endl;
    int coins2 = solution.maxCoins(piles2);
    cout << "Maximum coins you can get: " << coins2 << endl; // Expected: 4

    cout << "--------------------" << endl;

    // Example 3
    vector<int> piles3 = {9, 8, 7, 6, 5, 1, 2, 3, 4};
    cout << "Input: {9, 8, 7, 6, 5, 1, 2, 3, 4}" << endl;
    int coins3 = solution.maxCoins(piles3);
    cout << "Maximum coins you can get: " << coins3 << endl; // Expected: 18
}
