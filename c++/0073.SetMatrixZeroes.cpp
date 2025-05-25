/*
 * Leetcode 73 - Set Matrix Zeroes (Medium)
 *
 * Problem:
 * Given an m x n integer matrix, if an element is 0, set its entire row and column to 0's.
 * You must do it in place.
 *
 * Approach:
 * - Use the first row and first column as markers.
 * - Mark rows and columns that need to be zeroed by setting matrix[0][j] and matrix[i][0] to 0.
 * - Then traverse the matrix again and set cells to 0 based on these markers.
 * - Handle the first row and first column separately, using flags.
 *
 * Time Complexity: O(m * n)
 * Space Complexity: O(1) (in-place)
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        bool firstRow = false;
        bool firstCol = false;

		//check first row
        for (int i = 0; i < cols; i++) {
            if (matrix[0][i] == 0) {
                firstRow = true;
                break;
            }
        }
		//check first column
        for (int i = 0; i < rows; i++) {
            if (matrix[i][0] == 0) {
                firstCol = true;
                break;
            }
        }

		// go through rest and use 1st col and row as marker for zeroing
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

		// zero the matrix according to the markers
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

		//zero 1st row, col if needed
        if (firstRow) {
            for (int j = 0; j < cols; j++) {
                matrix[0][j] = 0;
            }
        }
        if (firstCol) {
            for (int i = 0; i < rows; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};

void printMatrix(const vector<vector<int>>& matrix)
{
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main(void)
{
    int rows, cols;
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));
    cout << "Enter matrix values row by row:" << endl;
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            cin >> matrix[i][j];

    cout << "\nOriginal matrix:\n";
    printMatrix(matrix);

    Solution sol;
    sol.setZeroes(matrix);

    cout << "\nModified matrix:\n";
    printMatrix(matrix);
}
