/*
 * Leetcode 1013 - Partition Array Into Three Parts With Equal Sum (Easy)
 *
 * Problem:
 * Given an array of integers arr, return true if we can partition the array into
 * three non-empty parts with equal sums.
 *
 * Formally, we can partition the array if we can find indexes i + 1 < j with:
 *   (arr[0] + ... + arr[i] == arr[i+1] + ... + arr[j-1] == arr[j] + ... + arr[n-1])
 *
 * Approach:
 * - First, calculate the total sum of the array.
 * - If the total is not divisible by 3, return false.
 * - Traverse the array, accumulating the sum.
 * - When a segment with sum equal to total/3 is found, reset the current sum and increment a counter.
 * - If we can find 3 such segments, return true. checking >= for 0 arrays like {0, 0, 0, 0}
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr)
    {
        int total = accumulate(arr.begin(), arr.end(), 0);
        if (total % 3 != 0) {
            return false;
        }

        int target = total / 3;
        int result = 0;
        int current = 0;

        for (const int num : arr) {
            current += num;
            if (current == target) {
                result++;
                current = 0;
            }
        }
        return (result >= 3);
    }
};

int main(void)
{
    Solution sol;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int &x : arr) {
        cin >> x;
    }

    bool res = sol.canThreePartsEqualSum(arr);
    cout << (res ? "true" : "false") << endl;
}
