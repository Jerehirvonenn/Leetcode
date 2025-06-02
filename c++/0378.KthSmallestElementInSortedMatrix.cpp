/**
 * Leetcode 378 - Kth Smallest Element in a Sorted Matrix (Medium)
 *
 * Problem:
 * Given an n x n matrix where each row and column is sorted in ascending order,
 * return the k-th smallest element in the matrix.
 *
 * Approach 1: Binary Search (Optimized for Memory)
 * - Use binary search on the value range between the smallest and largest elements.
 * - For each mid-value, count how many elements in the matrix are less than or equal to it.
 * - If count < k → move search to the right half; otherwise, to the left half.
 *
 * Time Complexity: O(n * log(max - min))
 * Space Complexity: O(1)
 *
 * Approach 2: Max Heap (Simpler but more memory-intensive)
 * - Use a max heap to keep track of the k smallest elements seen so far.
 * - Push every element into the heap and maintain heap size ≤ k.
 * - Top of heap will be the k-th smallest.
 *
 * Time Complexity: O(n^2 * log k)
 * Space Complexity: O(k)
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	int countLower(vector<vector<int>> &matrix, int middle, int n)
    {
        int row = n - 1;
        int col = 0;
        int result = 0;
        while (col < n && row >= 0) {
            if (matrix[row][col] > middle) {
                row--;
            }
            else {
                result += row + 1;
                col++;
            }
        }
        return result;
    }

    int kthSmallestBinary(vector<vector<int>>& matrix, int k)
    {
        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n - 1][n - 1];
        while (left < right) {
            int middle = left + (right - left) / 2;
            int lowerThanMiddle = countLower(matrix, middle, n);
            if (lowerThanMiddle < k) {
                left = middle + 1;
            }
            else {
                right = middle;
            }
        }
        return left;
    }

    int kthSmallestHeap(vector<vector<int>>& matrix, int k)
    {
        int n = matrix.size();
        priority_queue<int> maxHeap;
        for(int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                maxHeap.push(matrix[i][j]);
                if (maxHeap.size() > k) {
                    maxHeap.pop();
                } 
            }
        }
        return maxHeap.top();
    }
};

int main(void)
{
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 5, 9},
        {10, 11, 13},
        {12, 13, 15}
    };
    int k = 8;

    // Binary Search solution
    int resultBinary = sol.kthSmallestBinary(matrix, k);
    cout << "Kth smallest using binary search: " << resultBinary << endl;

    // Max Heap solution
    int resultHeap = sol.kthSmallestHeap(matrix, k);
    cout << "Kth smallest using max heap: " << resultHeap << endl;
}
