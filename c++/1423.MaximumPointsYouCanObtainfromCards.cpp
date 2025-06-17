/*
1423. Maximum Points You Can Obtain from Cards
--------------------------------------------------
You are given an integer array cardPoints and an integer k.

In one step, you can take one card from the beginning or from the end of the row.
You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Return the maximum score you can obtain.

Approach:
- Precompute the total points from the first k cards (left) and last k cards (right).
- At each step, compare remainingLeft and remainingRight.
- Greedily choose the better end and update totals accordingly.
*/

#include <iostream>
#include <vector>
#include <numeric>  // for accumulate
using namespace std;


class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        if (k >= n) {
            return accumulate(cardPoints.begin(), cardPoints.end(), 0);
        }

        int remainingLeft = 0;
        for (int i = k - 1; i >= 0; i--) {
            remainingLeft += cardPoints[i];
        }    
        int remainingRight = 0;
        for (int i = n - k; i < n; i++) {
            remainingRight += cardPoints[i];
        }

        int left = 0;
        int right = n - 1;
        int result = 0;
        for (int i = 0; i < k; i++) {
            if (remainingLeft > remainingRight) {
                result += cardPoints[left];
                remainingLeft -= cardPoints[left];
                remainingRight -= cardPoints[right - k + i + 1];
                left++;
            } else {
                result += cardPoints[right];
                remainingRight -= cardPoints[right];
                remainingLeft -= cardPoints[left + k - i - 1];
                right--;
            }
        }
        return result;
    }
};

int main(void)
{
    int n, k;
    cout << "Enter number of cards and k: ";
    cin >> n >> k;

    vector<int> cardPoints(n);
    cout << "Enter card points: ";
    for (int i = 0; i < n; i++) {
        cin >> cardPoints[i];
    }

    Solution sol;
    int result = sol.maxScore(cardPoints, k);
    cout << "Maximum score: " << result << endl;
}
