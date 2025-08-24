/*
 * Leetcode 1089 - Duplicate Zeros (Easy)
 *
 * Problem:
 * Given a fixed-length integer array arr, duplicate each occurrence of zero,
 * shifting the remaining elements to the right
 * Elements beyond the length of the original array are not written
 * Modify the input array in-place without returning anything
 *
 * Approach:
 * - Count how many zeros can be duplicated without exceeding array length.
 * - Use two pointers starting from the end of the adjusted array length.
 * - Move elements backward, duplicating zeros when encountered.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int zeroes = 0;
        bool noDuplication = false;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                if (i + zeroes >= n)
					break;
                if (i + zeroes == n - 1) {
                    noDuplication = true;
                    break;
                }
                zeroes++;
            }
        }
        int index = n - 1;
        for (int i = n - zeroes - 1; i >= 0; i--) {
            if (arr[i] == 0) {
                if (noDuplication) noDuplication = false;
                else arr[index--] = 0;
                arr[index--] = 0;
            } else {
                arr[index--] = arr[i];
            }
        }
    }
};


int main() {
    int n;
	cout << "Number of Elements: ";
    cin >> n;
    vector<int> arr(n);
	cout << n << " intgers: ";
    for(int i = 0; i < n; i++)
		cin >> arr[i];
    
    Solution sol;
    sol.duplicateZeros(arr);
    
    for(int val : arr)
		cout << val << " ";
    cout << "\n";
}

