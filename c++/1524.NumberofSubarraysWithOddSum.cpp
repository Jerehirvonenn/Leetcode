/* Leetcode 1524 - Number of Sub-arrays With Odd Sum (Medium)
 *
 * Problem:
 * Given an array of integers arr, return the number of subarrays with an odd sum.
 * Since the answer can be very large, return it modulo 10^9 + 7.
 *
 * Approach:
 * - Use prefix sum mod 2 to track even/odd sums.
 * - Count subarrays ending at current index with odd sum using counts of even/odd prefix sums.
 * - Update counts accordingly while iterating.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    const int MOD = 1e9 + 7;
public:
    int numOfSubarrays(vector<int>& arr) {
        long sumMod = 0;
        long result = 0;
        int odd = 0;
        int even = 1;
        for (const int num : arr) {
            sumMod = (sumMod + num) % 2;
            if (sumMod == 0) {
                result = (result + odd) % MOD;
                even++;
            }
            else {
                result = (result + even) % MOD;
                odd++;
            }
        }
        return (int)result;
    }
};

int main(void)
{
    Solution solution;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the array elements:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int result = solution.numOfSubarrays(arr);
    cout << "Number of subarrays with odd sum: " << result << endl;
}
